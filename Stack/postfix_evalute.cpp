#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isOperand(char c)
{
    if (c >= '0' && c <= '9')
        return true;

    return false;
}
bool isOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^' || C == '%')
        return true;

    return false;
}
int evaluate(string postfix)
{
    stack<int> S;
    int result;
    string val = "";
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperator(postfix[i]))
        {
            int value;
            int a = S.top();
            S.pop();
            int b = S.top();
            S.pop();
            switch (postfix[i])
            {
            case '+':
            {
                value = b + a;
                break;
            }
            case '-':
            {
                value = b - a;
                break;
            }
            case '*':
            {
                value = b * a;
                break;
            }
            case '/':
            {
                value = b / a;
                break;
            }
            case '%':
            {
                value = b % a;
                break;
            }
            case '^':
            {
                value = b ^ a;
                break;
            }
            default:
                break;
            }
            S.push(value);
        }
        else if (postfix[i] == ' ' || postfix[i] == ',')
        {
            continue;
        }
        else
        {
            cout << postfix[i] << endl;
            while (isOperand(postfix[i]))
            {
                val += postfix[i];
                i++;
            }
            int value = stoi(val);
            cout << value << endl;
            S.push(value);
            val = "";
        }
    }
    result = S.top();
    S.pop();
    return result;
}
int main()
{
    string postfix;
    cout << "enter the postfix expression (numbers and operators must be seperated by \",\" ) = ";
    getline(cin, postfix);
    int result = evaluate(postfix);
    cout << "result is = " << result << endl;

    return 1;
}