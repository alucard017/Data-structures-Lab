#include <iostream>
#include <string>
using namespace std;

string addLongIntegers(string num1, string num2)
{
    int carry = 0;
    string result = "";

    int i = num1.length() - 1, j = num2.length() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += num1[i--] - '0';
        if (j >= 0)
            sum += num2[j--] - '0';

        carry = sum / 10;
        result = to_string(sum % 10) + result;
    }

    return result;
}

int main()
{
    string num1 = "123456789123456789";
    string num2 = "987654321987654321";

    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;

    string sum = addLongIntegers(num1, num2);

    cout << "Sum: " << sum << endl;

    return 0;
}
