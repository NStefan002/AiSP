#include <iostream>
#include <vector>


using namespace std;

void ispisi(vector<int> &v);
bool ispravnoRasporedjeno(vector<vector<bool>> &susednosti, vector<int> &frekvencije, int tekuci);
bool generisi(vector<vector<bool>> &susednosti, vector<int> &frekvencije, int tekuci);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> susednosti(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        int prvi, drugi;
        cin >> prvi >> drugi;
        susednosti[prvi][drugi] = true;
        susednosti[drugi][prvi] = true;
    }
    
    vector<int> frekvencije(n, 0);
    if (generisi(susednosti, frekvencije, 0))
    {
        ispisi(frekvencije);
    }
    else
    {
        cout << '-' << endl;
    }

    return 0;
}

bool generisi(vector<vector<bool>> &susednosti, vector<int> &frekvencije, int tekuci)
{
    if (tekuci > 1 && !ispravnoRasporedjeno(susednosti, frekvencije, tekuci - 1))
    {
        return false;
    }

    if (tekuci == frekvencije.size())
    {
        return true;
    }
    
    /* Problem se svodi na problem bojenja grafa. Matrica susednosti cuva informaciju
    o tome izmedju koja dva cvora grafa postoji grana (ako je true znaci postoji). 
    Pokusavamo tekuci cvor grafa da obojimo sa jednom od tri ponudjene boje i vracamo
    informaciju o uspesnosti bojenja prethodnom rekurzivnom pozivu. */
    frekvencije[tekuci] = 1;
    if (!generisi(susednosti, frekvencije, tekuci + 1))
    {
        frekvencije[tekuci] = 2;
        if (!generisi(susednosti, frekvencije, tekuci + 1))
        {
            frekvencije[tekuci] = 3;
            return generisi(susednosti, frekvencije, tekuci + 1);
        }
    }
    return true;
}

bool ispravnoRasporedjeno(vector<vector<bool>> &susednosti, vector<int> &frekvencije, int tekuci)
{
    /* Ako postoji susedna grana tekucoj grani, ispitujemo da li je isto obojena. */
    for (int j = 0; j < tekuci; j++)
    {
        if (susednosti[tekuci][j] && frekvencije[j] == frekvencije[tekuci])
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
    cout << endl;
}