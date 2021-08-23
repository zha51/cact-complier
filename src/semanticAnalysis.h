#pragma

#include "../grammar/CACTBaseListener.h"
#include <stdio.h>
#include <vector>
#include <string>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include <stack>

using namespace std;

#define INT_TYPE 1
#define FLOAT_TYPE 2
#define DOUBLE_TYPE 3


class SemanticAnalysis : public CACTBaseListener
{
private:
    /* data */
public:
    SemanticAnalysis(/* args */) {}
    ~SemanticAnalysis() {}

typedef struct 
{
    string     name;
    int        type;
}TypeVariable;
std::vector<TypeVariable>StrTypeVector;            //定义一个vector，解决same name问题

typedef struct                     //解决数组不匹配问题，定义数组结构体
{
    string    name;                 
    int      size;                 //数组内长度
    int      type;                  //类型
    bool     is_array;
}Variable;
std::vector<Variable> VariableVector;              //定义一个存储变量的vector

std::vector<Variable> * curVarVec;                 //创建一个vector的指针
stack<std::vector<Variable> *> symbolTableStack;    //创建一个栈来解决定义域问题

typedef struct          //形参结构体，存放在函数vector中
{
    string name;
    int    type;
}FormalParameter;

typedef struct 
{
    string    name;       //函数名字
    int    returnType;   //函数返回类型
    int     funNumber;    //函数形参个数
    std::vector<FormalParameter> FormalParameterVector;     //定义一个vector装参数类型和名字
}Funtable;
std::vector<Funtable> FuntableVector;            //vector中每个函数结构体作为vector表项

std::vector<Funtable> * curFunVec;          //创建一个函数vector指针

std::vector<FormalParameter> *curForVec;      //形参vector中的指针

typedef struct       //定义一个临时vector解决函数定义时信息记录
{
    string   name;
    int      returnType;
    int      funNumber;      //形参个数
    std::vector<string>FParamsVector;
}TempFun;
std::vector<TempFun> TempFunVector;

std::vector<TempFun> * ptempfun;   //定义一个临时函数vector的指针

std::vector<string> ConstVector;     //定义一个临时vector，存储花括号内定义的常量

std::vector<string> * pconst;       //定义一个常量vector的指针

typedef struct                  //创建一个四元式
{   
   string   name;              //新建name方便对四元式进行操作
   string    op;
   string    arg1;
   string    arg2;
   string    result;
}Quaternion; 

std::vector<Quaternion> QuaternionVector ;    //定义一个四元式的vector
std::vector<Quaternion> * PQuaternion ;        //定义四元式的指针
stack<std::vector<Quaternion> *> QuaternionStack ; //将四元式存入栈中，解决定义域问题

std::vector<string> OutputVector;   //定义一个输出vector
std::vector<string> * POutput;

string  v_global()    //设置全局变量解决vi变量问题
{
    static int count = 0 ;
    count++;
    char c[100];
    sprintf(c, "%d", count);
    string  i(c);
    string vglo1= "v";
    string vglo2= i;
    string vglo = vglo1+vglo2;
    return vglo;
}

string t_global()      //Ti
{
    static int count = 0 ;
    count++;
    char c[100];
    sprintf(c, "%d", count);
    string j(c);
    string tglo1= "t";
    string tglo2= j;
    string tglo = tglo1+tglo2;
    return tglo;
}

string new_label()       //创建一个新的label i
{
    static int count = 0;
    count++;
    char c[100];
    sprintf(c, "%d", count);
    string j(c);
    string lglo1= "label";
    string lglo2= j;
    string lglo = lglo1+lglo2;
    return lglo;
}

typedef struct               //定义有一个label结构体，存储if、else信息
{
    string   name;
    int      times;
    string   label; 
}Label;

std::vector<Label> LabelVector ;    //定义一个label的vector
std::vector<Label> *PLabel ;        //labelvector的指针


 void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;
 void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;

 void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override;
 void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override;

