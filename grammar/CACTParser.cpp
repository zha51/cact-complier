
    #include <vector>
    #include <string>


// Generated from CACT.g4 by ANTLR 4.7.2


#include "CACTListener.h"

#include "CACTParser.h"


using namespace antlrcpp;
using namespace antlr4;

CACTParser::CACTParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CACTParser::~CACTParser() {
  delete _interpreter;
}

std::string CACTParser::getGrammarFileName() const {
  return "CACT.g4";
}

const std::vector<std::string>& CACTParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CACTParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

CACTParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::CompUnitContext::EOF() {
  return getToken(CACTParser::EOF, 0);
}

std::vector<CACTParser::DeclContext *> CACTParser::CompUnitContext::decl() {
  return getRuleContexts<CACTParser::DeclContext>();
}

CACTParser::DeclContext* CACTParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<CACTParser::DeclContext>(i);
}

std::vector<CACTParser::FuncDefContext *> CACTParser::CompUnitContext::funcDef() {
  return getRuleContexts<CACTParser::FuncDefContext>();
}

CACTParser::FuncDefContext* CACTParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<CACTParser::FuncDefContext>(i);
}


size_t CACTParser::CompUnitContext::getRuleIndex() const {
  return CACTParser::RuleCompUnit;
}

void CACTParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void CACTParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}

CACTParser::CompUnitContext* CACTParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CACTParser::RuleCompUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(64);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(62);
        decl();
        break;
      }

      case 2: {
        setState(63);
        funcDef();
        break;
      }

      }
      setState(66); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__22))) != 0));
    setState(68);
    match(CACTParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

CACTParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::FuncTypeContext* CACTParser::FuncDefContext::funcType() {
  return getRuleContext<CACTParser::FuncTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::BlockContext* CACTParser::FuncDefContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::FuncFParamsContext* CACTParser::FuncDefContext::funcFParams() {
  return getRuleContext<CACTParser::FuncFParamsContext>(0);
}


size_t CACTParser::FuncDefContext::getRuleIndex() const {
  return CACTParser::RuleFuncDef;
}

void CACTParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void CACTParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}

CACTParser::FuncDefContext* CACTParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 2, CACTParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    funcType();
    setState(71);
    match(CACTParser::Ident);
    setState(72);
    match(CACTParser::T__0);
    setState(74);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0)) {
      setState(73);
      funcFParams();
    }
    setState(76);
    match(CACTParser::T__1);
    setState(77);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

CACTParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::FuncTypeContext::getRuleIndex() const {
  return CACTParser::RuleFuncType;
}

void CACTParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void CACTParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}

CACTParser::FuncTypeContext* CACTParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 4, CACTParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

CACTParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::FuncFParamContext *> CACTParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<CACTParser::FuncFParamContext>();
}

CACTParser::FuncFParamContext* CACTParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<CACTParser::FuncFParamContext>(i);
}


size_t CACTParser::FuncFParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParams;
}

void CACTParser::FuncFParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParams(this);
}

void CACTParser::FuncFParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParams(this);
}

CACTParser::FuncFParamsContext* CACTParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 6, CACTParser::RuleFuncFParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    funcFParam();
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__7) {
      setState(82);
      match(CACTParser::T__7);
      setState(83);
      funcFParam();
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

CACTParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::FuncFParamContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::LeftBracket() {
  return getToken(CACTParser::LeftBracket, 0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::RightBracket() {
  return getToken(CACTParser::RightBracket, 0);
}


size_t CACTParser::FuncFParamContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParam;
}

void CACTParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void CACTParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
}

CACTParser::FuncFParamContext* CACTParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 8, CACTParser::RuleFuncFParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    bType();
    setState(90);
    match(CACTParser::Ident);
    setState(93);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::LeftBracket) {
      setState(91);
      match(CACTParser::LeftBracket);
      setState(92);
      match(CACTParser::RightBracket);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CACTParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::BlockContext::LeftBrace() {
  return getToken(CACTParser::LeftBrace, 0);
}

tree::TerminalNode* CACTParser::BlockContext::RightBrace() {
  return getToken(CACTParser::RightBrace, 0);
}

std::vector<CACTParser::BlockItemContext *> CACTParser::BlockContext::blockItem() {
  return getRuleContexts<CACTParser::BlockItemContext>();
}

CACTParser::BlockItemContext* CACTParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<CACTParser::BlockItemContext>(i);
}


size_t CACTParser::BlockContext::getRuleIndex() const {
  return CACTParser::RuleBlock;
}

void CACTParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void CACTParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

CACTParser::BlockContext* CACTParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(CACTParser::LeftBrace);
    setState(99);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__9)
      | (1ULL << CACTParser::T__10)
      | (1ULL << CACTParser::T__11)
      | (1ULL << CACTParser::T__12)
      | (1ULL << CACTParser::T__13)
      | (1ULL << CACTParser::T__14)
      | (1ULL << CACTParser::T__16)
      | (1ULL << CACTParser::T__22)
      | (1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::LeftBrace)
      | (1ULL << CACTParser::Add)
      | (1ULL << CACTParser::Sub)
      | (1ULL << CACTParser::Ident)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::DoubleConst)
      | (1ULL << CACTParser::FloatConst))) != 0)) {
      setState(96);
      blockItem();
      setState(101);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(102);
    match(CACTParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CACTParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::DeclContext* CACTParser::BlockItemContext::decl() {
  return getRuleContext<CACTParser::DeclContext>(0);
}

CACTParser::StmtContext* CACTParser::BlockItemContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::BlockItemContext::getRuleIndex() const {
  return CACTParser::RuleBlockItem;
}

void CACTParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void CACTParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}

CACTParser::BlockItemContext* CACTParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 12, CACTParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(106);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6:
      case CACTParser::T__22: {
        enterOuterAlt(_localctx, 1);
        setState(104);
        decl();
        break;
      }

      case CACTParser::T__0:
      case CACTParser::T__9:
      case CACTParser::T__10:
      case CACTParser::T__11:
      case CACTParser::T__12:
      case CACTParser::T__13:
      case CACTParser::T__14:
      case CACTParser::T__16:
      case CACTParser::BoolConst:
      case CACTParser::LeftBrace:
      case CACTParser::Add:
      case CACTParser::Sub:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::DoubleConst:
      case CACTParser::FloatConst: {
        enterOuterAlt(_localctx, 2);
        setState(105);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

CACTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::StmtContext::getRuleIndex() const {
  return CACTParser::RuleStmt;
}

void CACTParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FourthStmtContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::FourthStmtContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

std::vector<CACTParser::StmtContext *> CACTParser::FourthStmtContext::stmt() {
  return getRuleContexts<CACTParser::StmtContext>();
}

CACTParser::StmtContext* CACTParser::FourthStmtContext::stmt(size_t i) {
  return getRuleContext<CACTParser::StmtContext>(i);
}

CACTParser::CactElseContext* CACTParser::FourthStmtContext::cactElse() {
  return getRuleContext<CACTParser::CactElseContext>(0);
}

CACTParser::FourthStmtContext::FourthStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::FourthStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFourthStmt(this);
}
void CACTParser::FourthStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFourthStmt(this);
}
//----------------- FifthStmtContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::FifthStmtContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

