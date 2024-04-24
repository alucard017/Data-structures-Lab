#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;
char stack[MAX_SIZE];
int top = -1;

void push(char value)
{
    if (top == MAX_SIZE - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack[++top] = value;
}

char pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
        return '\0';
    }
    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return '\0';
    }
    return stack[top];
}

bool isEmpty()
{
    return top == -1;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string reverseString(const string &str)
{
    string reversed;
    for (int i = str.length() - 1; i >= 0; --i)
    {
        reversed += str[i];
    }
    return reversed;
}

string infixToPrefix(const string &infix)
{
    string reversedInfix = reverseString(infix);
    string postfix;
    int top = -1;

    for (char ch : reversedInfix)
    {
        if (isdigit(ch) || isalpha(ch))
        {
            postfix += ch;
        }
        else if (ch == ')')
        {
            push(ch);
        }
        else if (ch == '(')
        {
            while (top != -1 && peek() != ')')
            {
                postfix += pop();
            }
            pop(); // Remove ')'
        }
        else
        { // Operator
            while (top != -1 && precedence(peek()) > precedence(ch))
            {
                postfix += pop();
            }
            push(ch);
        }
    }

    while (top != -1)
    {
        postfix += pop();
    }

    return reverseString(postfix);
}

int main()
{
    string infix = "a+b*(c-d/e)";
    string prefix = infixToPrefix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}
