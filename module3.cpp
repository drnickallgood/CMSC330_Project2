#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include <sstream>
#include <fstream>

SymbolTable symbolTable;

void parseAssignments(stringstream &in);

int main()
{
    const int SIZE = 256;
    Expression* expression;
    char paren, comma, line[SIZE];

    ifstream fin("input.txt");
    //fin.open("input.txt");

    // Read file
    while(true) {

        symbolTable.init();

        // gets a line from teh file no bigger than SIZE
        fin.getline(line, SIZE);

        if(!fin) {

            break;
        }

        // converts the line into a stringstream so we can do things to it later as a string
        stringstream in(line, ios_base::in);

        // like removing parens
        in >> paren;
        cout << line << " ";
        expression = SubExpression::parse(in);
        in >> comma;
        parseAssignments(in);
        int result = expression->evaluate();
        cout << "Value = " << result << endl;


    }

    /*
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

     */
    return 0;
}

void parseAssignments(stringstream &in)
{
    char assignop, delimiter, junk;
    string variable;
    int value;
    // Clear out the symbol table

    symbolTable.init();
    do
    {
        variable = parseName(in);
         in >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}