CACTParser::StmtContext* CACTParser::FifthStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::FifthStmtContext::FifthStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::FifthStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFifthStmt(this);
}
void CACTParser::FifthStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFifthStmt(this);
}
//----------------- SeventhStmtContext ------------------------------------------------------------------

CACTParser::SeventhStmtContext::SeventhStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::SeventhStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSeventhStmt(this);
}
void CACTParser::SeventhStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSeventhStmt(this);
}
//----------------- ThirdStmtContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::ThirdStmtContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::ThirdStmtContext::ThirdStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::ThirdStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThirdStmt(this);
}
void CACTParser::ThirdStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThirdStmt(this);
}
//----------------- FirstStmtContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::FirstStmtContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::FirstStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::FirstStmtContext::FirstStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstStmt(this);
}
void CACTParser::FirstStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstStmt(this);
}
//----------------- SixthStmtContext ------------------------------------------------------------------

CACTParser::SixthStmtContext::SixthStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::SixthStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixthStmt(this);
}
void CACTParser::SixthStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixthStmt(this);
}
//----------------- EighthStmtContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::EighthStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::EighthStmtContext::EighthStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::EighthStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEighthStmt(this);
}
void CACTParser::EighthStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEighthStmt(this);
}
//----------------- SecondStmtContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::SecondStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::SecondStmtContext::SecondStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondStmt(this);
}
void CACTParser::SecondStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondStmt(this);
}
CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 14, CACTParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(143);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::FirstStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(108);
      lVal();
      setState(109);
      match(CACTParser::T__8);
      setState(110);
      exp();
      setState(111);
      match(CACTParser::T__9);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::SecondStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(114);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__0)
        | (1ULL << CACTParser::T__16)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Add)
        | (1ULL << CACTParser::Sub)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::DoubleConst)
        | (1ULL << CACTParser::FloatConst))) != 0)) {
        setState(113);
        exp();
      }
      setState(116);
      match(CACTParser::T__9);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::ThirdStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(117);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::FourthStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(118);
      match(CACTParser::T__10);
      setState(119);
      match(CACTParser::T__0);
      setState(120);
      cond();
      setState(121);
      match(CACTParser::T__1);
      setState(122);
      stmt();
      setState(126);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(123);
        cactElse();
        setState(124);
        stmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::FifthStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(128);
      match(CACTParser::T__11);
      setState(129);
      match(CACTParser::T__0);
      setState(130);
      cond();
      setState(131);
      match(CACTParser::T__1);
      setState(132);
      stmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::SixthStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(134);
      match(CACTParser::T__12);
      setState(135);
      match(CACTParser::T__9);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::SeventhStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(136);
      match(CACTParser::T__13);
      setState(137);
      match(CACTParser::T__9);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::EighthStmtContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(138);
      match(CACTParser::T__14);
      setState(140);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__0)
        | (1ULL << CACTParser::T__16)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Add)
        | (1ULL << CACTParser::Sub)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::DoubleConst)
        | (1ULL << CACTParser::FloatConst))) != 0)) {
        setState(139);
        exp();
      }
      setState(142);
      match(CACTParser::T__9);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CactElseContext ------------------------------------------------------------------

CACTParser::CactElseContext::CactElseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::CactElseContext::ELSE() {
  return getToken(CACTParser::ELSE, 0);
}


size_t CACTParser::CactElseContext::getRuleIndex() const {
  return CACTParser::RuleCactElse;
}

void CACTParser::CactElseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCactElse(this);
}

void CACTParser::CactElseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCactElse(this);
}

CACTParser::CactElseContext* CACTParser::cactElse() {
  CactElseContext *_localctx = _tracker.createInstance<CactElseContext>(_ctx, getState());
  enterRule(_localctx, 16, CACTParser::RuleCactElse);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(CACTParser::ELSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

CACTParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::LValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::LValContext::LeftBracket() {
  return getToken(CACTParser::LeftBracket, 0);
}

CACTParser::ExpContext* CACTParser::LValContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

tree::TerminalNode* CACTParser::LValContext::RightBracket() {
  return getToken(CACTParser::RightBracket, 0);
}


size_t CACTParser::LValContext::getRuleIndex() const {
  return CACTParser::RuleLVal;
}

void CACTParser::LValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLVal(this);
}

void CACTParser::LValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLVal(this);
}

CACTParser::LValContext* CACTParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 18, CACTParser::RuleLVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(CACTParser::Ident);
    setState(152);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(148);
      match(CACTParser::LeftBracket);
      setState(149);
      exp();
      setState(150);
      match(CACTParser::RightBracket);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

CACTParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ExpContext::getRuleIndex() const {
  return CACTParser::RuleExp;
}

void CACTParser::ExpContext::copyFrom(ExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->size = ctx->size;
  this->type = ctx->type;
  this->is_array = ctx->is_array;
  this->returnNumber = ctx->returnNumber;
}

//----------------- FirstExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::FirstExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::FirstExpContext::FirstExpContext(ExpContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstExp(this);
}
void CACTParser::FirstExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstExp(this);
}
//----------------- SecondExpContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::SecondExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::SecondExpContext::SecondExpContext(ExpContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondExp(this);
}
void CACTParser::SecondExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondExp(this);
}
CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 20, CACTParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__16:
      case CACTParser::Add:
      case CACTParser::Sub:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::DoubleConst:
      case CACTParser::FloatConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<CACTParser::FirstExpContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(154);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ExpContext *>(_tracker.createInstance<CACTParser::SecondExpContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(155);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::AddExpContext::getRuleIndex() const {
  return CACTParser::RuleAddExp;
}

void CACTParser::AddExpContext::copyFrom(AddExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->size = ctx->size;
  this->type = ctx->type;
  this->is_array = ctx->is_array;
  this->returnNumber = ctx->returnNumber;
  this->boolType = ctx->boolType;
  this->is_number = ctx->is_number;
}

//----------------- FirstAddExpContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::FirstAddExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::FirstAddExpContext::FirstAddExpContext(AddExpContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstAddExp(this);
}
void CACTParser::FirstAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstAddExp(this);
}
//----------------- SecondAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::SecondAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::MulExpContext* CACTParser::SecondAddExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

tree::TerminalNode* CACTParser::SecondAddExpContext::Add() {
  return getToken(CACTParser::Add, 0);
}

tree::TerminalNode* CACTParser::SecondAddExpContext::Sub() {
  return getToken(CACTParser::Sub, 0);
}

