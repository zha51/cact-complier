
    #include <vector>
    #include <string>


// Generated from CACT.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CACTParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CACTParser.
 */
class  CACTListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompUnit(CACTParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(CACTParser::CompUnitContext *ctx) = 0;

  virtual void enterFuncDef(CACTParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(CACTParser::FuncDefContext *ctx) = 0;

  virtual void enterFuncType(CACTParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(CACTParser::FuncTypeContext *ctx) = 0;

  virtual void enterFuncFParams(CACTParser::FuncFParamsContext *ctx) = 0;
  virtual void exitFuncFParams(CACTParser::FuncFParamsContext *ctx) = 0;

  virtual void enterFuncFParam(CACTParser::FuncFParamContext *ctx) = 0;
  virtual void exitFuncFParam(CACTParser::FuncFParamContext *ctx) = 0;

  virtual void enterBlock(CACTParser::BlockContext *ctx) = 0;
  virtual void exitBlock(CACTParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(CACTParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(CACTParser::BlockItemContext *ctx) = 0;

  virtual void enterFirstStmt(CACTParser::FirstStmtContext *ctx) = 0;
  virtual void exitFirstStmt(CACTParser::FirstStmtContext *ctx) = 0;

  virtual void enterSecondStmt(CACTParser::SecondStmtContext *ctx) = 0;
  virtual void exitSecondStmt(CACTParser::SecondStmtContext *ctx) = 0;

  virtual void enterThirdStmt(CACTParser::ThirdStmtContext *ctx) = 0;
  virtual void exitThirdStmt(CACTParser::ThirdStmtContext *ctx) = 0;

  virtual void enterFourthStmt(CACTParser::FourthStmtContext *ctx) = 0;
  virtual void exitFourthStmt(CACTParser::FourthStmtContext *ctx) = 0;

  virtual void enterFifthStmt(CACTParser::FifthStmtContext *ctx) = 0;
  virtual void exitFifthStmt(CACTParser::FifthStmtContext *ctx) = 0;

  virtual void enterSixthStmt(CACTParser::SixthStmtContext *ctx) = 0;
  virtual void exitSixthStmt(CACTParser::SixthStmtContext *ctx) = 0;

  virtual void enterSeventhStmt(CACTParser::SeventhStmtContext *ctx) = 0;
  virtual void exitSeventhStmt(CACTParser::SeventhStmtContext *ctx) = 0;

  virtual void enterEighthStmt(CACTParser::EighthStmtContext *ctx) = 0;
  virtual void exitEighthStmt(CACTParser::EighthStmtContext *ctx) = 0;

  virtual void enterCactElse(CACTParser::CactElseContext *ctx) = 0;
  virtual void exitCactElse(CACTParser::CactElseContext *ctx) = 0;

  virtual void enterLVal(CACTParser::LValContext *ctx) = 0;
  virtual void exitLVal(CACTParser::LValContext *ctx) = 0;

  virtual void enterFirstExp(CACTParser::FirstExpContext *ctx) = 0;
  virtual void exitFirstExp(CACTParser::FirstExpContext *ctx) = 0;

  virtual void enterSecondExp(CACTParser::SecondExpContext *ctx) = 0;
  virtual void exitSecondExp(CACTParser::SecondExpContext *ctx) = 0;

  virtual void enterFirstAddExp(CACTParser::FirstAddExpContext *ctx) = 0;
  virtual void exitFirstAddExp(CACTParser::FirstAddExpContext *ctx) = 0;

  virtual void enterSecondAddExp(CACTParser::SecondAddExpContext *ctx) = 0;
  virtual void exitSecondAddExp(CACTParser::SecondAddExpContext *ctx) = 0;

  virtual void enterFirstMulExp(CACTParser::FirstMulExpContext *ctx) = 0;
  virtual void exitFirstMulExp(CACTParser::FirstMulExpContext *ctx) = 0;

  virtual void enterSecondMulExp(CACTParser::SecondMulExpContext *ctx) = 0;
  virtual void exitSecondMulExp(CACTParser::SecondMulExpContext *ctx) = 0;

  virtual void enterFirstUnaryExp(CACTParser::FirstUnaryExpContext *ctx) = 0;
  virtual void exitFirstUnaryExp(CACTParser::FirstUnaryExpContext *ctx) = 0;

  virtual void enterSecondUnaryExp(CACTParser::SecondUnaryExpContext *ctx) = 0;
  virtual void exitSecondUnaryExp(CACTParser::SecondUnaryExpContext *ctx) = 0;

  virtual void enterThirdUnaryExp(CACTParser::ThirdUnaryExpContext *ctx) = 0;
  virtual void exitThirdUnaryExp(CACTParser::ThirdUnaryExpContext *ctx) = 0;

  virtual void enterFirstPrimaryExp(CACTParser::FirstPrimaryExpContext *ctx) = 0;
  virtual void exitFirstPrimaryExp(CACTParser::FirstPrimaryExpContext *ctx) = 0;

  virtual void enterSecondPrimaryExp(CACTParser::SecondPrimaryExpContext *ctx) = 0;
  virtual void exitSecondPrimaryExp(CACTParser::SecondPrimaryExpContext *ctx) = 0;

  virtual void enterThirdPrimaryExp(CACTParser::ThirdPrimaryExpContext *ctx) = 0;
  virtual void exitThirdPrimaryExp(CACTParser::ThirdPrimaryExpContext *ctx) = 0;

  virtual void enterUnaryOp(CACTParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(CACTParser::UnaryOpContext *ctx) = 0;

  virtual void enterCond(CACTParser::CondContext *ctx) = 0;
  virtual void exitCond(CACTParser::CondContext *ctx) = 0;

  virtual void enterFirstlOrExp(CACTParser::FirstlOrExpContext *ctx) = 0;
  virtual void exitFirstlOrExp(CACTParser::FirstlOrExpContext *ctx) = 0;

  virtual void enterSecondlOrExp(CACTParser::SecondlOrExpContext *ctx) = 0;
  virtual void exitSecondlOrExp(CACTParser::SecondlOrExpContext *ctx) = 0;

  virtual void enterFirstlAndExp(CACTParser::FirstlAndExpContext *ctx) = 0;
  virtual void exitFirstlAndExp(CACTParser::FirstlAndExpContext *ctx) = 0;

  virtual void enterSecondlAndExp(CACTParser::SecondlAndExpContext *ctx) = 0;
  virtual void exitSecondlAndExp(CACTParser::SecondlAndExpContext *ctx) = 0;

  virtual void enterFirstEqExp(CACTParser::FirstEqExpContext *ctx) = 0;
  virtual void exitFirstEqExp(CACTParser::FirstEqExpContext *ctx) = 0;

  virtual void enterSecondEqExp(CACTParser::SecondEqExpContext *ctx) = 0;
  virtual void exitSecondEqExp(CACTParser::SecondEqExpContext *ctx) = 0;

  virtual void enterSecondRelExp(CACTParser::SecondRelExpContext *ctx) = 0;
  virtual void exitSecondRelExp(CACTParser::SecondRelExpContext *ctx) = 0;

  virtual void enterFirstRelExp(CACTParser::FirstRelExpContext *ctx) = 0;
  virtual void exitFirstRelExp(CACTParser::FirstRelExpContext *ctx) = 0;

  virtual void enterThirdRelExp(CACTParser::ThirdRelExpContext *ctx) = 0;
  virtual void exitThirdRelExp(CACTParser::ThirdRelExpContext *ctx) = 0;

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext *ctx) = 0;
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext *ctx) = 0;

  virtual void enterDecl(CACTParser::DeclContext *ctx) = 0;
  virtual void exitDecl(CACTParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(CACTParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(CACTParser::ConstDeclContext *ctx) = 0;

  virtual void enterBType(CACTParser::BTypeContext *ctx) = 0;
  virtual void exitBType(CACTParser::BTypeContext *ctx) = 0;

  virtual void enterConstDef(CACTParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(CACTParser::ConstDefContext *ctx) = 0;

  virtual void enterFirstConstInitVal(CACTParser::FirstConstInitValContext *ctx) = 0;
  virtual void exitFirstConstInitVal(CACTParser::FirstConstInitValContext *ctx) = 0;

  virtual void enterSecondConstInitVal(CACTParser::SecondConstInitValContext *ctx) = 0;
  virtual void exitSecondConstInitVal(CACTParser::SecondConstInitValContext *ctx) = 0;

  virtual void enterVarDecl(CACTParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(CACTParser::VarDeclContext *ctx) = 0;

  virtual void enterScalarVarDef(CACTParser::ScalarVarDefContext *ctx) = 0;
  virtual void exitScalarVarDef(CACTParser::ScalarVarDefContext *ctx) = 0;

  virtual void enterArrayVarDef(CACTParser::ArrayVarDefContext *ctx) = 0;
  virtual void exitArrayVarDef(CACTParser::ArrayVarDefContext *ctx) = 0;

  virtual void enterConstExpNumber(CACTParser::ConstExpNumberContext *ctx) = 0;
  virtual void exitConstExpNumber(CACTParser::ConstExpNumberContext *ctx) = 0;

  virtual void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext *ctx) = 0;
  virtual void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext *ctx) = 0;

  virtual void enterNumber(CACTParser::NumberContext *ctx) = 0;
  virtual void exitNumber(CACTParser::NumberContext *ctx) = 0;


};

