#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int z, n;
    cin >> z >> n;

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }

    // zbir iz opsega [l, d)
    int l = 0, d = 1;
    int zbir = niz[0];
    while (d <= n)
    {
        if (zbir > z)
        {
            zbir -= niz[l++];
        }
        else if (zbir < z)
        {
            zbir += niz[d++];
        }
        else 
        {
            cout << l << ' ' << d - 1 << '\n';
            zbir -= niz[l++];
            zbir += niz[d++];
        }
    }

    return 0;
}