CACTParser::SecondAddExpContext::SecondAddExpContext(AddExpContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondAddExp(this);
}
void CACTParser::SecondAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondAddExp(this);
}

CACTParser::AddExpContext* CACTParser::addExp() {
   return addExp(0);
}

CACTParser::AddExpContext* CACTParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  CACTParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, CACTParser::RuleAddExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<FirstAddExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(159);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(166);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<SecondAddExpContext>(_tracker.createInstance<AddExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleAddExp);
        setState(161);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(162);
        _la = _input->LA(1);
        if (!(_la == CACTParser::Add

        || _la == CACTParser::Sub)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(163);
        mulExp(0); 
      }
      setState(168);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::MulExpContext::getRuleIndex() const {
  return CACTParser::RuleMulExp;
}

void CACTParser::MulExpContext::copyFrom(MulExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->size = ctx->size;
  this->type = ctx->type;
  this->is_array = ctx->is_array;
  this->returnNumber = ctx->returnNumber;
  this->boolType = ctx->boolType;
  this->is_number = ctx->is_number;
}

//----------------- FirstMulExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext* CACTParser::FirstMulExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::FirstMulExpContext::FirstMulExpContext(MulExpContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstMulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstMulExp(this);
}
void CACTParser::FirstMulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstMulExp(this);
}
//----------------- SecondMulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::SecondMulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::SecondMulExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

tree::TerminalNode* CACTParser::SecondMulExpContext::Mul() {
  return getToken(CACTParser::Mul, 0);
}

tree::TerminalNode* CACTParser::SecondMulExpContext::Divide() {
  return getToken(CACTParser::Divide, 0);
}

CACTParser::SecondMulExpContext::SecondMulExpContext(MulExpContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondMulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondMulExp(this);
}
void CACTParser::SecondMulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondMulExp(this);
}

CACTParser::MulExpContext* CACTParser::mulExp() {
   return mulExp(0);
}

CACTParser::MulExpContext* CACTParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  CACTParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, CACTParser::RuleMulExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<FirstMulExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(170);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(177);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<SecondMulExpContext>(_tracker.createInstance<MulExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleMulExp);
        setState(172);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(173);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::T__15)
          | (1ULL << CACTParser::Divide)
          | (1ULL << CACTParser::Mul))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(174);
        unaryExp(); 
      }
      setState(179);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryExpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryExp;
}

void CACTParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->size = ctx->size;
  this->type = ctx->type;
  this->is_array = ctx->is_array;
  this->returnNumber = ctx->returnNumber;
  this->boolType = ctx->boolType;
  this->is_number = ctx->is_number;
}

//----------------- FirstUnaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext* CACTParser::FirstUnaryExpContext::primaryExp() {
  return getRuleContext<CACTParser::PrimaryExpContext>(0);
}

CACTParser::FirstUnaryExpContext::FirstUnaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstUnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstUnaryExp(this);
}
void CACTParser::FirstUnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstUnaryExp(this);
}
//----------------- ThirdUnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext* CACTParser::ThirdUnaryExpContext::unaryOp() {
  return getRuleContext<CACTParser::UnaryOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::ThirdUnaryExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::ThirdUnaryExpContext::ThirdUnaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ThirdUnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThirdUnaryExp(this);
}
void CACTParser::ThirdUnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThirdUnaryExp(this);
}
//----------------- SecondUnaryExpContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::SecondUnaryExpContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncRParamsContext* CACTParser::SecondUnaryExpContext::funcRParams() {
  return getRuleContext<CACTParser::FuncRParamsContext>(0);
}

CACTParser::SecondUnaryExpContext::SecondUnaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondUnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondUnaryExp(this);
}
void CACTParser::SecondUnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondUnaryExp(this);
}
CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 26, CACTParser::RuleUnaryExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::FirstUnaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(180);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::SecondUnaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(181);
      match(CACTParser::Ident);
      setState(182);
      match(CACTParser::T__0);
      setState(184);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__0)
        | (1ULL << CACTParser::T__16)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Add)
        | (1ULL << CACTParser::Sub)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::DoubleConst)
        | (1ULL << CACTParser::FloatConst))) != 0)) {
        setState(183);
        funcRParams();
      }
      setState(186);
      match(CACTParser::T__1);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::ThirdUnaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(187);
      unaryOp();
      setState(188);
      unaryExp();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::PrimaryExpContext::getRuleIndex() const {
  return CACTParser::RulePrimaryExp;
}

void CACTParser::PrimaryExpContext::copyFrom(PrimaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->size = ctx->size;
  this->type = ctx->type;
  this->is_array = ctx->is_array;
  this->is_number = ctx->is_number;
}

//----------------- FirstPrimaryExpContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::FirstPrimaryExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::FirstPrimaryExpContext::FirstPrimaryExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstPrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstPrimaryExp(this);
}
void CACTParser::FirstPrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstPrimaryExp(this);
}
//----------------- SecondPrimaryExpContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::SecondPrimaryExpContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::SecondPrimaryExpContext::SecondPrimaryExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondPrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondPrimaryExp(this);
}
void CACTParser::SecondPrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondPrimaryExp(this);
}
//----------------- ThirdPrimaryExpContext ------------------------------------------------------------------

CACTParser::NumberContext* CACTParser::ThirdPrimaryExpContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

CACTParser::ThirdPrimaryExpContext::ThirdPrimaryExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ThirdPrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThirdPrimaryExp(this);
}
void CACTParser::ThirdPrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThirdPrimaryExp(this);
}
CACTParser::PrimaryExpContext* CACTParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(198);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::FirstPrimaryExpContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(192);
        match(CACTParser::T__0);
        setState(193);
        exp();
        setState(194);
        match(CACTParser::T__1);
        break;
      }

      case CACTParser::Ident: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::SecondPrimaryExpContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(196);
        lVal();
        break;
      }

      case CACTParser::IntConst:
      case CACTParser::DoubleConst:
      case CACTParser::FloatConst: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<CACTParser::ThirdPrimaryExpContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(197);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::UnaryOpContext::Add() {
  return getToken(CACTParser::Add, 0);
}

tree::TerminalNode* CACTParser::UnaryOpContext::Sub() {
  return getToken(CACTParser::Sub, 0);
}


size_t CACTParser::UnaryOpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryOp;
}

void CACTParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void CACTParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}

CACTParser::UnaryOpContext* CACTParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleUnaryOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__16)
      | (1ULL << CACTParser::Add)
      | (1ULL << CACTParser::Sub))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

CACTParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LOrExpContext* CACTParser::CondContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}


size_t CACTParser::CondContext::getRuleIndex() const {
  return CACTParser::RuleCond;
}

void CACTParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void CACTParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}

CACTParser::CondContext* CACTParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 32, CACTParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LOrExpContext::getRuleIndex() const {
  return CACTParser::RuleLOrExp;
}

void CACTParser::LOrExpContext::copyFrom(LOrExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->boolType = ctx->boolType;
}

