class Or: public SubExpression
{
public:
    Or(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
    double evaluate()
    {
        if( (left->evaluate() || right->evaluate())) {

            return 1;
        }

        return 0;
    }
};