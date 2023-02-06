#include <iostream>
#include <vector>


using namespace std;

long long fib(int n, vector<long long> &memo);

int main()
{
    int n;
    cin >> n;

    vector<long long> memo(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        cout << fib(i, memo) << '\n';
    }

    return 0;
}

long long fib(int n, vector<long long> &memo)
{
    if (memo[n] != 0)
    {
        return memo[n];
    }

    if (n == 0 || n == 1)
    {
        return memo[n] = 1;
    }
    return memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
}
