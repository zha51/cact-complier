grammar CACT;

// The language generated
options {
    language = Cpp;
}

@header {
    #include <vector>
    #include <string>
}

/********** Parser **********/
compUnit     
    : (decl | funcDef)+ EOF
    ;

funcDef 
    : funcType Ident '(' (funcFParams)? ')' block;

funcType  
locals[
        int funtype
    ]

    : 'void' | 'int' | 'float' | 'double' | 'bool'
    ;

funcFParams
    : funcFParam (',' funcFParam)*
    ;

funcFParam 
    : bType Ident ('[' ']')?
    ;

block 
    : LeftBrace (blockItem)* RightBrace
    ;

blockItem 
    : decl 
    | stmt
    ;
stmt 
    : lVal '=' exp ';'                           #firstStmt
    | (exp)? ';'                                 #secondStmt
    | block                                      #thirdStmt
    | 'if' '(' cond ')' stmt ('else' stmt )?     #fourthStmt
    | 'while' '(' cond ')' stmt                  #fifthStmt
    | 'break' ';'                                #sixthStmt
    | 'continue' ';'                             #seventhStmt
    | 'return' (exp)? ';'                        #eighthStmt
    ;

lVal
locals[
    int     size,
    int  type,
    bool is_array
]
    :Ident (LeftBracket exp RightBracket)?
    ;

exp
locals[
    int     size,
    int  type,
    bool is_array,
    int returnNumber
]
    : addExp                          #firstExp
    | BoolConst                       #secondExp
    ;

addExp 
locals[
    int     size,
    int  type,
    bool is_array,
    int returnNumber,
    int boolType
]
    : mulExp                          #firstAddExp
    | addExp ('+'|'-') mulExp         #secondAddExp
    ;

mulExp
locals[
    int     size,
    int  type,
    bool is_array,
    int returnNumber,
    int boolType
]
    :unaryExp                                #firstMulExp
    | mulExp ('*' | Divide | '%') unaryExp   #secondMulExp
    ;

unaryExp
locals[
   int     size,
    int  type,
    bool is_array,
    int returnNumber,
    int boolType
]
    : primaryExp                     #firstUnaryExp
    | Ident '(' (funcRParams)? ')'   #secondUnaryExp
    | unaryOp unaryExp               #thirdUnaryExp
    ;

primaryExp 
locals[
    int     size,
    int  type,
    bool is_array
]
    :'('exp')'                       #firstPrimaryExp
    | lVal                           #secondPrimaryExp
    | number                         #thirdPrimaryExp
    ;

unaryOp 
    :'+' 
    |'-' 
    |'!'
    ;

cond
locals[
        int boolType
    ]
    :lOrExp
    ;

lOrExp
locals[
        int boolType
    ]
    : lAndExp 
    | lOrExp '||' lAndExp
    ;

lAndExp
locals[
        int boolType
    ]
    :eqExp 
    | lAndExp '&&' eqExp
    ;

eqExp
locals[
    int boolType,
    int     size,
    int  type,
    bool is_array
    ]
    :relExp                                  #firstEqExp
    | eqExp ('==' | '!=') relExp             #secondEqExp
    ;

relExp
locals[
    int boolType,
    int    size,
    int  type,
    bool is_array
    ]
    : addExp                                     #firstRelExp       
    | relExp ('<' | '>' | '<=' | '>=') addExp    #secondRelExp 
    | BoolConst                                  #thirdRelExp   
    ;

funcRParams  
    :exp ( ',' exp )*
    ;



decl
    : constDecl
    | varDecl
    ;

constDecl
    : 'const' bType constDef (',' constDef)* ';'
    ;

bType
locals[
        int basicType
    ]
    : 'int'
    | 'float'
    | 'double'
    | 'bool'
    ;

constDef
    : Ident ( LeftBracket IntConst RightBracket )? '=' constInitVal
    ;

constInitVal
    locals[
        int basic_or_array_and_type
    ]
    : constExp                      # firstConstInitVal
    | LeftBrace ( constExp ( ',' constExp )* )? RightBrace    # secondConstInitVal
    ;

varDecl
    locals[
        int declType
    ]
    : bType varDef (',' varDef)* ';'
    ;

varDef
    locals[
        int declType
    ]
    : Ident ( LeftBracket IntConst RightBracket )?                       # scalarVarDef
    | Ident ( LeftBracket IntConst RightBracket )? '=' constInitVal      # arrayVarDef
    ;

constExp
    locals[
        int basic_or_array_and_type,
    ]
    : number            #constExpNumber
    | BoolConst         #constExpBoolConst
    ;

number
locals[
    int     size,
    int  type,
    bool is_array
]
    : IntConst
    | DoubleConst 
    | FloatConst
    ;



/********** Lexer **********/
BoolConst : 'true' | 'false';

LeftBracket : '[' ;
RightBracket : ']';
LeftBrace : '{';
RightBrace : '}';
Divide : '/';

Ident
    : IdentNondigit [a-zA-Z_0-9]*
    ;

fragment
IdentNondigit
    : [a-zA-Z_]
    ;

fragment
Digit
    : [0-9]
    ;

IntConst
    : DecimalConst 
    | OctalConst
    | HexadecimalConst
    ;

fragment
DecimalConst
    : '0'
    | NonzeroDigit (Digit)*
    ;

fragment
OctalConst
    : '0' OE 
    ;

fragment
OE 
    :OctalDigit OE
    |
    ;
fragment
HexadecimalConst
    :  HexadecimalPrefix HexadecimalDigit OF
    ;

fragment
OF
    :HexadecimalDigit OF 
    |
    ;
    
DoubleConst 
    : FractionalConstant (ExponentPart)?
    | DigitSequence ExponentPart
    ;

FloatConst 
    : FractionalConstant (ExponentPart)? FloatingSuffix
    | DigitSequence ExponentPart FloatingSuffix
    ;


fragment
FractionalConstant 
    :(DigitSequence )?'.' DigitSequence
    | DigitSequence '.'
    ;

fragment
ExponentPart
    : 'e' (Sign)? DigitSequence
    | 'E' (Sign)? DigitSequence
    ;

fragment
Sign 
    : '+' 
    | '-'
    ;

fragment
DigitSequence 
    :Digit+
    ;

fragment
FloatingSuffix
    :'f' 
    |'F'
    ;

fragment
NonzeroDigit
    : [1-9]
    ;

fragment
OctalDigit
    : [0-7]
    ;

fragment
HexadecimalPrefix
    : '0x'
    | '0X'
    ;

fragment
HexadecimalDigit
    : [0-9a-fA-F]
    ;

NewLine
    : ('\r' '\n'? | '\n') 
      -> skip
    ;

WhiteSpace
    : [ \t]+ 
      -> skip
    ;

BlockComment
    : '/*' .*? '*/'
      -> skip
    ;

LineComment
    : '//' ~[\r\n]*
      -> skip
    ;