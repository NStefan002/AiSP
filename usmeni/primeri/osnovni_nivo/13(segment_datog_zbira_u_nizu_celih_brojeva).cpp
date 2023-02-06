#include <iostream>
#include <map>


using namespace std;

int main()
{
    int z, n;
    cin >> z >> n;

    // {suma : broj takvih pref. suma}
    map<int, int> prefSume;
    prefSume[0] = 1;
    int tekucaSuma = 0;
    int brSegmenata = 0;
    for (int i = 0; i < n; i++)
    {
        int br;
        cin >> br;
        tekucaSuma += br;

        auto it = prefSume.find(tekucaSuma - z);
        if (it != prefSume.end())
        {
            brSegmenata += it->second;
        }
        prefSume[tekucaSuma]++;
    }

    cout << brSegmenata << endl;

    return 0;
}
