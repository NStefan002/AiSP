#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main ()
{
    int n;
    cin >> n;

    vector<int> sobe(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sobe[i];
    }
    
    sort(begin(sobe), end(sobe));

    int soba1 = 0, soba2 = 1, minRastojanje = sobe[1] - sobe[0];
    for (int i = 2; i < n; i++)
    {
        if (minRastojanje >= sobe[i] - sobe[i - 1])
        {
            minRastojanje = sobe[i] - sobe[i - 1];
            soba1 = i - 1;
            soba2 = i;
        }
    }

    cout << sobe[soba1] << ' ' << sobe[soba2] << endl;
    return 0;
}
