class Not: public SubExpression
{
public:
    Not(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
    double evaluate()
    {
        if( (left->evaluate() || right->evaluate()) > 0) {

            return 0;
        }

        return 1;
    }
};