#include <iostream>
#include<string>
#include<stack>
using namespace std;

float mathOp(float op1 , float op2 , char sign){
    if (sign == '+')
        return op1 + op2;
    else if (sign == '-')
        return op1 - op2;
    else if (sign == '*')
        return op1 * op2;
    else if (sign == '/')
        return op1 / op2;
    else
        return 0;
}

float postEval (string exp)
{
    stack<float> stk;
    for(int i=0 ; i<exp.length(); i++)
    {
        if (isdigit(exp[i]))    // check if it's num
        {
            stk.push(exp[i]-'0'); // we (-) 0 from it because o in char =(48)
        }
        else
        {
            // we out the secand num in the stack
            float op2 = stk.top();
            stk.pop();
            // we out first num in the stack {note::we always out two num}
            float op1 = stk.top();
            stk.pop();
            // to pmake calc
            float sum = mathOp(op1,op2,exp[i]);
            stk.push(sum);
        }
    }
    stk.top();

}

int main()
{
    string postfixEx = "382/+5-";
    cout << postEval(postfixEx) << endl;
}
