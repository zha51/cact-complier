#include "semanticAnalysis.h"
#include <vector>
#include <string>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include <stack>
using namespace std;

static int label_times = 0;        //记录if次数

    
void SemanticAnalysis::enterConstDecl(CACTParser::ConstDeclContext * ctx)
{}
void SemanticAnalysis::exitConstDecl(CACTParser::ConstDeclContext * ctx)
{
    std::cout << "const variable define:  " << std::endl;
    
    for (const auto &const_def : ctx->constDef())
    {
        std::cout << "\tname: " << const_def->Ident()->getText().c_str()
                  << " type: " << ctx->bType()->getText().c_str() << std::endl;
    }

    for (int i = 0; i < ctx->constDef().size(); i++)   //将const加入到const的vector中
    {
        pconst = &ConstVector;
        pconst->push_back(ctx->constDef()[i]->Ident()->getText());
        printf("const vector size is %d\n", (*pconst).size());
    }

    Variable var;    //将const常量也存入variable vector中
    for (int i = 0; i < ctx->constDef().size(); i++)
    {
        var.name = ctx->constDef()[i]->Ident()->getText();
        var.size = 0;
        var.type = ctx->bType()->basicType;   //6为const常量类型
        var.is_array = false;
        curVarVec->push_back(var);     //将常量也放在variable vector中，解决const常量重新定义问题
        printf("achive a const\n");
    }


}

void SemanticAnalysis::exitConstExpNumber(CACTParser::ConstExpNumberContext * ctx)
{
    ctx->is_number = true;
}
 
void SemanticAnalysis::exitFirstConstInitVal(CACTParser::FirstConstInitValContext * ctx)
{ 
    ctx->is_number = ctx->constExp()->is_number;
}

void SemanticAnalysis::exitConstDef(CACTParser::ConstDefContext * ctx)
{ 
    string sharp_1 = "#";
    string constinitval_1 = ctx->constInitVal()->getText();
    string general_const;
    string temp_Tconst;
    string temp_Vconst;
    string op = ":= ";
    string general_1;
    string general_2;

    if(ctx->constInitVal()->is_number == true)
    {   
        general_const = sharp_1+constinitval_1;
    }
    else
    {
        general_const = constinitval_1;
    }
    temp_Tconst = t_global();
    general_1 = temp_Tconst + op + general_const;
    cout<<general_1<<endl;
    POutput->push_back(general_1);            //t=#number

    temp_Vconst = v_global();                //v=t
    general_2 = temp_Vconst + op + temp_Tconst;
    POutput->push_back(general_2);

    Quaternion Quater;
    Quater.result = temp_Vconst;
    Quater.op = "";
    Quater.arg1 = general_const;
    Quater.arg2 = "";
    Quater.name = ctx->Ident()->getText();
    PQuaternion->push_back(Quater);

}

void SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext * ctx)
{
    if (ctx->bType()->getText() == "int") //如果是int类型则declType值为1
    {
        ctx->declType = 1;
    }
    if (ctx->bType()->getText() == "float")
    {
        ctx->declType = 2;
    }
    if (ctx->bType()->getText() == "double")
    {
        ctx->declType = 3;
    }
    if (ctx->bType()->getText() == "bool")
    {
        ctx->declType = 4;
    }
}
void SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext * ctx)
{
    for (const auto &var_def : ctx->varDef())
    {
        if (auto ArrayVarDef = dynamic_cast<CACTParser::ArrayVarDefContext *>(var_def)) //将VarDef类型指针转换为ArrayVarDef
        {
            printf("\tname: %s type: %s\n", ArrayVarDef->Ident()->getText().c_str(), ctx->bType()->getText().c_str());
        }

        if (auto ScalarVarDef = dynamic_cast<CACTParser::ScalarVarDefContext *>(var_def)) //将VarDef类型指针转换为ScalarVarDef
        {
            printf("\tname: %s type: %s\n", ScalarVarDef->Ident()->getText().c_str(), ctx->bType()->getText().c_str());

            string temp_var;
            string op = ":= ";
            string init_number = "#0";      //未初始化的默认为0
            string general1;

            if(ScalarVarDef!=nullptr)
            {
                temp_var = v_global();
                general1 = temp_var + op + init_number;
                POutput->push_back(general1);

                Quaternion Quater;                   //赋初值为0，存入到四元式中
                Quater.result = temp_var;
                Quater.arg1 = init_number;
                Quater.op = "";
                Quater.arg2 = "";
                Quater.name = ScalarVarDef->Ident()->getText();
                PQuaternion->push_back(Quater);

            }
        }
    }

}

void  SemanticAnalysis::exitDecl(CACTParser::DeclContext * ctx)
{
    printf("exitDecl!\n");
}

void SemanticAnalysis::enterConstDef(CACTParser::ConstDefContext * ctx)
{
    if (ctx->LeftBracket() != nullptr)                                                //如果含有左中括号
    {
        auto secondInit = dynamic_cast<CACTParser::SecondConstInitValContext *>(ctx->constInitVal());
        if (secondInit == nullptr)
        {
            // 没有花括号（数组赋值不足问题）  3
            printf("SemanticAnalysis::enterConstDef(): const def not fit!\n");
            exit(-1);
        }
    }
}

void SemanticAnalysis::enterArrayVarDef(CACTParser::ArrayVarDefContext * ctx)
{
    if (!ctx->LeftBracket()) //如果不含左中括号
    {
        auto secondInit = dynamic_cast<CACTParser::SecondConstInitValContext *>(ctx->constInitVal());
        if (secondInit != nullptr) //secondInit指针为空
        {
            if (secondInit->LeftBrace()) //含有花括号，解决变量赋多个值问题
            {
                printf("SemanticAnalysis::enterArrayVarDef():const def not fit!\n");
                exit(-1);
            }
        }

        else //secondInit指针不为空时执行
        {
            auto varDecl = dynamic_cast<CACTParser::VarDeclContext *>(ctx->parent); //解决int类型匹配的为浮点数问题
            if (varDecl->declType == 1)                                             //type is int
            {
                auto firstInit = dynamic_cast<CACTParser::FirstConstInitValContext *>(ctx->constInitVal());
                auto constExpnum = dynamic_cast<CACTParser::ConstExpNumberContext *>(firstInit->constExp());
                if (!constExpnum->number()->IntConst()) //如果指针不指向intconst，则为错误
                {
                    printf("SemanticAnalysis::enterArrayVarDef():const def not fit!\n");
                    exit(-1);
                }
            }
        }
    }
}


void SemanticAnalysis::exitSecondMulExp(CACTParser::SecondMulExpContext * ctx)
{
    if (ctx->mulExp()->type != ctx->unaryExp()->type) //secondMulExp中左边类型返回值不等于右边类型返回值（除号上下类型不匹配问题）
    {
        printf("SemanticAnalysis::exitSecondMulExp():const def not fit!\n");
        exit(-1);
    }
    ctx->type = ctx->mulExp()->type; //令函数类型与unaryExp同类型,向上层传递函数类型
}

void SemanticAnalysis::exitFirstMulExp(CACTParser::FirstMulExpContext * ctx) 
{  
    ctx->type=ctx->unaryExp()->type;
    ctx->size = ctx->unaryExp()->size;
    ctx->is_array = ctx->unaryExp()->is_array;
    ctx->returnNumber = ctx->unaryExp()->returnNumber;
    ctx->boolType = ctx->unaryExp()->boolType;
    ctx->is_number = ctx->unaryExp()->is_number;
    //printf("exitFirstMulExp() type is %d\n",ctx->type);
}

void SemanticAnalysis::exitFirstUnaryExp(CACTParser::FirstUnaryExpContext * ctx)
{
    ctx->type = ctx->primaryExp()->type;
    ctx->size = ctx->primaryExp()->size;
    ctx->is_array = ctx->primaryExp()->is_array;
    ctx->is_number =ctx->primaryExp()->is_number;
    //printf("firstunaryexp type is %d\n",ctx->type);
}

