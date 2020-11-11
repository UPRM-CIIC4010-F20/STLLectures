#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

enum TokenType {
    OPERATOR,
    OPERAND,
};

set<string> VALID_OPS { "+", "-", "*", "/" };

TokenType tokenType(string s) {
    if (VALID_OPS.count(s.substr(0,1)) != 0) {
        return OPERATOR;
    } else {
        return OPERAND;
    }
}

double apply (string operand, double v1, double v2)
{
    if (operand == "+") return (v1 + v2);
    if (operand == "-") return (v1 - v2);
    if (operand == "*") return (v1 * v2);
    if (operand == "/") return (v1 / v2);
    return 0.0;  // Just to avoid no-return warning
}

double eval(vector<string> expression)
{
    stack<double, vector<double> > exprStack;

    for (string token : expression) {
        switch(tokenType(token)) {
            case OPERAND:
                exprStack.push(stod(token));
                break;
            case OPERATOR:
                double op2 = exprStack.top();
                exprStack.pop();
                double op1 = exprStack.top();
                exprStack.pop();
                exprStack.push(apply(token, op1, op2));
                break;
        }
    }
    return exprStack.top();
}

int main() {

    vector<string> e1 {"5.0", "3.0", "+", "2.0", "*", "2.0", "*" };

    cout << "5.0 3.0 + 2 * ->" << eval(e1) << endl;

}

