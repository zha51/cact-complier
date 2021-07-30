
    #include <vector>
    #include <string>


// Generated from CACT.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CACTListener.h"


/**
 * This class provides an empty implementation of CACTListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CACTBaseListener : public CACTListener {
public:

  virtual void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override { }
  virtual void exitFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override { }

  virtual void enterFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }
  virtual void exitFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }

  virtual void enterBlock(CACTParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(CACTParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(CACTParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterFirstStmt(CACTParser::FirstStmtContext * /*ctx*/) override { }
  virtual void exitFirstStmt(CACTParser::FirstStmtContext * /*ctx*/) override { }

  virtual void enterSecondStmt(CACTParser::SecondStmtContext * /*ctx*/) override { }
  virtual void exitSecondStmt(CACTParser::SecondStmtContext * /*ctx*/) override { }

  virtual void enterThirdStmt(CACTParser::ThirdStmtContext * /*ctx*/) override { }
  virtual void exitThirdStmt(CACTParser::ThirdStmtContext * /*ctx*/) override { }

  virtual void enterFourthStmt(CACTParser::FourthStmtContext * /*ctx*/) override { }
  virtual void exitFourthStmt(CACTParser::FourthStmtContext * /*ctx*/) override { }

  virtual void enterFifthStmt(CACTParser::FifthStmtContext * /*ctx*/) override { }
  virtual void exitFifthStmt(CACTParser::FifthStmtContext * /*ctx*/) override { }

  virtual void enterSixthStmt(CACTParser::SixthStmtContext * /*ctx*/) override { }
  virtual void exitSixthStmt(CACTParser::SixthStmtContext * /*ctx*/) override { }

  virtual void enterSeventhStmt(CACTParser::SeventhStmtContext * /*ctx*/) override { }
  virtual void exitSeventhStmt(CACTParser::SeventhStmtContext * /*ctx*/) override { }

  virtual void enterEighthStmt(CACTParser::EighthStmtContext * /*ctx*/) override { }
  virtual void exitEighthStmt(CACTParser::EighthStmtContext * /*ctx*/) override { }

  virtual void enterLVal(CACTParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(CACTParser::LValContext * /*ctx*/) override { }

  virtual void enterFirstExp(CACTParser::FirstExpContext * /*ctx*/) override { }
  virtual void exitFirstExp(CACTParser::FirstExpContext * /*ctx*/) override { }

  virtual void enterSecondExp(CACTParser::SecondExpContext * /*ctx*/) override { }
  virtual void exitSecondExp(CACTParser::SecondExpContext * /*ctx*/) override { }

  virtual void enterFirstAddExp(CACTParser::FirstAddExpContext * /*ctx*/) override { }
  virtual void exitFirstAddExp(CACTParser::FirstAddExpContext * /*ctx*/) override { }

  virtual void enterSecondAddExp(CACTParser::SecondAddExpContext * /*ctx*/) override { }
  virtual void exitSecondAddExp(CACTParser::SecondAddExpContext * /*ctx*/) override { }

  virtual void enterFirstMulExp(CACTParser::FirstMulExpContext * /*ctx*/) override { }
  virtual void exitFirstMulExp(CACTParser::FirstMulExpContext * /*ctx*/) override { }

  virtual void enterSecondMulExp(CACTParser::SecondMulExpContext * /*ctx*/) override { }
  virtual void exitSecondMulExp(CACTParser::SecondMulExpContext * /*ctx*/) override { }

  virtual void enterFirstUnaryExp(CACTParser::FirstUnaryExpContext * /*ctx*/) override { }
  virtual void exitFirstUnaryExp(CACTParser::FirstUnaryExpContext * /*ctx*/) override { }

  virtual void enterSecondUnaryExp(CACTParser::SecondUnaryExpContext * /*ctx*/) override { }
  virtual void exitSecondUnaryExp(CACTParser::SecondUnaryExpContext * /*ctx*/) override { }

  virtual void enterThirdUnaryExp(CACTParser::ThirdUnaryExpContext * /*ctx*/) override { }
  virtual void exitThirdUnaryExp(CACTParser::ThirdUnaryExpContext * /*ctx*/) override { }

  virtual void enterFirstPrimaryExp(CACTParser::FirstPrimaryExpContext * /*ctx*/) override { }
  virtual void exitFirstPrimaryExp(CACTParser::FirstPrimaryExpContext * /*ctx*/) override { }

  virtual void enterSecondPrimaryExp(CACTParser::SecondPrimaryExpContext * /*ctx*/) override { }
  virtual void exitSecondPrimaryExp(CACTParser::SecondPrimaryExpContext * /*ctx*/) override { }

  virtual void enterThirdPrimaryExp(CACTParser::ThirdPrimaryExpContext * /*ctx*/) override { }
  virtual void exitThirdPrimaryExp(CACTParser::ThirdPrimaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(CACTParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterCond(CACTParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(CACTParser::CondContext * /*ctx*/) override { }

  virtual void enterLOrExp(CACTParser::LOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExp(CACTParser::LOrExpContext * /*ctx*/) override { }

  virtual void enterLAndExp(CACTParser::LAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExp(CACTParser::LAndExpContext * /*ctx*/) override { }

  virtual void enterFirstEqExp(CACTParser::FirstEqExpContext * /*ctx*/) override { }
  virtual void exitFirstEqExp(CACTParser::FirstEqExpContext * /*ctx*/) override { }

  virtual void enterSecondEqExp(CACTParser::SecondEqExpContext * /*ctx*/) override { }
  virtual void exitSecondEqExp(CACTParser::SecondEqExpContext * /*ctx*/) override { }

  virtual void enterSecondRelExp(CACTParser::SecondRelExpContext * /*ctx*/) override { }
  virtual void exitSecondRelExp(CACTParser::SecondRelExpContext * /*ctx*/) override { }

  virtual void enterFirstRelExp(CACTParser::FirstRelExpContext * /*ctx*/) override { }
  virtual void exitFirstRelExp(CACTParser::FirstRelExpContext * /*ctx*/) override { }

  virtual void enterThirdRelExp(CACTParser::ThirdRelExpContext * /*ctx*/) override { }
  virtual void exitThirdRelExp(CACTParser::ThirdRelExpContext * /*ctx*/) override { }

  virtual void enterFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(CACTParser::FuncRParamsContext * /*ctx*/) override { }

  virtual void enterDecl(CACTParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(CACTParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterBType(CACTParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(CACTParser::BTypeContext * /*ctx*/) override { }

  virtual void enterConstDef(CACTParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(CACTParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterFirstConstInitVal(CACTParser::FirstConstInitValContext * /*ctx*/) override { }
  virtual void exitFirstConstInitVal(CACTParser::FirstConstInitValContext * /*ctx*/) override { }

  virtual void enterSecondConstInitVal(CACTParser::SecondConstInitValContext * /*ctx*/) override { }
  virtual void exitSecondConstInitVal(CACTParser::SecondConstInitValContext * /*ctx*/) override { }

  virtual void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterScalarVarDef(CACTParser::ScalarVarDefContext * /*ctx*/) override { }
  virtual void exitScalarVarDef(CACTParser::ScalarVarDefContext * /*ctx*/) override { }

  virtual void enterArrayVarDef(CACTParser::ArrayVarDefContext * /*ctx*/) override { }
  virtual void exitArrayVarDef(CACTParser::ArrayVarDefContext * /*ctx*/) override { }

  virtual void enterConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override { }
  virtual void exitConstExpNumber(CACTParser::ConstExpNumberContext * /*ctx*/) override { }

  virtual void enterConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }
  virtual void exitConstExpBoolConst(CACTParser::ConstExpBoolConstContext * /*ctx*/) override { }

  virtual void enterNumber(CACTParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(CACTParser::NumberContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

