#include <iostream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "ge.h"
#include "geq.h"
#include "le.h"
#include "leq.h"
#include "eq.h"
#include "not.h"
#include "and.h"
#include "or.h"
#include "tern.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse()
{
    Expression* left;
    Expression* right;
    char operation, paren, junk;
    
    left = Operand::parse();
    cin >> operation;
    right = Operand::parse();
    cin >> paren;
    switch (operation)
    {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
        case '>':
            if(cin.peek() == '=') {
                cin >> junk;    // get rid of =
                return new Geq(left, right);
            }
            else {
                return new Ge(left, right);
            }
        case '<':
            if(cin.peek() == '=') {
                cin >> junk;    // Get rid of  =
                return new Leq(left, right);
            }
            else {
                return new Le(left, right);
            }
        case '=':
            return new Eq(left, right);
        case '&':
            return new And(left, right);
        case '|':
            return new Or(left, right);
        case '!':
            return new Not(left, right);
    }
    return 0;
}
        