void SemanticAnalysis::exitThirdUnaryExp(CACTParser::ThirdUnaryExpContext * ctx)   //解决unaryop不合法问题  30
{
    if (ctx->unaryOp()->getText() == "!")
    {
        ctx->type = 4; //bool类型则令type为4
        ctx->size = 0;
        ctx->is_array = false;
    }
    if ((ctx->unaryOp()->getText() == "+") || (ctx->unaryOp()->getText() == "-"))
    {
        ctx->type = 1;
        ctx->size = 0;
        ctx->is_array = false;
    }
   // printf("type is %d\n", ctx->type);
}

void SemanticAnalysis::exitThirdPrimaryExp(CACTParser::ThirdPrimaryExpContext *ctx)
{
    Variable var; //将number传入vector中
    ctx->type = ctx->number()->type;
    var.name = "";
    var.size = 0;
    var.is_array = false;
    var.type = ctx->number()->type;
    curVarVec->push_back(var);

    ctx->size = 0;
    ctx->type = ctx->number()->type;
    ctx->is_array = false;
    ctx->is_number = true;
}

void SemanticAnalysis::exitNumber(CACTParser::NumberContext * ctx)
{  
    if(ctx->IntConst()){
        ctx->type = 1;
    }
    if(ctx->FloatConst()){
        ctx->type = 2;
    }
    if (ctx->DoubleConst())
    {
        ctx->type=3;
    }
}


 void SemanticAnalysis::exitArrayVarDef(CACTParser::ArrayVarDefContext * ctx)    // 1.判断全局变量是否有重名。2.将定义的变量放入variable vactor中
 {
     //printf("ArrayVarDef1\n");
     Variable var; //结构体名字var,全局的变量vector
     int i;
     for (i = 0; i < (*curVarVec).size(); i++)
     {
         if ((*curVarVec)[i].name == ctx->Ident()->getText()) // 找到了
         {
             printf("SemanticAnalysis::enterArrayVarDef(): false same name!\n"); //全局中存在重复定义变量    10
             exit(-1);
         }
     }

     /* for(int i=0;i<TempFunVector[0].FParamsVector.size();i++)
        {
            if(TempFunVector[0].FParamsVector[i] == ctx->Ident()->getText())
            {
                printf("ArrayVarDef:variable name is samed with FormalParameter name!\n");
                exit(-1);
            }
        }*/

     /*curFunVec = &FuntableVector;   //通过变量地址对指针初始化
        for (int i = 0; i < (*curFunVec).size(); i++) //解决形参和变量名字相同的问题
        {
            
            curForVec = &((*curFunVec)[i].FormalParameterVector);  //指针初始化，指向FormalParameterVector
            for (int j = 0; j < (*curForVec).size(); j++)
            {
               if ((*curForVec)[j].name == ctx->Ident()->getText())
                {
                    printf("ArrayVarDef:variable name is samed with FormalParameter name!\n");
                    exit(-1);
                }
            }           
        }*/
     var.name = ctx->Ident()->getText();
     if (ctx->IntConst() == nullptr)
     {
         var.size = 0;
     }
     else
     {
         var.size = atoi(ctx->IntConst()->getText().c_str()); //string 转为int类型
     }
     auto varDecl = dynamic_cast<CACTParser::VarDeclContext *>(ctx->parent);
     var.type = varDecl->declType;
     if (ctx->LeftBracket())
     {
         var.is_array = true;
     }
     else
     {
         var.is_array = false;
     }
     curVarVec->push_back(var);

     Quaternion Quater;                        // 将赋值语句存入三地址码中
     Quater.op = "";
     // printf("%s\n",ctx->constInitVal()->getText().c_str());
     auto firstInit = dynamic_cast<CACTParser::FirstConstInitValContext *>(ctx->constInitVal());
     auto constExpnum = dynamic_cast<CACTParser::ConstExpNumberContext *>(firstInit->constExp());
     if(constExpnum!=nullptr)
    {
        string op ="#";
        string number = ctx->constInitVal()->getText();
        string arg1 = op+number;
        Quater.arg1 = arg1;
    }
    else
    {
        Quater.arg1 = ctx->constInitVal()->getText();
    }
     Quater.arg2 = "";
     Quater.name= ctx->Ident()->getText();
     Quater.result =  v_global();
     string sign =":= " ;
     string arrver = Quater.result + sign + Quater.arg1 + Quater.op + Quater.arg2;
     cout << arrver <<endl;       
     POutput->push_back(arrver);         //存入输出vector中

     PQuaternion->push_back(Quater);
 }


void SemanticAnalysis::exitScalarVarDef(CACTParser::ScalarVarDefContext * ctx)    //将定义的变量存入variable vactor中
{
    Variable var; //结构体名字var
    var.name = ctx->Ident()->getText();
    if (ctx->IntConst() == nullptr)
    {
        var.size = 0;
    }
    else
    {
        var.size = atoi(ctx->IntConst()->getText().c_str()); //string类型转换为int类型
    }

    auto varDecl = dynamic_cast<CACTParser::VarDeclContext *>(ctx->parent);
    var.type = varDecl->declType;
    if (ctx->LeftBracket())
    {
        var.is_array = true;
    }
    else
    {
        var.is_array = false;
    }

    // VariableVector.push_back(var);  与下一个语句意义相同
    curVarVec->push_back(var);
}


void SemanticAnalysis::exitLVal(CACTParser::LValContext * ctx)     //查找表达式中左值是否存在，存在则赋值，不存在则栈中寻找，都不在报错。
{
    int i;
    printf("Now is finding: %s\n", ctx->Ident()->getText().c_str());
    bool found_flag = false;
    if (curVarVec == nullptr)
    {
        printf("curVarVec==nullptr  \n");
    }

    for (i = 0; i < (*curVarVec).size(); i++)
    {
        if ((*curVarVec)[i].name == ctx->Ident()->getText()) // 找到了
        {
            //printf("%d\n",(*curVarVec).size());
            found_flag = true;
            if (ctx->LeftBracket() != nullptr)
            {
                if (atoi(ctx->exp()->getText().c_str()) < (*curVarVec)[i].size) //数组括号大小内数字小于初始定义数组大小 36
                {
                    ctx->size = 0;
                    ctx->type = (*curVarVec)[i].type; //为数组初始类型的数
                    ctx->is_array = false;
                    break;
                }
            }
            else
            {
                ctx->size = (*curVarVec)[i].size; //前面对该元素进行了定义，这里进行赋值
                ctx->type = (*curVarVec)[i].type;
                ctx->is_array = (*curVarVec)[i].is_array;
                break;
            }
        }
    }

    if (i == (*curVarVec).size()) //如果找不到，则去栈中查找，从栈顶到栈底，如果都找不到则报错
    {
        // printf("%d\n",(*curVarVec).size());
        std::vector<Variable> *newVarVec;
        stack<std::vector<Variable> *> newstack(symbolTableStack); //复制一个栈

        for (; !newstack.empty();) //遍历该栈
        {
            newVarVec = newstack.top(); //指针指向栈顶

            //printf("size is %d\n",(*newVarVec).size());
            for (int i = 0; i < (*newVarVec).size(); i++)
            {
                if ((*newVarVec)[i].name == ctx->Ident()->getText()) //找到了，进行赋值
                {
                    found_flag = true;
                    if (ctx->LeftBracket() != nullptr)
                    {
                        if (atoi(ctx->exp()->getText().c_str()) < (*newVarVec)[i].size) //数组括号大小内数字小于初始定义数组大小 36
                        {
                            ctx->size = 0;
                            ctx->type = (*newVarVec)[i].type; //为数组初始类型的数
                            ctx->is_array = false;
                            break;
                        }
                    }
                    else
                    {
                        ctx->size = (*newVarVec)[i].size; //前面对该元素进行了定义，这里进行赋值
                        ctx->type = (*newVarVec)[i].type;
                        ctx->is_array = (*newVarVec)[i].is_array;
                        break;
                    }
                }
            }
            newstack.pop(); //弹出栈顶的vector
        }
        if (found_flag == false) //栈中的vactor都不含该元素则报错
        {
            printf("exitLVal:variable is not define!\n");
            exit(-1);
        }
    }

    if (ctx->LeftBracket() != nullptr) //42
    {
        if (ctx->exp()->type == 2)
        {
            printf("array can't used float number at bracket!\n");
            exit(-1);
        }
    }
    // printf("exitlval type is %d\n",ctx->type);

    
    
}

