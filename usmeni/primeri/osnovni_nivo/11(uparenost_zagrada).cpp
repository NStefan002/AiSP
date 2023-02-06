#include <iostream>
#include <stack>
#include <string>


using namespace std;

bool ispravnoUparene(string &s);

int main() 
{
    string s;
    cin >> s;

    cout << (ispravnoUparene(s) ? "da" : "ne") << endl;

    return 0;
}

bool ispravnoUparene(string &s)
{
    stack<char> stek;
    for (char c : s)
    {
        if (c == '(')
        {
            stek.push(c);
        }
        else if (c == ')')
        {
            if (stek.empty())
            {
                return false;
            }
            stek.pop();
        }
    }

    return true;
}
