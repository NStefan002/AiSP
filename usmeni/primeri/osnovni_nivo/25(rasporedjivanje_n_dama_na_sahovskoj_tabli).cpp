#include <iostream>
#include <vector>


using namespace std;

void ispisi(vector<int> &v);
bool ispravnoPopunjeno(vector<int> &raspored, int i);
void generisi(vector<int> &raspored, int i);

int main()
{
    int n;
    cin >> n;

    vector<int> raspored(n, 0);
    generisi(raspored, 0);

    return 0;
}

void generisi(vector<int> &raspored, int i)
{
    if (!ispravnoPopunjeno(raspored, i - 1))
    {
        return;
    }

    if (i == raspored.size())
    {
        ispisi(raspored);
        return;
    }

    for (int upis = 1; upis < raspored.size() + 1; upis++)
    {
        raspored[i] = upis;
        generisi(raspored, i + 1);
    }
    // skidamo damu sa polja da bismo omogucili ostalim rekurzivnim
    // pozivima da izgenerisu neku drugu raspodelu
    raspored[i] = 0;
}

bool ispravnoPopunjeno(vector<int> &raspored, int i)
{
    if (i < 1)
    {
        return true;
    }

    for (int vecUpisano = 0; vecUpisano < i; vecUpisano++)
    {
        // provera da li je neki u istoj koloni
        if (raspored[vecUpisano] == raspored[i])
        {
            return false;
        }
        // naredne dve provere ispituju dijagonalu (nacrtati i videti povezanost)
        if (raspored[vecUpisano] + (i - vecUpisano) == raspored[i])
        {
            return false;
        }
        if (raspored[vecUpisano] - (i - vecUpisano) == raspored[i])
        {
            return false;
        }
    }
    return true;
}

void ispisi(vector<int> &v)
{
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
}
