#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments();

int main()
{
    Expression* expression;
    char paren, comma;
    string program;
    string input = "";


    // Sample (( a + b) * c), a = 1 , b = 2, c = 3;
    // (1 : 2 ? a > b), a = 1, b = 2;
    cout << "Enter expression: ";

    //((x < y) & ((x + y) = 10)), x = 2, y = 8;

    // Get rid of leading paren
    cin >> paren;


    // This is what actually starts the expression tree.
    expression = SubExpression::parse();


    cin >> comma;  
    parseAssignments();
    cout << "Value = " << expression->evaluate() << endl;
    return 0;
}

void parseAssignments()
{
    char assignop, delimiter, junk;
    string variable;
    int value;
    // Clear out the symbol table

    symbolTable.init();
    do
    {
        variable = parseName();
         cin >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}

