#include <cctype>
#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(stringstream &in)
{
    char paren;
    int value;

    in >> ws;
    if (isdigit(cin.peek()))
    {
        in >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (cin.peek() == '(')
    {
        in >> paren;
        return SubExpression::parse(in);
    }
    else
        return new Variable(parseName());
    return 0;
}