//----------------- FirstlOrExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext* CACTParser::FirstlOrExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::FirstlOrExpContext::FirstlOrExpContext(LOrExpContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstlOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstlOrExp(this);
}
void CACTParser::FirstlOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstlOrExp(this);
}
//----------------- SecondlOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext* CACTParser::SecondlOrExpContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

CACTParser::LAndExpContext* CACTParser::SecondlOrExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::SecondlOrExpContext::SecondlOrExpContext(LOrExpContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondlOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondlOrExp(this);
}
void CACTParser::SecondlOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondlOrExp(this);
}

CACTParser::LOrExpContext* CACTParser::lOrExp() {
   return lOrExp(0);
}

CACTParser::LOrExpContext* CACTParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  CACTParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CACTParser::RuleLOrExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<FirstlOrExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(205);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(212);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<SecondlOrExpContext>(_tracker.createInstance<LOrExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLOrExp);
        setState(207);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(208);
        match(CACTParser::T__17);
        setState(209);
        lAndExp(0); 
      }
      setState(214);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LAndExpContext::getRuleIndex() const {
  return CACTParser::RuleLAndExp;
}

void CACTParser::LAndExpContext::copyFrom(LAndExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->boolType = ctx->boolType;
}

//----------------- FirstlAndExpContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::FirstlAndExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::FirstlAndExpContext::FirstlAndExpContext(LAndExpContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstlAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstlAndExp(this);
}
void CACTParser::FirstlAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstlAndExp(this);
}
//----------------- SecondlAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext* CACTParser::SecondlAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::EqExpContext* CACTParser::SecondlAndExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::SecondlAndExpContext::SecondlAndExpContext(LAndExpContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondlAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondlAndExp(this);
}
void CACTParser::SecondlAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondlAndExp(this);
}

CACTParser::LAndExpContext* CACTParser::lAndExp() {
   return lAndExp(0);
}

CACTParser::LAndExpContext* CACTParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  CACTParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, CACTParser::RuleLAndExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<FirstlAndExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(216);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(223);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<SecondlAndExpContext>(_tracker.createInstance<LAndExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLAndExp);
        setState(218);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(219);
        match(CACTParser::T__18);
        setState(220);
        eqExp(0); 
      }
      setState(225);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::EqExpContext::getRuleIndex() const {
  return CACTParser::RuleEqExp;
}

void CACTParser::EqExpContext::copyFrom(EqExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->boolType = ctx->boolType;
  this->size = ctx->size;
  this->type = ctx->type;
  this->is_array = ctx->is_array;
}

//----------------- FirstEqExpContext ------------------------------------------------------------------

CACTParser::RelExpContext* CACTParser::FirstEqExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::FirstEqExpContext::FirstEqExpContext(EqExpContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstEqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstEqExp(this);
}
void CACTParser::FirstEqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstEqExp(this);
}
//----------------- SecondEqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::SecondEqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::RelExpContext* CACTParser::SecondEqExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

tree::TerminalNode* CACTParser::SecondEqExpContext::Equal() {
  return getToken(CACTParser::Equal, 0);
}

tree::TerminalNode* CACTParser::SecondEqExpContext::NotEqual() {
  return getToken(CACTParser::NotEqual, 0);
}

CACTParser::SecondEqExpContext::SecondEqExpContext(EqExpContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondEqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondEqExp(this);
}
void CACTParser::SecondEqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondEqExp(this);
}

CACTParser::EqExpContext* CACTParser::eqExp() {
   return eqExp(0);
}

CACTParser::EqExpContext* CACTParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  CACTParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, CACTParser::RuleEqExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<FirstEqExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(227);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<SecondEqExpContext>(_tracker.createInstance<EqExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleEqExp);
        setState(229);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(230);
        _la = _input->LA(1);
        if (!(_la == CACTParser::Equal

        || _la == CACTParser::NotEqual)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(231);
        relExp(0); 
      }
      setState(236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RelExpContext::getRuleIndex() const {
  return CACTParser::RuleRelExp;
}

void CACTParser::RelExpContext::copyFrom(RelExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->boolType = ctx->boolType;
  this->size = ctx->size;
  this->type = ctx->type;
  this->is_array = ctx->is_array;
  this->is_number = ctx->is_number;
}

//----------------- SecondRelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext* CACTParser::SecondRelExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::AddExpContext* CACTParser::SecondRelExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::SecondRelExpContext::LESS() {
  return getToken(CACTParser::LESS, 0);
}

CACTParser::SecondRelExpContext::SecondRelExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondRelExp(this);
}
void CACTParser::SecondRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondRelExp(this);
}
//----------------- FirstRelExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::FirstRelExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::FirstRelExpContext::FirstRelExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstRelExp(this);
}
void CACTParser::FirstRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstRelExp(this);
}
//----------------- ThirdRelExpContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ThirdRelExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::ThirdRelExpContext::ThirdRelExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ThirdRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThirdRelExp(this);
}
void CACTParser::ThirdRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThirdRelExp(this);
}

CACTParser::RelExpContext* CACTParser::relExp() {
   return relExp(0);
}

CACTParser::RelExpContext* CACTParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  CACTParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, CACTParser::RuleRelExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(240);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__16:
      case CACTParser::Add:
      case CACTParser::Sub:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::DoubleConst:
      case CACTParser::FloatConst: {
        _localctx = _tracker.createInstance<FirstRelExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(238);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = _tracker.createInstance<ThirdRelExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(239);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(247);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<SecondRelExpContext>(_tracker.createInstance<RelExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleRelExp);
        setState(242);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(243);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::T__19)
          | (1ULL << CACTParser::T__20)
          | (1ULL << CACTParser::T__21)
          | (1ULL << CACTParser::LESS))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(244);
        addExp(0); 
      }
      setState(249);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

CACTParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ExpContext *> CACTParser::FuncRParamsContext::exp() {
  return getRuleContexts<CACTParser::ExpContext>();
}

CACTParser::ExpContext* CACTParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<CACTParser::ExpContext>(i);
}


size_t CACTParser::FuncRParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncRParams;
}

void CACTParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void CACTParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}

CACTParser::FuncRParamsContext* CACTParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 42, CACTParser::RuleFuncRParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    exp();
    setState(255);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__7) {
      setState(251);
      match(CACTParser::T__7);
      setState(252);
      exp();
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

CACTParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ConstDeclContext* CACTParser::DeclContext::constDecl() {
  return getRuleContext<CACTParser::ConstDeclContext>(0);
}

CACTParser::VarDeclContext* CACTParser::DeclContext::varDecl() {
  return getRuleContext<CACTParser::VarDeclContext>(0);
}


size_t CACTParser::DeclContext::getRuleIndex() const {
  return CACTParser::RuleDecl;
}

void CACTParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void CACTParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

CACTParser::DeclContext* CACTParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 44, CACTParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__22: {
        enterOuterAlt(_localctx, 1);
        setState(258);
        constDecl();
        break;
      }

      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(259);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

CACTParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::ConstDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::ConstDefContext *> CACTParser::ConstDeclContext::constDef() {
  return getRuleContexts<CACTParser::ConstDefContext>();
}

CACTParser::ConstDefContext* CACTParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<CACTParser::ConstDefContext>(i);
}


