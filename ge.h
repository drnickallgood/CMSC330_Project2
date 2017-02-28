class Ge: public SubExpression
{
public:
    Ge(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
    double evaluate()
    {
        // cin.peek() is = ?
        if(left->evaluate() > right->evaluate()) {

            return 1;
        }

        return 0;
    }
};