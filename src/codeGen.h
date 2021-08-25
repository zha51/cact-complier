#pragma once

#include <stdio.h>
#include <vector>
#include <string>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include <stack>

using namespace std;

class CodeGen
{
private:
    /* data */
public:
    CodeGen(/* args */);
    ~CodeGen();
    CodeGen(vector<string> IRCode);

    vector<string> codeGenIRCode;

};

CodeGen::CodeGen(/* args */)
{
}

CodeGen::~CodeGen()
{
}