void SemanticAnalysis::exitFirstPrimaryExp(CACTParser::FirstPrimaryExpContext * ctx) 
{ 
    ctx->size = ctx->exp()->size;
    ctx->type = ctx->exp()->type;
    ctx->is_array = ctx->exp()->is_array;
}

void SemanticAnalysis::exitSecondPrimaryExp(CACTParser::SecondPrimaryExpContext * ctx) 
{
     ctx->size = ctx->lVal()->size;
     ctx->type = ctx->lVal()->type;
     ctx->is_array = ctx->lVal()->is_array;
     //cout << "exitSecondPrimaryExp: " << ctx->is_array << endl;
}

void SemanticAnalysis::exitFirstAddExp(CACTParser::FirstAddExpContext *ctx)
{ 
    ctx->type = ctx->mulExp()->type;
    ctx->size = ctx->mulExp()->size;
    ctx->is_array = ctx->mulExp()->is_array;
    ctx->returnNumber = ctx->mulExp()->returnNumber;
    ctx->boolType = ctx->mulExp()->boolType;
    ctx->is_number = ctx->mulExp()->is_number;
    //printf("first addexp is %d\n",ctx->type);
}

void SemanticAnalysis::exitFirstExp(CACTParser::FirstExpContext * ctx)
{   
    
    ctx->type = ctx->addExp()->type;
    ctx->size = ctx->addExp()->size;
    ctx->is_array = ctx->addExp()->is_array;
    ctx->returnNumber = ctx->addExp()->returnNumber;
    //printf("exp is %d\n",ctx->type);
    
} 

void SemanticAnalysis::exitSecondExp(CACTParser::SecondExpContext * ctx)
{ 
    ctx->type = 4;
    ctx->size = 0;
    ctx->is_array = false;
}


void SemanticAnalysis::exitSecondAddExp(CACTParser::SecondAddExpContext * ctx)   //加减号两边数据类型不匹配，或数组不匹配问题
{
    // cout << ctx->addExp()->is_array << endl;
    // cout << ctx->mulExp()->is_array << endl;
    //printf("enter exitSecondAddExp!\n");
    if ((ctx->addExp()->is_array == true) && (ctx->mulExp()->is_array == true)) //secondAddExp中addExp和mulExp同为数组
    {
        if (ctx->addExp()->size != ctx->mulExp()->size) //数组的大小不一样
        {
            printf("SemanticAnalysis::enterSecondAddExp():array is not fit!\n");
            exit(-1);
        }
        if (ctx->addExp()->type != ctx->mulExp()->type) //加号两边数据类型不一样
        {
            printf("exitSecondAddExp:array type is not fit!\n");
            exit(-1);
        }
    }

    if (ctx->addExp()->is_array != ctx->mulExp()->is_array) //加号两边一个为数组一个不为数组
    {
        printf("exitSecondAddExp():scalar quantity is not fit array!\n");
        exit(-1);
    }
    
    if (ctx->addExp()->type != ctx->mulExp()->type) //解决算数类型不匹配的问题
    {   
        printf("add is %d\n",ctx->addExp()->type);
        printf("mul is %d\n",ctx->mulExp()->type);
        printf("exitSecondAddExp:type is not fit!\n");
        exit(-1);
    }

    ctx->type = ctx->mulExp()->type; //参数继续向上传递
    ctx->size = ctx->mulExp()->size;
    ctx->is_array = ctx->mulExp()->is_array;
    //printf("addexp is %d\n",ctx->type);
    //printf("exit exitSecondAddExp!\n");
}

