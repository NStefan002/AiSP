#include <iostream>


using namespace std;

long long fib(int n);

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        cout << fib(i) << '\n';
    }
    return 0;
}

long long fib(int n)
{
    long long prethodni = 1, tekuci = 1;
    for (int i = 2; i <= n; i++)
    {
        long long sledeci = tekuci + prethodni;
        prethodni = tekuci;
        tekuci = sledeci;
    }

    return tekuci;
}
