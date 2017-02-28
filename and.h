class And: public SubExpression
{
public:
    And(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
    double evaluate()
    {
        if( (left->evaluate() && right->evaluate() > 0)) {

            return 1;
        }

        return 0;
    }
};