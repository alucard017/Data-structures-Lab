#include <iostream>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void push(char stack[], int &top, char value)
{
    stack[++top] = value;
}

char pop(char stack[], int &top)
{
    return stack[top--];
}

char peek(char stack[], int top)
{
    return stack[top];
}

string infixToPostfix(const string &infix)
{
    string postfix;
    const int MAX_SIZE = infix.length();
    char operators[MAX_SIZE];
    int top = -1;

    for (char ch : infix)
    {
        if (isdigit(ch) || isalpha(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(operators, top, ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek(operators, top) != '(')
            {
                postfix += pop(operators, top);
            }
            pop(operators, top); // Remove '('
        }
        else
        { // Operator
            while (top != -1 && precedence(peek(operators, top)) >= precedence(ch))
            {
                postfix += pop(operators, top);
            }
            push(operators, top, ch);
        }
    }

    while (top != -1)
    {
        postfix += pop(operators, top);
    }

    return postfix;
}

int main()
{
    string infix = "a+b*(c-d/e)";
    string postfix = infixToPostfix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
