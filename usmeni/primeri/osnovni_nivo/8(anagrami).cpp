#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>


using namespace std;

bool jesuAnagrami(vector<char> &s1, vector<char> &s2);

int main()
{
    string tmp1, tmp2;
    getline(cin, tmp1);
    getline(cin, tmp2);

    vector<char> s1, s2;
    for (char c : tmp1)
    {
        if (isalpha(c))
        {
            s1.push_back(tolower(c));
        }
    }

    for (char c : tmp2)
    {
        if (isalpha(c))
        {
            s2.push_back(tolower(c));
        }
    }

    sort(begin(s1), end(s1));
    sort(begin(s2), end(s2));

    cout << (jesuAnagrami(s1, s2) ? "da" : "ne") << endl;

    return 0;
}

bool jesuAnagrami(vector<char> &s1, vector<char> &s2)
{
    for (int i = 0; s1[i]; i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }

    return true;
}
