#ifndef STRINGTOQUEUE_H
#define STRINGTOQUEUE_H

#include "Queue.h"
#include "Stack.h"
#include "Token.h"
#include "Operand.h"
#include "Operator.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Queue<Token*>& convert(string inputString) {
	Queue<Token*> infixExpression;
	string doubleNum = "";

	for (int i = 0; i < inputString.size(); i++) {
		if(isdigit(inputString[i]) || inputString[i] == '.'){
			doubleNum.append(&inputString[i]);
		}
		else {
			if (doubleNum.size() > 0) {
				infixExpression.push(new Operand(stod(doubleNum)));
				doubleNum = "";
			}
			infixExpression.push(new Operator(inputString[i]));
		}
	}
	return infixExpression;
}

#endif