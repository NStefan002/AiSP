#include <iostream>
#include <queue>


using namespace std;

int main ()
{
    int k;
    cin >> k;

    queue<string> red;
    string linija;
    while (getline(cin, linija))
    {
        if (red.size() == k)
        {
            red.pop();
        }
        red.push(linija);
    }

    while (!red.empty())
    {
        cout << red.front() << '\n';
        red.pop();
    }

    return 0;
}