size_t CACTParser::ConstDeclContext::getRuleIndex() const {
  return CACTParser::RuleConstDecl;
}

void CACTParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void CACTParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}

CACTParser::ConstDeclContext* CACTParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 46, CACTParser::RuleConstDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(CACTParser::T__22);
    setState(263);
    bType();
    setState(264);
    constDef();
    setState(269);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__7) {
      setState(265);
      match(CACTParser::T__7);
      setState(266);
      constDef();
      setState(271);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(272);
    match(CACTParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

CACTParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::BTypeContext::getRuleIndex() const {
  return CACTParser::RuleBType;
}

void CACTParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void CACTParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}

CACTParser::BTypeContext* CACTParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 48, CACTParser::RuleBType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

CACTParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::ConstDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstInitValContext* CACTParser::ConstDefContext::constInitVal() {
  return getRuleContext<CACTParser::ConstInitValContext>(0);
}

tree::TerminalNode* CACTParser::ConstDefContext::LeftBracket() {
  return getToken(CACTParser::LeftBracket, 0);
}

tree::TerminalNode* CACTParser::ConstDefContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

tree::TerminalNode* CACTParser::ConstDefContext::RightBracket() {
  return getToken(CACTParser::RightBracket, 0);
}


size_t CACTParser::ConstDefContext::getRuleIndex() const {
  return CACTParser::RuleConstDef;
}

void CACTParser::ConstDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDef(this);
}

void CACTParser::ConstDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDef(this);
}

CACTParser::ConstDefContext* CACTParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 50, CACTParser::RuleConstDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    match(CACTParser::Ident);
    setState(280);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::LeftBracket) {
      setState(277);
      match(CACTParser::LeftBracket);
      setState(278);
      match(CACTParser::IntConst);
      setState(279);
      match(CACTParser::RightBracket);
    }
    setState(282);
    match(CACTParser::T__8);
    setState(283);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

CACTParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstInitValContext::getRuleIndex() const {
  return CACTParser::RuleConstInitVal;
}

void CACTParser::ConstInitValContext::copyFrom(ConstInitValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->basic_or_array_and_type = ctx->basic_or_array_and_type;
  this->is_number = ctx->is_number;
}

//----------------- FirstConstInitValContext ------------------------------------------------------------------

CACTParser::ConstExpContext* CACTParser::FirstConstInitValContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::FirstConstInitValContext::FirstConstInitValContext(ConstInitValContext *ctx) { copyFrom(ctx); }

void CACTParser::FirstConstInitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFirstConstInitVal(this);
}
void CACTParser::FirstConstInitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFirstConstInitVal(this);
}
//----------------- SecondConstInitValContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::SecondConstInitValContext::LeftBrace() {
  return getToken(CACTParser::LeftBrace, 0);
}

tree::TerminalNode* CACTParser::SecondConstInitValContext::RightBrace() {
  return getToken(CACTParser::RightBrace, 0);
}

std::vector<CACTParser::ConstExpContext *> CACTParser::SecondConstInitValContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::SecondConstInitValContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}

CACTParser::SecondConstInitValContext::SecondConstInitValContext(ConstInitValContext *ctx) { copyFrom(ctx); }

void CACTParser::SecondConstInitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSecondConstInitVal(this);
}
void CACTParser::SecondConstInitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSecondConstInitVal(this);
}
CACTParser::ConstInitValContext* CACTParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 52, CACTParser::RuleConstInitVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(298);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::BoolConst:
      case CACTParser::IntConst:
      case CACTParser::DoubleConst:
      case CACTParser::FloatConst: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<CACTParser::FirstConstInitValContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(285);
        constExp();
        break;
      }

      case CACTParser::LeftBrace: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<CACTParser::SecondConstInitValContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(286);
        match(CACTParser::LeftBrace);
        setState(295);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
          | (1ULL << CACTParser::IntConst)
          | (1ULL << CACTParser::DoubleConst)
          | (1ULL << CACTParser::FloatConst))) != 0)) {
          setState(287);
          constExp();
          setState(292);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CACTParser::T__7) {
            setState(288);
            match(CACTParser::T__7);
            setState(289);
            constExp();
            setState(294);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(297);
        match(CACTParser::RightBrace);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

CACTParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::VarDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::VarDefContext *> CACTParser::VarDeclContext::varDef() {
  return getRuleContexts<CACTParser::VarDefContext>();
}

CACTParser::VarDefContext* CACTParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<CACTParser::VarDefContext>(i);
}


size_t CACTParser::VarDeclContext::getRuleIndex() const {
  return CACTParser::RuleVarDecl;
}

void CACTParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void CACTParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

CACTParser::VarDeclContext* CACTParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 54, CACTParser::RuleVarDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(300);
    bType();
    setState(301);
    varDef();
    setState(306);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__7) {
      setState(302);
      match(CACTParser::T__7);
      setState(303);
      varDef();
      setState(308);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(309);
    match(CACTParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

CACTParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::VarDefContext::getRuleIndex() const {
  return CACTParser::RuleVarDef;
}

void CACTParser::VarDefContext::copyFrom(VarDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->declType = ctx->declType;
}

//----------------- ArrayVarDefContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ArrayVarDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstInitValContext* CACTParser::ArrayVarDefContext::constInitVal() {
  return getRuleContext<CACTParser::ConstInitValContext>(0);
}

tree::TerminalNode* CACTParser::ArrayVarDefContext::LeftBracket() {
  return getToken(CACTParser::LeftBracket, 0);
}

tree::TerminalNode* CACTParser::ArrayVarDefContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

tree::TerminalNode* CACTParser::ArrayVarDefContext::RightBracket() {
  return getToken(CACTParser::RightBracket, 0);
}

CACTParser::ArrayVarDefContext::ArrayVarDefContext(VarDefContext *ctx) { copyFrom(ctx); }

void CACTParser::ArrayVarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayVarDef(this);
}
void CACTParser::ArrayVarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayVarDef(this);
}
//----------------- ScalarVarDefContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ScalarVarDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::ScalarVarDefContext::LeftBracket() {
  return getToken(CACTParser::LeftBracket, 0);
}

tree::TerminalNode* CACTParser::ScalarVarDefContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

tree::TerminalNode* CACTParser::ScalarVarDefContext::RightBracket() {
  return getToken(CACTParser::RightBracket, 0);
}

CACTParser::ScalarVarDefContext::ScalarVarDefContext(VarDefContext *ctx) { copyFrom(ctx); }