void SemanticAnalysis::exitFirstStmt(CACTParser::FirstStmtContext * ctx)   //主要处理等号两边数组不匹配问题
{   
    printf("enter exitFirstStmt!\n");
    POutput=&OutputVector;
    Quaternion Quater;
    if ((ctx->lVal()->is_array == true) && (ctx->exp()->is_array == true)) //firststmt两边同为数组
    {
        if (ctx->lVal()->size != ctx->exp()->size) //等号两边数组大小不匹配
        {
            printf("enterFirstStmt(): array size is not fit!\n");
            exit(-1);
        }
    }

    if (ctx->lVal()->type != ctx->exp()->type) //firststmt等号左右两边类型不匹配
    {
        printf("enterFirstStmt: left and right type is not fit!\n");
        exit(-1);
    }

    pconst = &ConstVector;
    for (int i = 0; i < (*pconst).size(); i++)
    {
        if (ctx->lVal()->Ident()->getText() == (*pconst)[i]) //43,44对const常量重复定义
        {
            printf("exitFirstStmt:false assign to const!\n");
            exit(-1);
        }
    }
  
    if(ctx->exp()!=nullptr)
    {   
        
        auto firstExp = dynamic_cast<CACTParser::FirstExpContext *>(ctx->exp());   
        if(firstExp!=nullptr)
        {   
            
            auto firstAddexp = dynamic_cast<CACTParser::FirstAddExpContext *>(firstExp->addExp());
            if(firstAddexp !=nullptr)
            {   
                auto secondMulexp = dynamic_cast<CACTParser::SecondMulExpContext *>(firstAddexp->mulExp());
                if(secondMulexp != nullptr)
                {   
                    string mul_divarg1;
                    for(int i=0;i<(*PQuaternion).size();i++)
                    {
                        if(secondMulexp->mulExp()->getText() == (*PQuaternion)[i].name)
                        {
                            mul_divarg1 = (*PQuaternion)[i].result;   //v
                        }
                    }
                    string mul_divtemp1 = t_global();               //乘除式
                    string op =":= ";
                    string mul;
                    string div;
                    string sharp_number;
                    if(secondMulexp->Mul()!=nullptr)
                    {
                        mul = "*";
                        div = "";
                    }
                    if(secondMulexp->Divide()!=nullptr)
                    {
                        mul = "";
                        div = "/";
                    }
                    if(secondMulexp->unaryExp()->is_number == true)
                    {
                        string sharp ="#";
                        string number = secondMulexp->unaryExp()->getText();
                        sharp_number = sharp+number;
                    }
                    string mul_divVariable = mul_divtemp1+op+mul_divarg1+mul+div+sharp_number;     //t=v*#number
                    cout<<mul_divVariable<<endl;
                    POutput->push_back(mul_divVariable);

                    string mul_div_v = v_global();
                    string mul_divAssign = mul_div_v+op+mul_divtemp1;          //v=t
                    POutput->push_back(mul_divAssign);

                    Quater.name = ctx->lVal()->getText();                   //将v=v*/#number存入四元式
                    Quater.result = mul_div_v;
                    Quater.arg1 = mul_divarg1;
                    Quater.op = mul+div;
                    Quater.arg2 = sharp_number;
                    PQuaternion->push_back(Quater);

                }
                auto firstMulexp = dynamic_cast<CACTParser::FirstMulExpContext *>(firstAddexp->mulExp());
                if(firstMulexp != nullptr)
                {   
                    auto firstUnaryExp = dynamic_cast<CACTParser::FirstUnaryExpContext *>(firstMulexp->unaryExp());
                    if(firstUnaryExp != nullptr)
                    {
                        auto secondPrimaryExp = dynamic_cast<CACTParser::SecondPrimaryExpContext *>(firstUnaryExp->primaryExp());
                        if(secondPrimaryExp != nullptr)
                        {
                            int m;                                                     //b=a
                            string temp_tba;
                            string a_vari1;
                            string b_vari2;
                            string temp_vba;
                            string op =":= ";
                            string ba_general1;
                            string ba_general2;
                            for(m=0;m<(*PQuaternion).size();m++)                                     //找a;     
                            {
                                if(ctx->exp()->getText() == (*PQuaternion)[m].name)
                                {
                                    a_vari1 = temp_tba + op + (*PQuaternion)[m].result;
                                    break;
                                }
                            }
                            if(m == (*PQuaternion).size())                                           //找不到则去栈中查找
                            {
                                stack<std::vector<Quaternion> *> newstack(QuaternionStack);          //复制一个栈
                                for(; !newstack.empty();)     //遍历该栈
                                {   
                                    std::vector<Quaternion> *newQuaternion;
                                    newQuaternion = newstack.top();         //指针指向栈顶
                                    for(int i=0;i<(*newQuaternion).size();i++)
                                    {
                                        if((*newQuaternion)[i].name == ctx->exp()->getText())           //找到了
                                        {
                                            a_vari1 = (*newQuaternion)[i].result;
                                            break;
                                        }
                                    }
                                    newstack.pop();       //弹出栈顶vector
                                }
                                            
                            }

                                temp_tba = t_global();
                                ba_general1 = temp_tba + op + a_vari1;
                                POutput->push_back(ba_general1);              //t=v  找到a，并输出

                            int h;
                            int find_flagb = false;
                            for(h=0;h<(*PQuaternion).size();h++)
                            {
                                if(ctx->lVal()->getText()==(*PQuaternion)[h].name)      //该vector中找到了
                                {
                                    b_vari2 = (*PQuaternion)[h].result;
                                    find_flagb = true;
                                    break;
                                }
                            }
                            if(h == (*PQuaternion).size())                                   //找不到则去栈中查找
                            {
                                stack<std::vector<Quaternion> *> newstack(QuaternionStack);     //复制一个栈
                                for(; !newstack.empty();)     //遍历该栈
                                {   
                                    std::vector<Quaternion> *newQuaternion;
                                    newQuaternion = newstack.top();         //指针指向栈顶
                                    for(int i=0;i<(*newQuaternion).size();i++)
                                    {
                                        if((*newQuaternion)[i].name == ctx->lVal()->getText())      //找到了
                                        {
                                            b_vari2 = (*newQuaternion)[i].result;
                                            find_flagb = true;
                                            break;
                                        }
                                    }
                                    newstack.pop();       //弹出栈顶vector
                                }
                                
                            }

                            if(find_flagb == false)
                            {
                                temp_vba = v_global();
                            }
                            else{
                                temp_vba = b_vari2;
                            }

                                ba_general2 = temp_vba + op + temp_tba;
                                cout<<ba_general2<<endl;              //v=t
                                POutput->push_back(ba_general2);

                        }
                    }
                    auto secondUnaryExp = dynamic_cast<CACTParser::SecondUnaryExpContext *>(firstMulexp->unaryExp());
                    if(secondUnaryExp != nullptr)              //判断是否为函数，函数则需要使用CALL
                    {   
                        string variable1;
                        string assign1; 

                        string get_int11="CALL ";
                        string get_int12=secondUnaryExp->Ident()->getText();
                        string get_int1= get_int11+get_int12;
                        cout<<get_int1<<endl;
                        string temp = t_global();
        
                        string op=":= ";
                        string get_int=temp+op+get_int1;        // t1:=CALL get_int
                        cout<<get_int<<endl;
                        POutput->push_back(get_int);

                        for(int i=0;i<(*PQuaternion).size();i++)
                        {
                            if(ctx->lVal()->getText() == (*PQuaternion)[i].name )
                            {
                                variable1 = (*PQuaternion)[i].result;
                                break;
                            }
                            else
                            {
                                variable1=v_global();
                            }
                        }
                        assign1 = variable1+op+temp;      //v= t
                        POutput->push_back(assign1);

                                                              //将a=get_int存入四元式中
                        Quater.name = ctx->lVal()->getText();
                        Quater.result = variable1;
                        Quater.arg1 = ctx->exp()->getText();
                        Quater.arg2 = "";     
                        Quater.op = "";
                        PQuaternion->push_back(Quater);        //v=get_int    name=a
                    }
                }
            }
        }
    }
    
    printf("stmt is %s\n",ctx->exp()->getText().c_str());
    
    auto firstExp = dynamic_cast<CACTParser::FirstExpContext *>(ctx->exp());
    if(firstExp!=nullptr)
        {
            auto secondAddexp = dynamic_cast<CACTParser::SecondAddExpContext *>(firstExp->addExp());
            if(secondAddexp!=nullptr)                        //加减式
            {   
                string add ;
                string sub ;
                if(secondAddexp->Add()!=nullptr)
                {
                    add = "+";
                    sub = "";
                }
                if(secondAddexp->Sub()!=nullptr)
                {
                    sub = "-";
                    add = "";
                }

                string stmtVariable;

                int k;
                for(k=0;k<(*PQuaternion).size();k++)
                {
                    if(secondAddexp->addExp()->getText()==(*PQuaternion)[k].name)   //该vector中找到了
                    {
                        stmtVariable = (*PQuaternion)[k].result;
                        break;
                    }
                }
                  
                if(k == (*PQuaternion).size())                                   //找不到则去栈中查找
                {
                    stack<std::vector<Quaternion> *> newstack(QuaternionStack);     //复制一个栈
                    for(; !newstack.empty();)     //遍历该栈
                    {   
                        std::vector<Quaternion> *newQuaternion;
                        newQuaternion = newstack.top();         //指针指向栈顶
                        for(int i=0;i<(*newQuaternion).size();i++)
                        {
                            if((*newQuaternion)[i].name == secondAddexp->addExp()->getText())      //找到了
                            {
                                stmtVariable = (*newQuaternion)[i].result;
                                break;
                            }
                        }
                        newstack.pop();       //弹出栈顶vector
                    }
                    
                }

                string sharp;
                string or_number;
                if(secondAddexp->mulExp()->is_number==true)       
                {
                    sharp = "#";
                    or_number =secondAddexp->mulExp()->getText();                   
                }
                else
                {
                    sharp = "";
                    int k;
                    for(k=0;k<(*PQuaternion).size();k++)
                    {
                        if(secondAddexp->mulExp()->getText()==(*PQuaternion)[k].name)   //该vector中找到了
                        {
                            or_number = (*PQuaternion)[k].result;
                            break;
                        }
                    }
                  
                    if(k == (*PQuaternion).size())                                   //找不到则去栈中查找
                    {
                        stack<std::vector<Quaternion> *> newstack(QuaternionStack);     //复制一个栈
                        for(; !newstack.empty();)     //遍历该栈
                        {   
                            std::vector<Quaternion> *newQuaternion;
                            newQuaternion = newstack.top();         //指针指向栈顶
                            for(int i=0;i<(*newQuaternion).size();i++)
                            {
                                if((*newQuaternion)[i].name == secondAddexp->mulExp()->getText())      //找到了
                                {
                                    or_number = (*newQuaternion)[i].result;
                                    break;
                                }
                            }
                            newstack.pop();       //弹出栈顶vector
                        }
                        
                    }
                    
                }
                string sharpnumber = sharp+or_number;            //#number
                string live_variable;
                string subassign;
                string op = ":= ";
                bool find_flag = false;
                                                    //找lval是否存在，存在则不需要产生t和v
                int j;
                for(j=0;j<(*PQuaternion).size();k++)
                {
                    if(ctx->lVal()->getText() == (*PQuaternion)[j].name)
                    {   
                        find_flag = true;
                        live_variable = (*PQuaternion)[j].result;
                        break;
                    }
                }
                if(j == (*PQuaternion).size())                                   //找不到则去栈中查找
                {
                    stack<std::vector<Quaternion> *> newstack(QuaternionStack);     //复制一个栈
                    for(; !newstack.empty();)     //遍历该栈
                    {   
                        std::vector<Quaternion> *newQuaternion;
                        newQuaternion = newstack.top();         //指针指向栈顶
                        for(int i=0;i<(*newQuaternion).size();i++)
                        {
                            if((*newQuaternion)[i].name == ctx->lVal()->getText())      //找到了
                            {   
                                find_flag = true;
                                live_variable = (*newQuaternion)[i].result;
                                break;
                            }
                        }
                        newstack.pop();       //弹出栈顶vector
                    }
                    
                }

                if(find_flag == false)
                {
                    string temp_t1;
                    temp_t1=t_global();
                   
                    subassign = temp_t1+op+stmtVariable+add+sub+sharpnumber;      //t=v+- #number
                    POutput->push_back(subassign);

                    Quaternion  Quater;                       //将上述式子存入四元式中
                    Quater.result = temp_t1;
                    Quater.arg1 = stmtVariable;
                    Quater.op = add+sub;
                    Quater.arg2 = sharpnumber;
                    Quater.name = temp_t1;
                    PQuaternion->push_back(Quater);
                

                    string temp_v1 = v_global();                    
                    string subassign2 = temp_v1+op+temp_t1;           //Vi= Ti
                    POutput->push_back(subassign2);
                    
                    Quater.result = temp_v1;             //将v和t记录入四元式中
                    Quater.arg1 = temp_t1;
                    Quater.arg2 = "";
                    Quater.op = "";
                    Quater.name = ctx->lVal()->getText();
                    PQuaternion->push_back(Quater);
                }
                else
                {
                    subassign = live_variable + op + stmtVariable + add + sub + sharpnumber;
                    POutput->push_back(subassign);
     
                }

                
                    
            }
        }


    
      
}

