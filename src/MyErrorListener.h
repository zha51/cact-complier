#include "antlr4-runtime.h"

class MyListener : public antlr4::BaseErrorListener {
	public:
		MyListener(){}
		~MyListener() {}
		
		void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line, size_t charPositionInLine, const std::string &msg, std::exception_ptr e)
        {
            printf("yudao  cuowu  le!!\n");
            exit(-1);
        }
};
