#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

long long brKombinacija(int k, int n, vector<vector<long long>> &memo);

int main()
{
    int k, n;
    cin >> k >> n;

    vector<vector<long long>> memo(n + 1);
    // treba nam samo trougao, a ne cela matrica
    for (int i = 0; i <= n; i++)
    {
        memo[i].resize(min(k + 1, i + 1), 0);
    }

    cout << brKombinacija(k, n, memo) << endl;
    return 0;
}

long long brKombinacija(int k, int n, vector<vector<long long>> &memo)
{
    // rezultat za konkretno n i k je vec izracunat
    if (memo[n][k] != 0) return memo[n][k];

    // od nula elemenata mozemo odabrati k elemenata samo na jedan nacin
    // isto vazi i za k elemenata
    if (k == 0 || k == n) return memo[n][k] = 1;

    return memo[n][k] = brKombinacija(k - 1, n - 1, memo) + brKombinacija(k, n - 1, memo);
}
