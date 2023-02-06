#include <iostream>
#include <vector>


using namespace std;

void sledecaKombinacija(vector<int> &k, int n);
void ispisi(vector<int> &v);

int main()
{
    int n;
    cin >> n;

    vector<int> kombinacija;
    int br;
    while (cin >> br)
    {
        kombinacija.push_back(br);
    }

    sledecaKombinacija(kombinacija, n);

    return 0;
}

void sledecaKombinacija(vector<int> &k, int n)
{
    int i = k.size() - 1;
    int d = k.size();
    while (i >= 0)
    {
        if (k[i] != n - (d - i - 1))
        {
            k[i]++;
            break;
        }
        i--;
    }
    if (i == -1)
    {
        cout << "-\n";
    }
    else
    {
        ispisi(k);
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
