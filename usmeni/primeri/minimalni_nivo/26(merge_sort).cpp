#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void merge_sort(vector<int> &niz);
void merge_sort(vector<int> &niz, int l, int d, vector<int> &tmp);
void merge(vector<int> &a, int i, int n, vector<int> &b, int j, int m, vector<int> &c, int k);

int main()
{
    int n;
    cin >> n;

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }

    merge_sort(niz);

    for (int x : niz)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}

void merge_sort(vector<int> &niz)
{
    int n = niz.size();
    vector<int> tmp(n);
    merge_sort(niz, 0, n - 1, tmp);
}

void merge_sort(vector<int> &niz, int l, int d, vector<int> &tmp)
{
    if (l >= d)
    {
        return;
    }

    int s = l + (d - l) / 2;

    merge_sort(niz, l, s, tmp);
    merge_sort(niz, s + 1, d, tmp);

    merge(niz, l, s, niz, s + 1, d, tmp, l);

    for (int i = l; i <= d; i++)
    {
        niz[i] = tmp[i];
    }
}

void merge(vector<int> &a, int i, int n, vector<int> &b, int j, int m, vector<int> &c, int k)
{
    while (i <= n && j <= m)
    {
        c[k++] = a[i] < b[j] ? a[i++] : b[j++];
    }

    while (i <= n)
    {
        c[k++] = a[i++];
    }

    while (j <= m)
    {
        c[k++] = b[j++];
    }
}
