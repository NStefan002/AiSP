#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iznos;
    cin >> iznos;

    const vector<int> apoeni = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000};
    int i = apoeni.size() - 1;
    int br_apoena = 0;
    while (iznos > 0)
    {
        if (iznos - apoeni[i] >= 0)
        {
            iznos -= apoeni[i];
            br_apoena++;
        }
        else
        {
            i--;
        }
    }

    cout << br_apoena << '\n';

    return 0;
}
