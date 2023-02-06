#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>


using namespace std;

bool isti(vector<int> &ulazniNiz, vector<int> &izlazniNiz);

int main()
{
    int n;
    cin >> n;

    vector<int> ulazniNiz(n), izlazniNiz(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ulazniNiz[i];
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> izlazniNiz[i];
    }

    cout << (isti(ulazniNiz, izlazniNiz) ? "da" : "ne") << endl;

    return 0;
}

bool isti(vector<int> &ulazniNiz, vector<int> &izlazniNiz)
{
    if (ulazniNiz.size() != izlazniNiz.size())
    {
        return false;
    }

    sort(begin(ulazniNiz), end(ulazniNiz));
    sort(begin(izlazniNiz), end(izlazniNiz));

    return ulazniNiz == izlazniNiz;
}
