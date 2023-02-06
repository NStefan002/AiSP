#include <iostream>
#include <vector>
#include <set>


using namespace std;

void generisi(vector<int> permutacija, set<int> &preostali, int i);
void ispisi(vector<int> &v);

int main()
{
    int n;
    cin >> n;

    vector<int> permutacija(n);
    set<int> preostali;
    for (int i = 1; i <= n; i++)
    {
        preostali.insert(i);
    }

    generisi(permutacija, preostali, 0);

    return 0;
}

void generisi(vector<int> permutacija, set<int> &preostali, int i)
{
    int n = permutacija.size();
    if (i == n)
    {
        ispisi(permutacija);
        return;
    }

    for (int x : preostali)
    {
        permutacija[i] = x;
        preostali.erase(x);
        generisi(permutacija, preostali, i + 1);
        preostali.insert(x);
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
