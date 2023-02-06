#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    int maxSuma = 0; // suma praznog segmenta je 0
    int i = 0;

    while (i < n)
    {
        int tekuciZbir = 0;
        int j = i;
        while (j < n)
        {
            int br;
            cin >> br;
            tekuciZbir += br;
            if (tekuciZbir < 0)
            {
                break;
            }

            maxSuma = max(maxSuma, tekuciZbir);
            j++;
        }

        i = j + 1;
    }

    cout << maxSuma << endl;

    return 0;
}