void SemanticAnalysis::enterFuncType(CACTParser::FuncTypeContext * ctx)
{
    if(ctx->getText() == "int")
    {
        ctx->funtype=1;
    }
    if(ctx->getText() == "float")
    {
        ctx->funtype=2;
    }
    if(ctx->getText() == "double")
    {
        ctx->funtype=3;
    }
    if(ctx->getText() == "bool")
    {
        ctx->funtype=4;
    }
    if(ctx->getText() == "void")
    {
        ctx->funtype=5;
    }

}

void SemanticAnalysis::enterBType(CACTParser::BTypeContext * ctx)
{
    if(ctx->getText() == "int")
    {
        ctx->basicType=1;
    }
    if(ctx->getText() == "float")
    {
        ctx->basicType=2;
    }
    if(ctx->getText() == "double")
    {
        ctx->basicType=3;
    }
    if(ctx->getText() == "bool")
    {
        ctx->basicType=4;
    }
}

void SemanticAnalysis::enterFuncDef(CACTParser::FuncDefContext * ctx)
{ 
    //printf("enter funcdef!\n");
    POutput = &OutputVector;
    string strFun1 = "FUNCTION "; 
    string strFun2 = ctx->Ident()->getText().c_str();
    string strFun3 =" :";
    string strFun = strFun1 + strFun2 + strFun3;
    printf("%s\n",strFun.c_str());
    POutput->push_back(strFun);
}

void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext * ctx)       //记录函数信息至函数的vector中
{
    Funtable Fun;                          //结构体名字为Fun
    if (ctx->Ident()->getText() == "main") //main函数合法性的判断
    {
        if (ctx->funcType()->funtype != 1) //main函数类型必须为int
        {
            printf("functype is %d\n", ctx->funcType()->funtype);
            printf("main() funcType is error!\n");
            exit(-1);
        }

        if (ctx->funcFParams() != nullptr) //main函数不能含有形参
        {
            printf("main() funcFParams is error!\n");
            exit(-1);
        }
    }
    Fun.returnType = ctx->funcType()->funtype; //返回值类型
    Fun.name = ctx->Ident()->getText();
    if (ctx->funcFParams() == nullptr) //形参个数为0
    {
        Fun.funNumber = 0;
    }
    if (ctx->funcFParams() != nullptr) //如果含有形参,形参存入函数vector中
    {
        Fun.funNumber = ctx->funcFParams()->funcFParam().size(); //函数参数个数
        int i;
        for (i = 0; i < ctx->funcFParams()->funcFParam().size(); i++)
        {
            FormalParameter Formal;
            Formal.name = ctx->funcFParams()->funcFParam()[i]->Ident()->getText(); //形参名字
            Formal.type = ctx->funcFParams()->funcFParam()[i]->bType()->basicType; //形参类型
            Fun.FormalParameterVector.push_back(Formal);                           //存形参类型,名字的vector
        }
    }
    FuntableVector.push_back(Fun); //将结构体存入vector中
}

void SemanticAnalysis::exitCompUnit(CACTParser::CompUnitContext * ctx)    //判断main（）函数的合法性
{
    int i;
    int n = 0; //定义一个计数器来得到main函数的个数
    for (i = 0; i < FuntableVector.size(); i++)
    {
        if (FuntableVector[i].name == "main") //含有main
        {
            n++;
            printf("main()=%d!\n", n);
        }
    }
    if (n == 0)
    {
        printf("exitCompUnit():lost main()!\n");
        exit(-1);
    }
    if (n > 1)
    {
        printf("exitCompUnit():main() is more!\n ");
        exit(-1);
    }

    for(int i=0;i<OutputVector.size();i++)
    {
        cout<<OutputVector[i]<<endl;
    }
}

void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext * /*ctx*/)
{
    curVarVec = new std::vector<Variable>();       //初始一个全局的vector
    PQuaternion = new std::vector<Quaternion>();   //初始一个四元式的全局vector
}

void SemanticAnalysis::enterBlock(CACTParser::BlockContext * ctx)
{

    symbolTableStack.push(curVarVec);        //进入之后先将之前的vector压入栈中
    curVarVec = new std::vector<Variable>(); //指针指向新创建的vector

    QuaternionStack.push(PQuaternion);       //进入括号之前将上一个四元式压入栈中
    PQuaternion = new std::vector<Quaternion>();   //指针指向新创建的四元式vector

    //std::vector<Variable> *newVarVec;
    //stack<std::vector<Variable> *> newstack(symbolTableStack);

    pconst = new std::vector<string>(); //每次进入花括号前都会初始化一个vector，用来存储花括号内const常量

    auto funcdef = dynamic_cast<CACTParser::FuncDefContext *>(ctx->parent); //将形参存入到variable vector中
    if (funcdef != nullptr)                                                 //花括号前确实含有函数定义
    {
        //std::vector<TempFun> *newFunVec;      //创建一个新的vector指针，解决函数作用域问题
        //std::vector<TempFun> newvector(TempFunVector);    //复制一个vector前后类型要一样，括号内相当于是初始化。

        ptempfun = new std::vector<TempFun>(); //每次进来前面要是函数定义，则创建一个新的临时函数vectot
        TempFun TFun;
        TFun.name = funcdef->Ident()->getText();
        TFun.returnType = funcdef->funcType()->funtype;
        if (funcdef->funcFParams() != nullptr)
        {
            for (int i = 0; i < funcdef->funcFParams()->funcFParam().size(); i++)
            {
                TFun.FParamsVector.push_back(funcdef->funcFParams()->funcFParam()[i]->Ident()->getText());
            }

            TFun.funNumber = funcdef->funcFParams()->funcFParam().size();
        }
        else
        {
            TFun.funNumber = 0;
        }

        TempFunVector.push_back(TFun);

        if (funcdef->funcFParams() != nullptr) //解决形参作为变量的问题
        {
            for (int i = 0; i < funcdef->funcFParams()->funcFParam().size(); i++)
            {
                Variable var;
                var.name = funcdef->funcFParams()->funcFParam()[i]->Ident()->getText();
                var.size = 0;
                var.type = funcdef->funcFParams()->funcFParam()[i]->bType()->basicType;
                var.is_array = false;
                curVarVec->push_back(var);
            }
        }
    }
}

