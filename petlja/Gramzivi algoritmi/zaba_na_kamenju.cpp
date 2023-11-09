#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> kamenje(n);
    for (int i = 0; i < n; i++)
    {
        cin >> kamenje[i];
    }

    int r;
    cin >> r;

    int tekuci = 0, br_skokova = 0;
    while (tekuci < n - 1)
    {
        int sledeci = tekuci + 1;
        while(sledeci < n && kamenje[sledeci] - kamenje[tekuci] <= r)
        {
            sledeci++;
        }
        // ne moze da skoci na sledeci kamen
        if (sledeci == tekuci + 1)
        {
            br_skokova = -1;
            break;
        }
        tekuci = sledeci - 1;
        br_skokova++;
    }

    cout << br_skokova << '\n';

    return 0;
}
