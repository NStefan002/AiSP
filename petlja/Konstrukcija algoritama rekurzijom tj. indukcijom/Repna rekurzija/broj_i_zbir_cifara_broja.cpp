#include <iostream>

using namespace std;

void br_i_zbir(long long n, int &br_cif, int &zbir_cif);

int main()
{
    long long n;
    cin >> n;

    int br_cif = 0, zbir_cif = 0;

    if (n == 0) br_cif = 1;
    else br_i_zbir(n, br_cif, zbir_cif);

    cout << br_cif << " " << zbir_cif;

    return 0;
}

void br_i_zbir(long long n, int &br_cif, int &zbir_cif)
{
    if (n == 0)
        return;

    br_cif++;
    zbir_cif += n % 10;
    br_i_zbir(n / 10, br_cif, zbir_cif);
}
