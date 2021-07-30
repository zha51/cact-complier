#include "semanticAnalysis.h"
#include <vector>
#include <string>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

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

    for (int i = 0; i < ctx->constDef().size(); i++) //将const加入到const的vector中
    {
        pconst = &ConstVector;
        pconst->push_back(ctx->constDef()[i]->Ident()->getText());
        printf("const vector size is %d\n", (*pconst).size());
    }

    Variable var; //将const常量也存入variable vector中
    for (int i = 0; i < ctx->constDef().size(); i++)
    {
        var.name = ctx->constDef()[i]->Ident()->getText();
        var.size = 0;
        var.type = ctx->bType()->basicType; //6为const常量类型
        var.is_array = false;
        curVarVec->push_back(var); //将常量也放在variable vector中，解决const常量重新定义问题
        printf("achive a const\n");
    }
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
        }
    }
}

void  SemanticAnalysis::exitDecl(CACTParser::DeclContext * ctx)
{
    printf("exitDecl!\n");
}

void SemanticAnalysis::enterConstDef(CACTParser::ConstDefContext * ctx)
{
    printf("const Def test!!!!!!! ,Ident is: %s\n", ctx->Ident()->getText().c_str()); //输出变量类型
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
    //printf("exitFirstMulExp() type is %d\n",ctx->type);
}

void SemanticAnalysis::exitFirstUnaryExp(CACTParser::FirstUnaryExpContext * ctx)
{
    ctx->type = ctx->primaryExp()->type;
    ctx->size = ctx->primaryExp()->size;
    ctx->is_array = ctx->primaryExp()->is_array;
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
    printf("type is %d\n", ctx->type);
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
    ctx->type = 1;
    ctx->is_array = false;
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
     printf("ArrayVarDef1\n");
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
    {                                               //printf("add is %d\n",ctx->addExp()->type);
        //printf("mul is %d\n",ctx->mulExp()->type);
        printf("exitSecondAddExp:type is not fit!\n");
        exit(-1);
    }

    ctx->type = ctx->mulExp()->type; //参数继续向上传递
    ctx->size = ctx->mulExp()->size;
    ctx->is_array = ctx->mulExp()->is_array;
    //printf("addexp is %d\n",ctx->type);
}

void SemanticAnalysis::exitFirstStmt(CACTParser::FirstStmtContext * ctx)   //主要处理等号两边数组不匹配问题
{
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

    for (int i = 0; i < (*pconst).size(); i++)
    {
        if (ctx->lVal()->Ident()->getText() == (*pconst)[i]) //43,44对const常量重复定义
        {
            printf("exitFirstStmt:false assign to const!\n");
            exit(-1);
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
    printf("enter funcdef!\n");
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
            printf("main()=%d!", n);
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
}

void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext * /*ctx*/)
{
    curVarVec = new std::vector<Variable>();       //初始一个全局的vector
}

void SemanticAnalysis::enterBlock(CACTParser::BlockContext * ctx)
{

    symbolTableStack.push(curVarVec);        //进入之后先将之前的vector压入栈中
    curVarVec = new std::vector<Variable>(); //指针指向新创建的vector

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

 void SemanticAnalysis::exitLAndExp(CACTParser::LAndExpContext * ctx)
 { 
        ctx->boolType=ctx->eqExp()->boolType;
 }

 void SemanticAnalysis::exitLOrExp(CACTParser::LOrExpContext * ctx)
 {
        ctx->boolType=ctx->lAndExp()->boolType;
 }

 void SemanticAnalysis::exitCond(CACTParser::CondContext * ctx)
 {
        ctx->boolType=ctx->lOrExp()->boolType;
 } 

void SemanticAnalysis::exitFifthStmt(CACTParser::FifthStmtContext * ctx)     //while合法性判断 25
{   //printf("exitFifthStmt:00000!\n");
    //printf("booltype is %d\n",ctx->cond()->boolType);
    if (ctx->cond()->boolType == 0)
    {
        printf("exitFifthStmt:cond is not approved!\n");
        exit(-1);
    }
}

void SemanticAnalysis::exitFourthStmt(CACTParser::FourthStmtContext * ctx)   //if合法性判断  26
{
    if (ctx->cond()->boolType == 0)
    {
        printf("exitFourthStmt:cond is not approved!\n");
        exit(-1);
    }
}

void SemanticAnalysis::exitSecondUnaryExp(CACTParser::SecondUnaryExpContext * ctx)
{
      /* curFunVec = &FuntableVector;                       //void返回值用来做加法
        for (int i = 0; i < (*curFunVec).size(); i++)
        {
            if(ctx->Ident()->getText() == (*curFunVec)[i].name)
            {   
                if((*curFunVec)[i].returnType==5)
                {
                    printf("SecondUnaryExp:void type func can't use to add!\n");
                    exit(-1);
                }
            }
        }   */

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
                                      if ((*curVarVec)[m].type != FuntableVector[i].FormalParameterVector[k].type)
                                          ; //判断实参在变量vector中记录的类型和函数vector记录的形参类型是否相同
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
   
}