void SemanticAnalysis::exitBlock(CACTParser::BlockContext * ctx)
{
    delete curVarVec;                   //离开花括号右边时，删除该vector
    curVarVec = symbolTableStack.top(); //指针指向栈顶元素
    symbolTableStack.pop();             //弹出栈顶元素

    delete PQuaternion;
    PQuaternion = QuaternionStack.top();
    QuaternionStack.pop(); 

    ptempfun = &TempFunVector;

    auto forBlock = dynamic_cast<CACTParser::FuncDefContext *>(ctx->parent); //保证block为函数产生的block
    if (forBlock != nullptr)
    {
        vector<TempFun>().swap(TempFunVector); //清除了元素，并回收临时函数vector内存
    }
    vector<string>().swap(ConstVector); //清除constvector中元素和内存
}

 void SemanticAnalysis::exitFirstRelExp(CACTParser::FirstRelExpContext * ctx) 
 {
     ctx->type = ctx->addExp()->type;
     ctx->size = ctx->addExp()->size;
     ctx->is_array = ctx->addExp()->is_array;
     ctx->boolType = ctx->addExp()->boolType;
     ctx->is_number = ctx->addExp()->is_number;
 }

 void SemanticAnalysis::enterFifthStmt(CACTParser::FifthStmtContext * ctx)
 {  
     string temp_fifLabel = new_label();
     label_times++;
     string charactor = " :";
     string LABEL = "LABEL ";
     string general_1;

     general_1 = LABEL + temp_fifLabel + charactor;
     POutput->push_back(general_1);

     PLabel = &LabelVector;
     Label Lab;                          //将产生label存入到label vector中
     Lab.name = temp_fifLabel;
     Lab.times = label_times;
     Lab.label = "upwhile_label";
     PLabel->push_back(Lab);

 }

 void SemanticAnalysis::exitSecondRelExp(CACTParser::SecondRelExpContext * ctx)     //判断if、while函数cond是否为bool类型
 {

     if (ctx->getText() == "<")
     {
         ctx->boolType = 1;
     }
     if (ctx->getText() == ">")
     {
         ctx->boolType = 1;
     }
     if (ctx->getText() == "<=")
     {
         ctx->boolType = 1;
     }
     if (ctx->getText() == ">=")
     {
         ctx->boolType = 1;
     }

     if ((ctx->relExp()->is_array == true) || (ctx->addExp()->is_array == true))
     {
         printf("exitSecondRelExp:array can't used op\n");
         exit(-1);
     }

     string IF = "IF ";
     string GOTO = " GOTO ";
     string GOTO2 = "GOTO ";
     string less_charater;
     string v_1;
     string v_2;
     string general_relexp1;
     string general_relexp2;

     Label Lab;
     string temp_relexplabel1 = new_label();                //while中存入第一个goto label
     label_times++;
     Lab.name = temp_relexplabel1;
     Lab.times = label_times;
     Lab.label = "while1_label";
     PLabel->push_back(Lab);

     string temp_relexplabel2 = new_label();               //while中存入第二个goto label
     label_times++;
     Lab.name = temp_relexplabel2;
     Lab.times = label_times;
     Lab.label = "while2_label";
     PLabel->push_back(Lab);
     
     auto firsteqexp = dynamic_cast<CACTParser::FirstEqExpContext *>(ctx->parent);
     if(firsteqexp!=nullptr)
     {
         auto firstlandexp = dynamic_cast<CACTParser::FirstlAndExpContext *>(firsteqexp->parent);
         if(firstlandexp != nullptr)
         {
             auto firstlorexp = dynamic_cast<CACTParser::FirstlOrExpContext *>(firstlandexp->parent);
             if(firstlorexp !=nullptr)
             {
                 auto cond = dynamic_cast<CACTParser::CondContext *>(firstlorexp->parent);
                 if(cond != nullptr)
                 {
                     auto fifthstmt = dynamic_cast<CACTParser::FifthStmtContext *>(cond->parent);
                     if(fifthstmt != nullptr)
                     {
                        
                        for(int i=0;i<(*PQuaternion).size();i++)
                        {
                            if(ctx->relExp()->getText() == (*PQuaternion)[i].name )
                            {
                                v_1 = (*PQuaternion)[i].result;
                                break;
                            }
                        }

                        for(int i=0;i<(*PQuaternion).size();i++)
                        {
                            if(ctx->addExp()->getText() == (*PQuaternion)[i].name )
                            {
                                v_2 = (*PQuaternion)[i].result;
                                break;
                            }
                        }

                        if(ctx->LESS() != nullptr)
                        {
                            less_charater = "<";
                        }

                        general_relexp1 = IF + v_1 + less_charater + v_2 + GOTO + temp_relexplabel1;
                        POutput->push_back(general_relexp1);           //IF v < v goto labeli

                        general_relexp2 = GOTO2 + temp_relexplabel2;
                        POutput->push_back(general_relexp2);           //goto label(i+1)
                     }
                 }
             }
         }
     }
 }

 void SemanticAnalysis::exitThirdRelExp(CACTParser::ThirdRelExpContext * ctx) 
 {
     if (ctx->BoolConst())
     {
         ctx->boolType = 1;
     }
 }

 void SemanticAnalysis::exitFirstEqExp(CACTParser::FirstEqExpContext * ctx)
 {
     ctx->boolType = ctx->relExp()->boolType;
     //printf("booltype is %d\n",ctx->boolType);
     ctx->type = ctx->relExp()->type;
     ctx->size = ctx->relExp()->size;
     ctx->is_array = ctx->relExp()->is_array;
 }

 void SemanticAnalysis::exitFirstlAndExp(CACTParser::FirstlAndExpContext * ctx) 
 { 
    ctx->boolType=ctx->eqExp()->boolType;
 }

 void SemanticAnalysis::exitFirstlOrExp(CACTParser::FirstlOrExpContext * ctx) 
 {
    ctx->boolType=ctx->lAndExp()->boolType;
 }

 void SemanticAnalysis::exitCond(CACTParser::CondContext * ctx)
 {  
    
    ctx->boolType=ctx->lOrExp()->boolType;

    string label;
    string LABEL = "LABEL ";
    string general_cond;
    string character = " :";

    PLabel = &LabelVector;
    for(int i=0;i<(*PLabel).size();i++)
    {
        if((*PLabel)[i].label == "if_label")
        {
            if((*PLabel)[i].name =="label1")
            {
                label = "label1";
            }
        }
    }
    

    auto fourthstmt = dynamic_cast<CACTParser::FourthStmtContext *>(ctx->parent);     //IF需产生label
    if(fourthstmt!=nullptr)
    {
        general_cond = LABEL+label+character;
        POutput->push_back(general_cond);
                        
        Label Lab;            //存入label vector中
        Lab.name = label;
        Lab.times = 1;
        Lab.label = label;
        PLabel->push_back(Lab);
    }

    auto fifthstmt = dynamic_cast<CACTParser::FifthStmtContext *>(ctx->parent);    //生成while产生的label
    {
        string temp_label2;
        string character2 = " :";
        string general_label2;
        Label Lab;
        for(int i=0;i<(*PLabel).size();i++)
        {
            if((*PLabel)[i].label == "while1_label")
            {
                temp_label2 = (*PLabel)[i].name;
                Lab.times = (*PLabel)[i].times;
            }
        }
        general_label2 = LABEL + temp_label2 + character2;
        POutput->push_back(general_label2);
     
        Lab.name = temp_label2;
        Lab.label = temp_label2;

    }
 } 

void SemanticAnalysis::exitFifthStmt(CACTParser::FifthStmtContext * ctx)     //while合法性判断 25
{   
    //printf("booltype is %d\n",ctx->cond()->boolType);
    if (ctx->cond()->boolType == 0)
    {
        printf("exitFifthStmt:cond is not approved!\n");
        exit(-1);
    }

    string GOTO = "GOTO ";
    string LABEL = "LABEL ";
    string temp_label1;
    string temp_label3;
    string character_exitfifstmt = " :";
    string general_label1;
    string general_label3;
    int  time_label1;
    int time_label3;
    for(int i=0;i<(*PLabel).size();i++)
    {
        if((*PLabel)[i].label == "upwhile_label")
        {
            temp_label1 = (*PLabel)[i].name;
            time_label1 = (*PLabel)[i].times;
        }
    }

    for(int j=0;j<(*PLabel).size();j++)
    {
        if((*PLabel)[j].label == "while2_label")
        {
            temp_label3 = (*PLabel)[j].name;
            time_label3 = (*PLabel)[j].times;
        }
    }
    Label Lab;
    general_label1 = GOTO + temp_label1;
    POutput->push_back(general_label1);
    Lab.name = temp_label1;
    Lab.times = time_label1;
    Lab.label = temp_label1;
    PLabel->push_back(Lab);                         //GOTO label1 中label存入

    general_label3 = LABEL + temp_label3 + character_exitfifstmt;
    POutput->push_back(general_label3); 
    Lab.name = temp_label3;
    Lab.times = time_label3;
    Lab.label = temp_label3;
    PLabel->push_back(Lab);
}

void SemanticAnalysis::exitFourthStmt(CACTParser::FourthStmtContext * ctx)   //if合法性判断  26
{
    if (ctx->cond()->boolType == 0)
    {
        printf("exitFourthStmt:cond is not approved!\n");
        exit(-1);
    }

    string LABEL = "LABEL ";
    string temp_nextLable = new_label();
    string character = " :";
    label_times++;
    string general_next ;
    general_next = LABEL + temp_nextLable + character;
    POutput->push_back(general_next);

    Label Lab;                    //label 3 存入
    Lab.name = temp_nextLable;
    Lab.times = label_times;
    Lab.label = temp_nextLable;
    PLabel->push_back(Lab);

}

