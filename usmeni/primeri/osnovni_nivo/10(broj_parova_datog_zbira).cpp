#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main ()
{
    int s, n;
    cin >> s >> n;

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }

    sort(begin(niz), end(niz));

    int l = 0, d = n - 1;
    int brParova = 0;
    while (l < d)
    {
        int zbir = niz[l] + niz[d];
        if (zbir > s)
        {
            // treba nam manji broj
            d--;
        }
        else if (zbir < s)
        {
            // treba nam veci broj
            l++;
        }
        else // pronadjen trazeni zbir
        {
            brParova++;
            // trazimo sledeci par
            l++; d--;
        }
    }

    cout << brParova << endl;
    
    return 0;
}
