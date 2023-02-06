#include <iostream>
#include <vector>


using namespace std;

void generisi(vector<int> &v, int i, int n, int k);
void ispisi(vector<int> &v);

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> varijacija(k);
    generisi(varijacija, 0, n, k);

    return 0;
}

void generisi(vector<int> &v, int i, int n, int k)
{
    if (i == k)
    {
        ispisi(v);
        return;
    }

    for (int j = 1; j <= n; j++)
    {
        v[i] = j;
        generisi(v, i + 1, n, k);
    }
}

void ispisi(vector<int> &v)
{
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
}
