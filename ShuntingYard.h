#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "Queue.h"
#include "Stack.h"
#include "Token.h"
#include "Operator.h"
#include <iostream>

Queue<Token*> shuntingYard(Queue<Token*> infixQueue) {
	
	Queue<Token*> postfixQueue;
	Stack<Operator*> operatorStack;
	while (!infixQueue.empty()) {

		Token* item = infixQueue.pop();
		if (item->getType() == 0) {
			postfixQueue.push(item);
		}
		else if (item->getType() == 1) {

			Operator* opItem = static_cast<Operator*>(item);
			if (opItem->getSymbol() == '(') {
				operatorStack.push(opItem);
			}
			else if (opItem->getSymbol() == ')') {
				while (operatorStack.top()->getSymbol() != '(') {
					postfixQueue.push(operatorStack.pop());
				}
				operatorStack.pop(); //remove left parenthesis
			}
			else if (!operatorStack.empty()) {
				while (operatorStack.top()->getPrecedence() <= opItem->getPrecedence()) {
					postfixQueue.push(operatorStack.pop());
				}
				operatorStack.push(opItem);
			}

		}
	}

	for (int i = 0; i < operatorStack.getSize(); i++) {
		postfixQueue.push(operatorStack.pop());
	}

	return postfixQueue;
}

#endif