void SemanticAnalysis::exitSecondUnaryExp(CACTParser::SecondUnaryExpContext * ctx)
{
      if(ctx->Ident()->getText()=="get_int")
      {
          ctx->type = 1;
      }
      if(ctx->Ident()->getText()=="get_float")
      {
          ctx->type = 2;
      }
      if(ctx->Ident()->getText()=="get_double")
      {
          ctx->type = 3;
      }

      ctx->size = 0;

      curFunVec = &FuntableVector;
      for (int i = 0; i < (*curFunVec).size(); i++)
      {
          if (ctx->Ident()->getText() == (*curFunVec)[i].name)
          {
              ctx->type = (*curFunVec)[i].returnType;
          }
          else
          {
              ctx->type = 1;
          }
      }

      ctx->is_array = false;
      if (ctx->funcRParams() != nullptr)
      {
          ctx->returnNumber = ctx->funcRParams()->exp().size();
      }
      if (ctx->funcRParams() == nullptr)
      {
          ctx->returnNumber = 0;
      }

      for (int i = 0; i < FuntableVector.size(); i++)
      {
          if (ctx->Ident()->getText() == FuntableVector[i].name) //函数调用时，函数名字匹配上了
          {
              if (ctx->returnNumber != FuntableVector[i].funNumber) //40
              {
                  printf("exitSecondUnaryExp:formal parameter number and actual paramenter number is not fit!\n");
                  exit(-1);
              }

              if (ctx->funcRParams() != nullptr) //41
              {
                  for (int j = 0; j < ctx->funcRParams()->exp().size(); j++)
                  {
                      for (int k = 0; k < FuntableVector[i].FormalParameterVector.size(); k++)
                      {
                          if (ctx->funcRParams()->exp()[j]->getText() == FuntableVector[i].FormalParameterVector[k].name) //实参和函数变量vector中实参相同
                          {
                              for (int m = 0; m < (*curVarVec).size(); m++) //遍历变量vector
                              {
                                  if ((*curVarVec)[m].name == ctx->funcRParams()->exp()[j]->getText()) //寻找变量vector中对实参的记录
                                  {
                                      if ((*curVarVec)[m].type != FuntableVector[i].FormalParameterVector[k].type)    //判断实参在变量vector中记录的类型和函数vector记录的形参类型是否相同
                                      {   
                                          printf("exitSecondUnaryExp:actual type and formal type is not fit!\n");
                                          exit(-1);
                                      }
                                  }
                              }
                          }
                      }
                  }
              }
          }
      }

      for (int i = 0; i < FuntableVector.size(); i++) //返回函数的bool类型
      {
          if (ctx->Ident()->getText() == FuntableVector[i].name)
          {
              if (FuntableVector[i].returnType == 4)
              {
                  ctx->boolType = 1;
              }
              else
              {
                  ctx->boolType = 0;
              }
          }
      }

    

    
    if(ctx->Ident()->getText()=="print_int")                    //print_int函数掉用操作
    {
        if(ctx->funcRParams() != nullptr)
        {   
            if(ctx->funcRParams()->getText()=="get_int()")       //实参为get_int()
            {   
                string Variable1 = v_global();
                string op = ":= ";
                string call = "CALL ";
                string func1 = "get_int";
                string call_get_int = Variable1 + op + call + func1;
                cout<<call_get_int<<endl;
                POutput->push_back(call_get_int);              //v1:= CALL get_int

                string arg = "ARG ";
                string parameter = Variable1;
                string arg_variable = arg+Variable1;           //ARG v1
                cout<<arg_variable<<endl;
                POutput->push_back(arg_variable);
            }

            //printf("%S\n",ctx->funcRParams()->getText().c_str());
            int k;
            string print_int1 = "ARG ";
            string print_int2;
            string print_int;
            for(k=0;k<(*PQuaternion).size();k++)
            {
                if(ctx->funcRParams()->getText()==(*PQuaternion)[k].name)
                {   
                    print_int2 = (*PQuaternion)[k].result;    //v1
                    break;   
                }
               
            }
            if(k == (*PQuaternion).size())                                   //找不到则去栈中查找
                {
                    stack<std::vector<Quaternion> *> newstack(QuaternionStack);     //复制一个栈
                    for(; !newstack.empty();)     //遍历该栈
                    {   
                        std::vector<Quaternion> *newQuaternion;
                        newQuaternion = newstack.top();         //指针指向栈顶
                        for(int i=0;i<(*newQuaternion).size();i++)
                        {
                            if((*newQuaternion)[i].name == ctx->funcRParams()->getText())      //找到了
                            {
                                print_int2 = (*newQuaternion)[i].result;
                                break;
                            }
                        }
                        newstack.pop();       //弹出栈顶vector
                    }
                    
                }
                print_int = print_int1 + print_int2;
                cout<<print_int<<endl ;
                POutput->push_back(print_int);
                
                
            string funcPrint_int = "print_int ";
            string call ="CALL print_int";
            cout<<call<<endl;
            POutput->push_back(call);

        }
    }
    else if(ctx->Ident()->getText()=="print_float")                 //print_float函数掉用操作
    {
        if(ctx->funcRParams() != nullptr)
        {   
            if(ctx->funcRParams()->getText()=="get_float()")       //实参为get_float()
            {   
                string Variable1 = v_global();
                string op = ":= ";
                string call = "CALL ";
                string func1 = "get_float";
                string call_get_float = Variable1 + op + call + func1;
                cout<<call_get_float<<endl;
                POutput->push_back(call_get_float);              //v1:= CALL get_float

                string arg = "ARG ";
                string parameter = Variable1;
                string arg_variable = arg+Variable1;           //ARG v1
                cout<<arg_variable<<endl;
                POutput->push_back(arg_variable);
            }

            //printf("%S\n",ctx->funcRParams()->getText().c_str());
            for(int i=0;i<(*PQuaternion).size();i++)
            if(ctx->funcRParams()->getText()==(*PQuaternion)[i].name)
            {   
                string print_float1 = "ARG ";
                string print_float2 = (*PQuaternion)[i].result;    //v1
                string print_float = print_float1 + print_float2;
                cout<<print_float<<endl ;
                POutput->push_back(print_float);
                break;
            }

            string funcPrint_float = "print_float ";
            string call ="CALL print_float";
            cout<<call<<endl;
            POutput->push_back(call);
        }
    }
    else if(ctx->Ident()->getText()=="print_double")               //print_double函数操作
    {
        if(ctx->funcRParams() != nullptr)
        {   

            if(ctx->funcRParams()->getText()=="get_double()")       //实参为get_double()
            {   
                string Variable1 = v_global();
                string op = ":= ";
                string call = "CALL ";
                string func1 = "get_double";
                string call_get_double = Variable1 + op + call + func1;
                cout<<call_get_double<<endl;
                POutput->push_back(call_get_double);              //v1:= CALL get_int

                string arg = "ARG ";
                string parameter = Variable1;
                string arg_variable = arg+Variable1;           //ARG v1
                cout<<arg_variable<<endl;
                POutput->push_back(arg_variable);
            }

            //printf("%S\n",ctx->funcRParams()->getText().c_str());
            for(int i=0;i<(*PQuaternion).size();i++)
            if(ctx->funcRParams()->getText()==(*PQuaternion)[i].name)
            {   
                string print_double1 = "ARG ";
                string print_double2 = (*PQuaternion)[i].result;    //v1
                string print_double = print_double1 + print_double2;
                cout<<print_double<<endl ;
                POutput->push_back(print_double);
                break;            
            }
            string funcPrint_double = "print_double ";
            string call ="CALL print_double";
            cout<<call<<endl;
            POutput->push_back(call);

        }
    } 
    else if(ctx->Ident()->getText()=="print_bool")               //print_bool函数操作
    {
        if(ctx->funcRParams() != nullptr)
        {               
            //printf("%S\n",ctx->funcRParams()->getText().c_str());
            for(int i=0;i<(*PQuaternion).size();i++)
            if(ctx->funcRParams()->getText()==(*PQuaternion)[i].name)
            {   
                string print_bool1 = "ARG ";
                string print_bool2 = (*PQuaternion)[i].result;         //v1
                string print_bool = print_bool1 + print_bool2;
                cout<<print_bool<<endl ;
                POutput->push_back(print_bool);
                break;
            }

            string funcPrint_bool = "print_bool ";
            string call ="CALL print_bool";
            cout<<call<<endl;
            POutput->push_back(call);
        }
    }
    else
    {
        if(ctx->funcRParams() != nullptr)
        {
            for(int i=0;i<(*PQuaternion).size();i++)
            if(ctx->funcRParams()->getText()==(*PQuaternion)[i].name)
            {
                string print_bool1 = "ARG ";
                string print_bool2 = (*PQuaternion)[i].result;         //v1
                string print_bool = print_bool1 + print_bool2;
                POutput->push_back(print_bool);
                break;
            }

            string general_fun;
            string function_name = ctx->Ident()->getText();
            string call = "CALL ";
            general_fun = call + function_name;
            POutput->push_back(general_fun);
        }
    } 

    

}