void CACTParser::ScalarVarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScalarVarDef(this);
}
void CACTParser::ScalarVarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScalarVarDef(this);
}
CACTParser::VarDefContext* CACTParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 56, CACTParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::ScalarVarDefContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(311);
      match(CACTParser::Ident);
      setState(315);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::LeftBracket) {
        setState(312);
        match(CACTParser::LeftBracket);
        setState(313);
        match(CACTParser::IntConst);
        setState(314);
        match(CACTParser::RightBracket);
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::ArrayVarDefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(317);
      match(CACTParser::Ident);
      setState(321);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::LeftBracket) {
        setState(318);
        match(CACTParser::LeftBracket);
        setState(319);
        match(CACTParser::IntConst);
        setState(320);
        match(CACTParser::RightBracket);
      }
      setState(323);
      match(CACTParser::T__8);
      setState(324);
      constInitVal();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

CACTParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstExpContext::getRuleIndex() const {
  return CACTParser::RuleConstExp;
}

void CACTParser::ConstExpContext::copyFrom(ConstExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->basic_or_array_and_type = ctx->basic_or_array_and_type;
  this->is_number = ctx->is_number;
}

//----------------- ConstExpBoolConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstExpBoolConstContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::ConstExpBoolConstContext::ConstExpBoolConstContext(ConstExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstExpBoolConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpBoolConst(this);
}
void CACTParser::ConstExpBoolConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpBoolConst(this);
}
//----------------- ConstExpNumberContext ------------------------------------------------------------------

CACTParser::NumberContext* CACTParser::ConstExpNumberContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

CACTParser::ConstExpNumberContext::ConstExpNumberContext(ConstExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstExpNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpNumber(this);
}
void CACTParser::ConstExpNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpNumber(this);
}
CACTParser::ConstExpContext* CACTParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 58, CACTParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(329);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst:
      case CACTParser::DoubleConst:
      case CACTParser::FloatConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpNumberContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(327);
        number();
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpBoolConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(328);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

CACTParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::NumberContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

tree::TerminalNode* CACTParser::NumberContext::DoubleConst() {
  return getToken(CACTParser::DoubleConst, 0);
}

tree::TerminalNode* CACTParser::NumberContext::FloatConst() {
  return getToken(CACTParser::FloatConst, 0);
}


size_t CACTParser::NumberContext::getRuleIndex() const {
  return CACTParser::RuleNumber;
}

void CACTParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void CACTParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

CACTParser::NumberContext* CACTParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 60, CACTParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(331);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::DoubleConst)
      | (1ULL << CACTParser::FloatConst))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CACTParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return addExpSempred(dynamic_cast<AddExpContext *>(context), predicateIndex);
    case 12: return mulExpSempred(dynamic_cast<MulExpContext *>(context), predicateIndex);
    case 17: return lOrExpSempred(dynamic_cast<LOrExpContext *>(context), predicateIndex);
    case 18: return lAndExpSempred(dynamic_cast<LAndExpContext *>(context), predicateIndex);
    case 19: return eqExpSempred(dynamic_cast<EqExpContext *>(context), predicateIndex);
    case 20: return relExpSempred(dynamic_cast<RelExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CACTParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CACTParser::_decisionToDFA;
atn::PredictionContextCache CACTParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CACTParser::_atn;
std::vector<uint16_t> CACTParser::_serializedATN;

std::vector<std::string> CACTParser::_ruleNames = {
  "compUnit", "funcDef", "funcType", "funcFParams", "funcFParam", "block", 
  "blockItem", "stmt", "cactElse", "lVal", "exp", "addExp", "mulExp", "unaryExp", 
  "primaryExp", "unaryOp", "cond", "lOrExp", "lAndExp", "eqExp", "relExp", 
  "funcRParams", "decl", "constDecl", "bType", "constDef", "constInitVal", 
  "varDecl", "varDef", "constExp", "number"
};

std::vector<std::string> CACTParser::_literalNames = {
  "", "'('", "')'", "'void'", "'int'", "'float'", "'double'", "'bool'", 
  "','", "'='", "';'", "'if'", "'while'", "'break'", "'continue'", "'return'", 
  "'%'", "'!'", "'||'", "'&&'", "'>'", "'<='", "'>='", "'const'", "", "'['", 
  "']'", "'{'", "'}'", "'/'", "'+'", "'-'", "'*'", "'=='", "'!='", "'else'", 
  "'<'"
};

std::vector<std::string> CACTParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "BoolConst", "LeftBracket", "RightBracket", "LeftBrace", 
  "RightBrace", "Divide", "Add", "Sub", "Mul", "Equal", "NotEqual", "ELSE", 
  "LESS", "Ident", "IntConst", "DoubleConst", "FloatConst", "NewLine", "WhiteSpace", 
  "BlockComment", "LineComment"
};

dfa::Vocabulary CACTParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CACTParser::_tokenNames;

CACTParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2e, 0x150, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 
    0x43, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x44, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x4d, 0xa, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 
    0x5, 0x57, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x5a, 0xb, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x60, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0x64, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x67, 0xb, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6d, 0xa, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x75, 0xa, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x81, 0xa, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x8f, 0xa, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0x92, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x9b, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x9f, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0xa7, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xaa, 0xb, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 
    0xe, 0xb2, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xb5, 0xb, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xbb, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xc1, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xc9, 0xa, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xd5, 0xa, 0x13, 0xc, 
    0x13, 0xe, 0x13, 0xd8, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xe0, 0xa, 0x14, 0xc, 0x14, 0xe, 
    0x14, 0xe3, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x7, 0x15, 0xeb, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xee, 
    0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xf3, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xf8, 0xa, 0x16, 0xc, 0x16, 
    0xe, 0x16, 0xfb, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 
    0x100, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x103, 0xb, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x5, 0x18, 0x107, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x10e, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 
    0x111, 0xb, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x11b, 0xa, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x7, 0x1c, 0x125, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x128, 0xb, 
    0x1c, 0x5, 0x1c, 0x12a, 0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x12d, 0xa, 
    0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x133, 
    0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x136, 0xb, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x13e, 0xa, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x144, 0xa, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x148, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
    0x5, 0x1f, 0x14c, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x2, 0x8, 
    0x18, 0x1a, 0x24, 0x26, 0x28, 0x2a, 0x21, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
    0x3e, 0x2, 0xa, 0x3, 0x2, 0x5, 0x9, 0x3, 0x2, 0x20, 0x21, 0x5, 0x2, 
    0x12, 0x12, 0x1f, 0x1f, 0x22, 0x22, 0x4, 0x2, 0x13, 0x13, 0x20, 0x21, 
    0x3, 0x2, 0x23, 0x24, 0x4, 0x2, 0x16, 0x18, 0x26, 0x26, 0x3, 0x2, 0x6, 
    0x9, 0x3, 0x2, 0x28, 0x2a, 0x2, 0x15b, 0x2, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x48, 0x3, 0x2, 0x2, 0x2, 0x6, 0x51, 0x3, 0x2, 0x2, 0x2, 0x8, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x5b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x10, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x93, 0x3, 0x2, 0x2, 0x2, 0x14, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc8, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xca, 0x3, 0x2, 0x2, 0x2, 0x22, 0xcc, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xce, 0x3, 0x2, 0x2, 0x2, 0x26, 0xd9, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xf2, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x106, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x108, 0x3, 0x2, 0x2, 0x2, 0x32, 0x114, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x116, 0x3, 0x2, 0x2, 0x2, 0x36, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x38, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x147, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x14b, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x43, 0x5, 0x2e, 
    0x18, 0x2, 0x41, 0x43, 0x5, 0x4, 0x3, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x2, 0x2, 0x3, 0x47, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x5, 0x6, 0x4, 0x2, 0x49, 0x4a, 0x7, 
    0x27, 0x2, 0x2, 0x4a, 0x4c, 0x7, 0x3, 0x2, 0x2, 0x4b, 0x4d, 0x5, 0x8, 
    0x5, 0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x4, 0x2, 0x2, 
    0x4f, 0x50, 0x5, 0xc, 0x7, 0x2, 0x50, 0x5, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x52, 0x9, 0x2, 0x2, 0x2, 0x52, 0x7, 0x3, 0x2, 0x2, 0x2, 0x53, 0x58, 
    0x5, 0xa, 0x6, 0x2, 0x54, 0x55, 0x7, 0xa, 0x2, 0x2, 0x55, 0x57, 0x5, 
    0xa, 0x6, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x59, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x5c, 0x5, 0x32, 0x1a, 0x2, 0x5c, 0x5f, 0x7, 0x27, 0x2, 0x2, 0x5d, 
    0x5e, 0x7, 0x1b, 0x2, 0x2, 0x5e, 0x60, 0x7, 0x1c, 0x2, 0x2, 0x5f, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x61, 0x65, 0x7, 0x1d, 0x2, 0x2, 0x62, 0x64, 0x5, 0xe, 
    0x8, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x68, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x69, 0x7, 0x1e, 0x2, 0x2, 0x69, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6d, 
    0x5, 0x2e, 0x18, 0x2, 0x6b, 0x6d, 0x5, 0x10, 0x9, 0x2, 0x6c, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x6f, 0x5, 0x14, 0xb, 0x2, 0x6f, 0x70, 0x7, 0xb, 0x2, 
    0x2, 0x70, 0x71, 0x5, 0x16, 0xc, 0x2, 0x71, 0x72, 0x7, 0xc, 0x2, 0x2, 
    0x72, 0x92, 0x3, 0x2, 0x2, 0x2, 0x73, 0x75, 0x5, 0x16, 0xc, 0x2, 0x74, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x92, 0x7, 0xc, 0x2, 0x2, 0x77, 0x92, 0x5, 
    0xc, 0x7, 0x2, 0x78, 0x79, 0x7, 0xd, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x3, 
    0x2, 0x2, 0x7a, 0x7b, 0x5, 0x22, 0x12, 0x2, 0x7b, 0x7c, 0x7, 0x4, 0x2, 
    0x2, 0x7c, 0x80, 0x5, 0x10, 0x9, 0x2, 0x7d, 0x7e, 0x5, 0x12, 0xa, 0x2, 
    0x7e, 0x7f, 0x5, 0x10, 0x9, 0x2, 0x7f, 0x81, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 0xe, 0x2, 0x2, 0x83, 0x84, 0x7, 
    0x3, 0x2, 0x2, 0x84, 0x85, 0x5, 0x22, 0x12, 0x2, 0x85, 0x86, 0x7, 0x4, 
    0x2, 0x2, 0x86, 0x87, 0x5, 0x10, 0x9, 0x2, 0x87, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x88, 0x89, 0x7, 0xf, 0x2, 0x2, 0x89, 0x92, 0x7, 0xc, 0x2, 0x2, 
    0x8a, 0x8b, 0x7, 0x10, 0x2, 0x2, 0x8b, 0x92, 0x7, 0xc, 0x2, 0x2, 0x8c, 
    0x8e, 0x7, 0x11, 0x2, 0x2, 0x8d, 0x8f, 0x5, 0x16, 0xc, 0x2, 0x8e, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x92, 0x7, 0xc, 0x2, 0x2, 0x91, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x91, 0x74, 0x3, 0x2, 0x2, 0x2, 0x91, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x91, 0x78, 0x3, 0x2, 0x2, 0x2, 0x91, 0x82, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x88, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x91, 
    0x8c, 0x3, 0x2, 0x2, 0x2, 0x92, 0x11, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 
    0x7, 0x25, 0x2, 0x2, 0x94, 0x13, 0x3, 0x2, 0x2, 0x2, 0x95, 0x9a, 0x7, 
    0x27, 0x2, 0x2, 0x96, 0x97, 0x7, 0x1b, 0x2, 0x2, 0x97, 0x98, 0x5, 0x16, 
    0xc, 0x2, 0x98, 0x99, 0x7, 0x1c, 0x2, 0x2, 0x99, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x96, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0x9b, 0x15, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9f, 0x5, 0x18, 0xd, 0x2, 0x9d, 
    0x9f, 0x7, 0x1a, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x8, 
    0xd, 0x1, 0x2, 0xa1, 0xa2, 0x5, 0x1a, 0xe, 0x2, 0xa2, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xa3, 0xa4, 0xc, 0x3, 0x2, 0x2, 0xa4, 0xa5, 0x9, 0x3, 0x2, 
    0x2, 0xa5, 0xa7, 0x5, 0x1a, 0xe, 0x2, 0xa6, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0xa7, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0x19, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x8, 0xe, 0x1, 0x2, 0xac, 0xad, 0x5, 
    0x1c, 0xf, 0x2, 0xad, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0xc, 0x3, 
    0x2, 0x2, 0xaf, 0xb0, 0x9, 0x4, 0x2, 0x2, 0xb0, 0xb2, 0x5, 0x1c, 0xf, 
    0x2, 0xb1, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xc1, 
    0x5, 0x1e, 0x10, 0x2, 0xb7, 0xb8, 0x7, 0x27, 0x2, 0x2, 0xb8, 0xba, 0x7, 
    0x3, 0x2, 0x2, 0xb9, 0xbb, 0x5, 0x2c, 0x17, 0x2, 0xba, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0xbc, 0xc1, 0x7, 0x4, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x20, 0x11, 0x2, 
    0xbe, 0xbf, 0x5, 0x1c, 0xf, 0x2, 0xbf, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xb6, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x7, 
    0x3, 0x2, 0x2, 0xc3, 0xc4, 0x5, 0x16, 0xc, 0x2, 0xc4, 0xc5, 0x7, 0x4, 
    0x2, 0x2, 0xc5, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc9, 0x5, 0x14, 0xb, 
    0x2, 0xc7, 0xc9, 0x5, 0x3e, 0x20, 0x2, 0xc8, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x9, 0x5, 0x2, 0x2, 0xcb, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x24, 0x13, 0x2, 0xcd, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0xcf, 0x8, 0x13, 0x1, 0x2, 0xcf, 0xd0, 0x5, 0x26, 
    0x14, 0x2, 0xd0, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0xc, 0x3, 0x2, 
    0x2, 0xd2, 0xd3, 0x7, 0x14, 0x2, 0x2, 0xd3, 0xd5, 0x5, 0x26, 0x14, 0x2, 
    0xd4, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd6, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x8, 
    0x14, 0x1, 0x2, 0xda, 0xdb, 0x5, 0x28, 0x15, 0x2, 0xdb, 0xe1, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0xdd, 0xc, 0x3, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x15, 0x2, 
    0x2, 0xde, 0xe0, 0x5, 0x28, 0x15, 0x2, 0xdf, 0xdc, 0x3, 0x2, 0x2, 0x2, 
    0xe0, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0x27, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 
    0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x8, 0x15, 0x1, 0x2, 0xe5, 0xe6, 0x5, 
    0x2a, 0x16, 0x2, 0xe6, 0xec, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0xc, 0x3, 
    0x2, 0x2, 0xe8, 0xe9, 0x9, 0x6, 0x2, 0x2, 0xe9, 0xeb, 0x5, 0x2a, 0x16, 
    0x2, 0xea, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 
    0x8, 0x16, 0x1, 0x2, 0xf0, 0xf3, 0x5, 0x18, 0xd, 0x2, 0xf1, 0xf3, 0x7, 
    0x1a, 0x2, 0x2, 0xf2, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xf3, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0xc, 0x4, 0x2, 
    0x2, 0xf5, 0xf6, 0x9, 0x7, 0x2, 0x2, 0xf6, 0xf8, 0x5, 0x18, 0xd, 0x2, 
    0xf7, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xf9, 
    0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x101, 0x5, 
    0x16, 0xc, 0x2, 0xfd, 0xfe, 0x7, 0xa, 0x2, 0x2, 0xfe, 0x100, 0x5, 0x16, 
    0xc, 0x2, 0xff, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x100, 0x103, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x102, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x104, 
    0x107, 0x5, 0x30, 0x19, 0x2, 0x105, 0x107, 0x5, 0x38, 0x1d, 0x2, 0x106, 
    0x104, 0x3, 0x2, 0x2, 0x2, 0x106, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x7, 0x19, 0x2, 0x2, 0x109, 
    0x10a, 0x5, 0x32, 0x1a, 0x2, 0x10a, 0x10f, 0x5, 0x34, 0x1b, 0x2, 0x10b, 
    0x10c, 0x7, 0xa, 0x2, 0x2, 0x10c, 0x10e, 0x5, 0x34, 0x1b, 0x2, 0x10d, 
    0x10b, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x111, 0x3, 0x2, 0x2, 0x2, 0x10f, 
    0x10d, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x3, 0x2, 0x2, 0x2, 0x110, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x112, 
    0x113, 0x7, 0xc, 0x2, 0x2, 0x113, 0x31, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 
    0x9, 0x8, 0x2, 0x2, 0x115, 0x33, 0x3, 0x2, 0x2, 0x2, 0x116, 0x11a, 0x7, 
    0x27, 0x2, 0x2, 0x117, 0x118, 0x7, 0x1b, 0x2, 0x2, 0x118, 0x119, 0x7, 
    0x28, 0x2, 0x2, 0x119, 0x11b, 0x7, 0x1c, 0x2, 0x2, 0x11a, 0x117, 0x3, 
    0x2, 0x2, 0x2, 0x11a, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 
    0x2, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0xb, 0x2, 0x2, 0x11d, 0x11e, 0x5, 
    0x36, 0x1c, 0x2, 0x11e, 0x35, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x12d, 0x5, 
    0x3c, 0x1f, 0x2, 0x120, 0x129, 0x7, 0x1d, 0x2, 0x2, 0x121, 0x126, 0x5, 
    0x3c, 0x1f, 0x2, 0x122, 0x123, 0x7, 0xa, 0x2, 0x2, 0x123, 0x125, 0x5, 
    0x3c, 0x1f, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x125, 0x128, 0x3, 
    0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x3, 
    0x2, 0x2, 0x2, 0x127, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x128, 0x126, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x121, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x12a, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12d, 0x7, 
    0x1e, 0x2, 0x2, 0x12c, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x120, 0x3, 
    0x2, 0x2, 0x2, 0x12d, 0x37, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x5, 0x32, 
    0x1a, 0x2, 0x12f, 0x134, 0x5, 0x3a, 0x1e, 0x2, 0x130, 0x131, 0x7, 0xa, 
    0x2, 0x2, 0x131, 0x133, 0x5, 0x3a, 0x1e, 0x2, 0x132, 0x130, 0x3, 0x2, 
    0x2, 0x2, 0x133, 0x136, 0x3, 0x2, 0x2, 0x2, 0x134, 0x132, 0x3, 0x2, 
    0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x137, 0x3, 0x2, 
    0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x7, 0xc, 
    0x2, 0x2, 0x138, 0x39, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13d, 0x7, 0x27, 
    0x2, 0x2, 0x13a, 0x13b, 0x7, 0x1b, 0x2, 0x2, 0x13b, 0x13c, 0x7, 0x28, 
    0x2, 0x2, 0x13c, 0x13e, 0x7, 0x1c, 0x2, 0x2, 0x13d, 0x13a, 0x3, 0x2, 
    0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x148, 0x3, 0x2, 
    0x2, 0x2, 0x13f, 0x143, 0x7, 0x27, 0x2, 0x2, 0x140, 0x141, 0x7, 0x1b, 
    0x2, 0x2, 0x141, 0x142, 0x7, 0x28, 0x2, 0x2, 0x142, 0x144, 0x7, 0x1c, 
    0x2, 0x2, 0x143, 0x140, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x3, 0x2, 
    0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x7, 0xb, 
    0x2, 0x2, 0x146, 0x148, 0x5, 0x36, 0x1c, 0x2, 0x147, 0x139, 0x3, 0x2, 
    0x2, 0x2, 0x147, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x148, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x149, 0x14c, 0x5, 0x3e, 0x20, 0x2, 0x14a, 0x14c, 0x7, 0x1a, 0x2, 
    0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14a, 0x3, 0x2, 0x2, 
    0x2, 0x14c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x9, 0x9, 0x2, 0x2, 
    0x14e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x25, 0x42, 0x44, 0x4c, 0x58, 0x5f, 
    0x65, 0x6c, 0x74, 0x80, 0x8e, 0x91, 0x9a, 0x9e, 0xa8, 0xb3, 0xba, 0xc0, 
    0xc8, 0xd6, 0xe1, 0xec, 0xf2, 0xf9, 0x101, 0x106, 0x10f, 0x11a, 0x126, 
    0x129, 0x12c, 0x134, 0x13d, 0x143, 0x147, 0x14b, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CACTParser::Initializer CACTParser::_init;
