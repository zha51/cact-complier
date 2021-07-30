#include <iostream>

#include "antlr4-runtime.h"
#include "../grammar/CACTLexer.h"
#include "../grammar/CACTParser.h"
#include "../grammar/CACTBaseListener.h"
#include "MyErrorListener.h"

#include "semanticAnalysis.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    CACTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CACTParser parser(&tokens);

    
    // remove and add new error listeners
    MyListener err_listener;
    parser.removeErrorListeners();	// remove all error listeners
    parser.addErrorListener(&err_listener);	// add

    
    tree::ParseTree *tree = parser.compUnit();
    SemanticAnalysis listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    


    std::cout << "-------------------------Print AST:--------------------------" << std::endl;
    std::cout << tree->toStringTree(&parser) << std::endl;

}