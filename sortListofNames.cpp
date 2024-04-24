#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> names;
    int n;

    cout << "Enter the number of names: ";
    cin >> n;

    cout << "Enter " << n << " names:\n";
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        names.push_back(name);
    }

    // Sorting the names
    sort(names.begin(), names.end());

    cout << "Sorted list of names:\n";
    for (const string &name : names)
    {
        cout << name << endl;
    }

    return 0;
}
