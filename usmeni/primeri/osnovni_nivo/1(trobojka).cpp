#include <iostream>
#include <vector>


using namespace std;

void trobojka(vector<int> &niz, int a, int b);
void razmeni(vector<int> &v, int i, int j);
void ucitaj(vector<int> &v, int n);
void ispisi(vector<int> &v); 

int main()
{
    int n, a, b;
    cin >> n;

    vector<int> niz(n);
    ucitaj(niz, n);

    cin >> a >> b;

    trobojka(niz, a, b);
    ispisi(niz);

    return 0;
}

void trobojka(vector<int> &niz, int a, int b)
{
    // aaaa ccc ??? bbbb
    //     l    i d
    int i = 0, l = 0, d = niz.size() - 1;
    while (i <= d)
    {
        if (niz[i] < a)
        {
            razmeni(niz, i++, l++);
        }
        else if (niz[i] > b) 
        {
            razmeni(niz, i, d--);
        }
        else 
        {
            i++;
        }
    }
}

void ucitaj(vector<int> &v, int n)
{
    v = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

void ispisi(vector<int> &v)
{
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void razmeni(vector<int> &v, int i, int j)
{
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
