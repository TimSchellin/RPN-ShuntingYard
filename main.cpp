#include "Operand.h"
#include "Operator.h"
#include "Stack.h"
#include "Queue.h"
#include "ShuntingYard.h"
#include "StringToQueue.h"
#include <iostream>

using namespace std;

//double evaluate(Queue<Token*> tokenQueue);
void pause();

int main() {
	Queue<Token*> infixQueue = convert("3.0*4.1+8.2");
	cout << "conversion successful\n";
	while (!infixQueue.empty()) {
		cout << "\n";
		infixQueue.pop()->print();
	}
}
	/*
	//sayHi();
	Operand n1(6.0);
	Operand n2(2.0);
	Operand n3(10.0);
	Operator o1('*');
	Operator o2('-');

	Queue <Token*> tokenQueue;

	tokenQueue.push(&n1);
	tokenQueue.push(&n2);
	tokenQueue.push(&n3);
	tokenQueue.push(&o1);
	tokenQueue.push(&o2);
	
	
	for (int i = 0; i < 5; i++) {
		cout << "\n";
		tokenQueue.pop()->print();
	}
	double result = evaluate(tokenQueue);
	cout << "\nresult: " << result << '\n';

	pause();
	return 0;
}

double evaluate(Queue<Token*> tokenQueue) {
	Stack <double> tokenStack;
	//int size = tokenQueue.getSize();

	while (!tokenQueue.empty()) {
		Token* token = tokenQueue.pop();
		//token->print();
		//cout << "\n";
		if (token->getType() == 1) {
			Operator* optr = static_cast<Operator*>(token);
			double left = tokenStack.pop();
			double right = tokenStack.pop();
			tokenStack.push(optr->calculate(left, right));
		}

		else if (token->getType() == 0) {
			tokenStack.push(token->getNum());
		}

		cout << "\ntop: " << tokenStack.top();

		/*
		//cout << "\n\nNEW LOOP:\n\n";
		Stack <double> stackCopy;
		stackCopy = tokenStack;
		cout << "\nstack size: " << stackCopy.getSize();
		while(!stackCopy.empty()) {
			cout << "\n\nSTACK: " << stackCopy.pop();
		}
		
	}
	return tokenStack.top();
}
*/
void pause() {
	int i;
	cin >> i;
}
/*
double evaluate(Token lhs, Token  rhs, Token optr) {
	assert(optr.getType() == 1); //make sure 1 is for operators, and not operands
	switch (optr.getSymbol()) {
	case '+':
		return(lhs.getNum() + rhs.getNum());
	case '-':
		return(lhs.getNum() - rhs.getNum());
	case '*':
		return(lhs.getNum() * rhs.getNum());
	case '/':
		return(lhs.getNum() / rhs.getNum());
	case '^':
		double result = lhs.getNum();
		for (int i = 0; i < rhs.getNum(); i++) {
			result *= result;
		}
		return result;
	}
}
*/