#include <iostream>


using namespace std;

bool prost(int n);

int main()
{
    int n;
    cin >> n;

    cout << (prost(n) ? "DA" : "NE") << endl;

    return 0;
}

bool prost(int n)
{
    if (n == 1) return false;
    if (n % 2 == 0 && n != 2) return false;
    if (n % 3 == 0 && n != 3) return false;

    for (int i = 1; (6*i - 1) * (6*i - 1) <= n; i++)
    {
        if (n % (6*i + 1) == 0 || n % (6*i - 1) == 0) return false;
    }

    return true;
}
