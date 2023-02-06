#include <iostream>
#include <vector>


using namespace std;

void generisi(vector<int> &podskup, int i);
void ispisi(vector<int> &v);

int main()
{
    int n;
    cin >> n;

    vector<int> podskup(n, -1);
    generisi(podskup, 0);

    return 0;
}

void generisi(vector<int> &podskup, int i)
{
    ispisi(podskup);
    int n = podskup.size();
    if (i == n)
    {
        return;
    }

    int prethodni = i == 0 ? -1 : podskup[i - 1];
    for (int j = prethodni + 1; j < n; j++)
    {
        podskup[i] = j;
        generisi(podskup, i + 1);
        podskup[i] = -1;
    }
}

void ispisi(vector<int> &v)
{
    for (int x : v)
    {
        if (x == -1)
        {
            break;
        }
        cout << x << ' ';
    }
    cout << '\n';
}
