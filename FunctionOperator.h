#ifndef FUNCTION_OPERATOR_H
#define FUNCTION_OPERATOR_H

#include "Token.h"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

class FunctionOperator : public Token {

public:
	FunctionOperator() : Token(2) {}
	FunctionOperator(string inputFunction) : Token(2) {
		str = inputFunction;
	}

	void print() {
		std::cout << str;
	}
	double calculate(Operand input) {
		if (str == "sin" || str == "sine"){ return }

	}
private:
	string str;
};

/*
STRING POSSIBLE OPTIONS:
	sin   sine    cos    cosine    tan    tangent    sec   secant    csc    cosecant    cot    cotangent
	arcsin    arcsine
	potato



*/
#endif