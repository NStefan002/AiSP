#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void quick_sort(vector<int> &niz, int l, int d);

int main()
{
    int n;
    cin >> n;

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }

    quick_sort(niz, 0, n - 1);

    for (int x : niz)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}

void quick_sort(vector<int> &niz, int l, int d)
{
    if (l >= d)
    {
        return;
    }

    // nasumicno biramo pivota
    int pivot = l + rand() % (d - l + 1);
    swap(niz[l], niz[pivot]);

    int p = l;
    for (int i = l + 1; i <= d; i++)
    {
        if (niz[i] <= niz[l])
        {
            swap(niz[i], niz[++p]);
        }
    }
    swap(niz[l], niz[p]);

    quick_sort(niz, l,  p - 1);
    quick_sort(niz, p + 1, d);
}
