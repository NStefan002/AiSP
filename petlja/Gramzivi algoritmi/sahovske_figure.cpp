#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> domaci(n);
    vector<int> gosti(n);

    for (int i = 0; i < n; i++)
    {
        cin >> domaci[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> gosti[i];
    }

    sort(begin(domaci), end(domaci));
    sort(begin(gosti), end(gosti));

    int d = 0, g = 0;
    int pobede = 0;
    while (d < n)
    {
        if (domaci[d] >= gosti[g])
        {
            pobede++;
            d++;
            g++;
        }
        else
        {
            d++;
        }
    }

    cout << pobede << '\n';

    return 0;
}