void SemanticAnalysis::exitEighthStmt(CACTParser::EighthStmtContext * ctx)
{
    ptempfun = &TempFunVector;
    if (ctx->exp() != nullptr) //37
    {
        //printf("left type is %d\n",ctx->exp()->type);
        //printf("right type is %d\n",(*ptempfun)[0].returnType);
        if (ctx->exp()->type != (*ptempfun)[0].returnType)
        {
            printf("exitEighthStmt: return type is not fit!\n");
            exit(-1);
        }
    }

    if (ctx->exp() == nullptr) //38
    {
        if ((*ptempfun)[0].returnType != 5)
        {
            printf("exitEighthStmt: should have return type!\n");
            exit(-1);
        }
    }

    printf("exitEighthStmt: finish a return!\n");

    if(ctx->exp() != nullptr)                //返回值中间代码
    {   
        int i;
        Quaternion Quater;
        Quater.result = t_global();
        Quater.name = "RETURN";
        string arg11;
        string arg12;
        
        auto firstexp = dynamic_cast<CACTParser::FirstExpContext *>(ctx->exp());
        if(firstexp->addExp()->is_number == true)
        {
            arg11 = "#";                   //为数字，返回加#
            arg12 = ctx->exp()->getText(); 
        }
        else
        {
            arg11 = "";

            int j;
            for(int j=0;j<(*PQuaternion).size();j++)
            {
                if(ctx->exp()->getText() == (*PQuaternion)[j].name)
                {
                    arg12 = (*PQuaternion)[j].result;
                    break;
                }
            }
            if(j == (*PQuaternion).size())                     //找不到则去栈中查找
            {
                stack<std::vector<Quaternion> *> newstack(QuaternionStack);     //复制一个栈
                for(; !newstack.empty();)     //遍历该栈
                {   
                    std::vector<Quaternion> *newQuaternion;
                    newQuaternion = newstack.top();         //指针指向栈顶
                    for(int i=0;i<(*newQuaternion).size();i++)
                    {
                        if((*newQuaternion)[i].name == ctx->exp()->getText())      //找到了
                        {
                            arg12 = (*newQuaternion)[i].result;
                            break;
                        }
                    }
                    newstack.pop();       //弹出栈顶vector
                }
            }
        }
        
        Quater.arg1 = arg11+arg12;
        Quater.op = "";
        Quater.arg2 = "";
        PQuaternion->push_back(Quater);
        string op = ":= ";
        string return0q = Quater.result + op + Quater.arg1 + Quater.op + Quater.arg2;
        cout<<return0q<<endl;
        POutput = &OutputVector;
        POutput->push_back(return0q);

        string return001 ="RETURN ";
        string return00 = return001+Quater.result;
        cout<<return00<<endl;
        POutput->push_back(return00);
    }
}

void SemanticAnalysis::enterFourthStmt(CACTParser::FourthStmtContext * ctx) 
{
   
}

void SemanticAnalysis::exitSecondEqExp(CACTParser::SecondEqExpContext * ctx)   //35
{   //printf("secondeqexp is %s\n",ctx->eqExp()->is_array);
    
    if (ctx->eqExp()->is_array == true)
    {
        if (ctx->eqExp()->type == 4)
        {
            printf("exitSecondEqExp:bool type array can't operation!\n");
            exit(-1);
        }
    }
    if (ctx->relExp()->is_array == true)
    {
        if (ctx->relExp()->type == 4)
        {
            printf("exitSecondEqExp:bool type array can't operation!\n");
            exit(-1);
        }
    }

    POutput = &OutputVector;
    PLabel = &LabelVector;
    Label Lab;
    string if_judage;
    string sif = "IF ";
    string v_condname;
    string equal;
    string notequal;
    string RelExp;
    string mark;
    string RelExp1;
    string iflabel1;
    string if_jump =" GOTO ";
    string else_jump = "GOTO ";
    string elselabel2;
    string  goto_another;       //goto label2
    

    auto firstlandexp = dynamic_cast<CACTParser::FirstlAndExpContext *>(ctx->parent);
    if(firstlandexp!=nullptr)
    {
        auto firstlorexp = dynamic_cast<CACTParser::FirstlOrExpContext *>(firstlandexp->parent);
        if(firstlorexp!=nullptr)
        {
            auto cond = dynamic_cast<CACTParser::CondContext *>(firstlorexp->parent);
            if(cond!=nullptr)
            {
                for(int i=0;i<(*PQuaternion).size();i++)      //寻找eqexp对应元素存储位子
                {
                    if(ctx->eqExp()->getText() == (*PQuaternion)[i].name)
                    v_condname = (*PQuaternion)[i].result;
                }

                if(ctx->Equal()!=nullptr)            //打印使用符号
                {
                    equal = "==";
                    notequal ="";
                }
                if(ctx->NotEqual()!=nullptr)
                {
                    equal ="";
                    notequal ="!=";
                }

                if(ctx->relExp()->is_number == true)      //number前面#号
                {
                    mark = "#";
                }
                else
                {
                    mark = "";
                }
                RelExp1 = ctx->relExp()->getText();
                RelExp = mark+RelExp1;                      //"#"+number

                iflabel1 = new_label();
                label_times++;
                Label Lab;
                PLabel = &LabelVector;
                Lab.name = iflabel1;
                Lab.times = label_times;
                Lab.label = "if_label";
                PLabel->push_back(Lab);

                if_judage = sif+v_condname+equal+notequal+RelExp+if_jump+iflabel1;
                POutput->push_back(if_judage);

                auto fourthstmt = dynamic_cast<CACTParser::FourthStmtContext *>(cond->parent);
                if(fourthstmt!=nullptr)                       //如果含有else则创建一个label
                {   
                    
                    if(fourthstmt->cactElse()!= nullptr)
                    {   
                        elselabel2 = new_label();
                        label_times++;
                        
                        Lab.name = elselabel2;
                        Lab.times = label_times;
                        Lab.label = "else_label";
                        PLabel->push_back(Lab);

                        goto_another = else_jump+elselabel2;
                        POutput->push_back(goto_another);
                        
                    }
                }

            }
        }
    }
   
} 

void SemanticAnalysis::enterCactElse(CACTParser::CactElseContext * ctx)
{   
    string GOTO = "GOTO ";
    string temp_cactlabel;
    string general_cact;

    for(int i=0;i<(*PLabel).size();i++)
    {
        if((*PLabel)[i].label == "label1")
        {
            if((*PLabel)[i].times == 1)
            {
                temp_cactlabel = "label3";
                break;  
            }
        }
    }
    general_cact = GOTO + temp_cactlabel;
    POutput->push_back(general_cact);

}
void SemanticAnalysis::exitCactElse(CACTParser::CactElseContext * ctx)  
{ 
    string LABEL = "LABEL ";
    string temp_label;
    string general_exitcact;
    string character = " :";

    for(int i=0;i<(*PLabel).size();i++)
    {
        if((*PLabel)[i].label == "else_label")
        {
            if((*PLabel)[i].times == 2)
            {
                temp_label = (*PLabel)[i].name;

                Label Lab;
                Lab.name = temp_label;
                Lab.times = 2;
                Lab.label = temp_label;
                PLabel->push_back(Lab);
            }
        }
    }
    general_exitcact = LABEL + temp_label + character;
    POutput->push_back(general_exitcact);

}

 void SemanticAnalysis::enterThirdStmt(CACTParser::ThirdStmtContext * ctx)
 { 
     

 }