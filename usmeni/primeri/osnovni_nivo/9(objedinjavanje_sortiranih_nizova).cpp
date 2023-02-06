#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int m;
    cin >> m;

    vector<int> grupaA(m);
    for (int i = 0; i < m; i++)
    {
        cin >> grupaA[i];
    }

    int n;
    cin >> n;

    vector<int> grupaB(m);
    for (int i = 0; i < n; i++)
    {
        cin >> grupaB[i];
    }

    vector<int> objedinjeno(m + n);
    int a = 0, b = 0, o = 0;
    while (a < m && b < n)
    {
        objedinjeno[o++] = grupaA[a] < grupaB[b] ? grupaA[a++] : grupaB[b++];
    }
    
    while (a < m)
    {
        objedinjeno[o++] = grupaA[a++];
    }

    while (b < n)
    {
        objedinjeno[o++] = grupaB[b++];
    }

    for (int x : objedinjeno)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