  void enterFuncType(CACTParser::FuncTypeContext * /*ctx*/) override;
  void exitFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }

   void enterFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override { }
   void exitFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override { }

   void enterFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }
   void exitFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }

   void enterBlock(CACTParser::BlockContext * /*ctx*/) override;
   void exitBlock(CACTParser::BlockContext * /*ctx*/) override;

   void enterBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }
   void exitBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }

   //void enterStmt(CACTParser::StmtContext * /*ctx*/) override { }
   //void exitStmt(CACTParser::StmtContext * /*ctx*/) override { }

   void enterFirstStmt(CACTParser::FirstStmtContext * /*ctx*/) override{ }
   void exitFirstStmt(CACTParser::FirstStmtContext * /*ctx*/) override;

   void enterSecondStmt(CACTParser::SecondStmtContext * /*ctx*/) override { }
   void exitSecondStmt(CACTParser::SecondStmtContext * /*ctx*/) override { }

   void enterThirdStmt(CACTParser::ThirdStmtContext * /*ctx*/) override;
   void exitThirdStmt(CACTParser::ThirdStmtContext * /*ctx*/) override  { }

   void enterFourthStmt(CACTParser::FourthStmtContext * /*ctx*/) override;
   void exitFourthStmt(CACTParser::FourthStmtContext * /*ctx*/) override;

   void enterFifthStmt(CACTParser::FifthStmtContext * /*ctx*/) override;
   void exitFifthStmt(CACTParser::FifthStmtContext * /*ctx*/) override;

   void enterSixthStmt(CACTParser::SixthStmtContext * /*ctx*/) override { }
   void exitSixthStmt(CACTParser::SixthStmtContext * /*ctx*/) override { }

   void enterSeventhStmt(CACTParser::SeventhStmtContext * /*ctx*/) override { }
   void exitSeventhStmt(CACTParser::SeventhStmtContext * /*ctx*/) override { }

   void enterEighthStmt(CACTParser::EighthStmtContext * /*ctx*/) override { }
   void exitEighthStmt(CACTParser::EighthStmtContext * /*ctx*/) override;



   void enterLVal(CACTParser::LValContext * /*ctx*/) override { }
   void exitLVal(CACTParser::LValContext * /*ctx*/) override;

   //void enterExp(CACTParser::ExpContext * /*ctx*/) override { }
   //void exitExp(CACTParser::ExpContext * /*ctx*/) override { }

    void enterFirstExp(CACTParser::FirstExpContext * /*ctx*/) override { }
    void exitFirstExp(CACTParser::FirstExpContext * /*ctx*/) override;

   void enterSecondExp(CACTParser::SecondExpContext * /*ctx*/) override { }
   void exitSecondExp(CACTParser::SecondExpContext * /*ctx*/) override;

   //void enterAddExp(CACTParser::AddExpContext * /*ctx*/) override { }
   //void exitAddExp(CACTParser::AddExpContext * /*ctx*/) override { }

   void enterFirstAddExp(CACTParser::FirstAddExpContext * /*ctx*/) override { }
   void exitFirstAddExp(CACTParser::FirstAddExpContext * /*ctx*/) override;

   void enterSecondAddExp(CACTParser::SecondAddExpContext * /*ctx*/) override { }
   void exitSecondAddExp(CACTParser::SecondAddExpContext * /*ctx*/) override ;

  // void enterMulExp(CACTParser::MulExpContext * /*ctx*/) override { }
  // void exitMulExp(CACTParser::MulExpContext * /*ctx*/) override { }

   void enterFirstMulExp(CACTParser::FirstMulExpContext * /*ctx*/) override{ }
   void exitFirstMulExp(CACTParser::FirstMulExpContext * /*ctx*/) override;

   void  enterSecondMulExp(CACTParser::SecondMulExpContext * /*ctx*/) override { }
   void exitSecondMulExp(CACTParser::SecondMulExpContext * /*ctx*/) override ;

  // void enterUnaryExp(CACTParser::UnaryExpContext * /*ctx*/) override { }
  // void exitUnaryExp(CACTParser::UnaryExpContext * /*ctx*/) override { }

   void enterFirstUnaryExp(CACTParser::FirstUnaryExpContext * /*ctx*/) override { }
   void exitFirstUnaryExp(CACTParser::FirstUnaryExpContext * /*ctx*/) override;

   void enterSecondUnaryExp(CACTParser::SecondUnaryExpContext * /*ctx*/) override { }
   void exitSecondUnaryExp(CACTParser::SecondUnaryExpContext * /*ctx*/) override;

   void enterThirdUnaryExp(CACTParser::ThirdUnaryExpContext * /*ctx*/) override { }
   void exitThirdUnaryExp(CACTParser::ThirdUnaryExpContext * /*ctx*/) override;

   //void enterPrimaryExp(CACTParser::PrimaryExpContext * /*ctx*/) override { }
   //void exitPrimaryExp(CACTParser::PrimaryExpContext * /*ctx*/) override { }

    void enterFirstPrimaryExp(CACTParser::FirstPrimaryExpContext * /*ctx*/) override { }
    void exitFirstPrimaryExp(CACTParser::FirstPrimaryExpContext * /*ctx*/) override;

  void enterSecondPrimaryExp(CACTParser::SecondPrimaryExpContext * /*ctx*/) override { }
   void exitSecondPrimaryExp(CACTParser::SecondPrimaryExpContext * /*ctx*/) override;

   void enterThirdPrimaryExp(CACTParser::ThirdPrimaryExpContext * /*ctx*/) override { }
   void exitThirdPrimaryExp(CACTParser::ThirdPrimaryExpContext * /*ctx*/) override;

   void enterUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }
   void exitUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }

   void enterCond(CACTParser::CondContext * /*ctx*/) override { }
   void exitCond(CACTParser::CondContext * /*ctx*/) override;

   //void enterLOrExp(CACTParser::LOrExpContext * /*ctx*/) override { }
   //void exitLOrExp(CACTParser::LOrExpContext * /*ctx*/) override;

   void enterFirstlOrExp(CACTParser::FirstlOrExpContext * /*ctx*/) override { }
   void exitFirstlOrExp(CACTParser::FirstlOrExpContext * /*ctx*/) override;

   void enterSecondlOrExp(CACTParser::SecondlOrExpContext * /*ctx*/) override { }
   void exitSecondlOrExp(CACTParser::SecondlOrExpContext * /*ctx*/) override { }

   void enterFirstlAndExp(CACTParser::FirstlAndExpContext * /*ctx*/) override { }
   void exitFirstlAndExp(CACTParser::FirstlAndExpContext * /*ctx*/) override;

   void enterSecondlAndExp(CACTParser::SecondlAndExpContext * /*ctx*/) override { }
  void exitSecondlAndExp(CACTParser::SecondlAndExpContext * /*ctx*/) override { }

   //void enterLAndExp(CACTParser::LAndExpContext * /*ctx*/) override { }
   //void exitLAndExp(CACTParser::LAndExpContext * /*ctx*/) override;

   //void enterEqExp(CACTParser::EqExpContext * /*ctx*/) override { }
   //void exitEqExp(CACTParser::EqExpContext * /*ctx*/) override;

    void enterFirstEqExp(CACTParser::FirstEqExpContext * /*ctx*/) override { }
    void exitFirstEqExp(CACTParser::FirstEqExpContext * /*ctx*/) override;

   void enterSecondEqExp(CACTParser::SecondEqExpContext * /*ctx*/) override { }
   void exitSecondEqExp(CACTParser::SecondEqExpContext * /*ctx*/) override;

   //void enterRelExp(CACTParser::RelExpContext * /*ctx*/) override { }
   //void exitRelExp(CACTParser::RelExpContext * /*ctx*/) override;

   void enterSecondRelExp(CACTParser::SecondRelExpContext * /*ctx*/) override { }
   void exitSecondRelExp(CACTParser::SecondRelExpContext * /*ctx*/) override;

   void enterFirstRelExp(CACTParser::FirstRelExpContext * /*ctx*/) override { }
   void exitFirstRelExp(CACTParser::FirstRelExpContext * /*ctx*/) override;

   void enterThirdRelExp(CACTParser::ThirdRelExpContext * /*ctx*/) override { }
   void exitThirdRelExp(CACTParser::ThirdRelExpContext * /*ctx*/) override;

   void enterFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }
   void exitFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }

   void enterDecl(CACTParser::DeclContext * /*ctx*/) override { }
  void exitDecl(CACTParser::DeclContext * /*ctx*/) override;

  void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;
  void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;

   void enterBType(CACTParser::BTypeContext * /*ctx*/) override;
   void exitBType(CACTParser::BTypeContext * /*ctx*/) override { }

    void enterConstDef(CACTParser::ConstDefContext * /*ctx*/) override;
    void exitConstDef(CACTParser::ConstDefContext * /*ctx*/) override;

  // void enterConstInitVal(CACTParser::ConstInitValContext * /*ctx*/) override { }
  // void exitConstInitVal(CACTParser::ConstInitValContext * /*ctx*/) override { }

  void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;
  void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;

   void enterScalarVarDef(CACTParser::ScalarVarDefContext * /*ctx*/) override { }
   void exitScalarVarDef(CACTParser::ScalarVarDefContext * /*ctx*/) override ;

   void enterArrayVarDef(CACTParser::ArrayVarDefContext * /*ctx*/) override;
   void exitArrayVarDef(CACTParser::ArrayVarDefContext * /*ctx*/) override;

   void enterConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override { }
   void exitConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override;

   void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }
   void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }

   void enterNumber(CACTParser::NumberContext * /*ctx*/) override { }
   void exitNumber(CACTParser::NumberContext * /*ctx*/) override ;

   void enterFirstConstInitVal(CACTParser::FirstConstInitValContext * /*ctx*/) override { }
   void exitFirstConstInitVal(CACTParser::FirstConstInitValContext * /*ctx*/) override;

   void enterSecondConstInitVal(CACTParser::SecondConstInitValContext * /*ctx*/) override { }
   void exitSecondConstInitVal(CACTParser::SecondConstInitValContext * /*ctx*/) override { }

    void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }

    void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
    void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

    void enterCactElse(CACTParser::CactElseContext * /*ctx*/) override;
    void exitCactElse(CACTParser::CactElseContext * /*ctx*/) override;

    
};
