#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>


using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;

    queue<float> segment;
    float suma = 0;
    float br;
    for (int i = 0; i < k; i++)
    {
        cin >> br;
        segment.push(br);
        suma += br;
    }

    float maxProsek = suma / k;
    for (int i = k; i < n; i++) 
    {
        cin >> br;
        suma += br;
        segment.push(br);
        suma -= segment.front();
        segment.pop();
        
        maxProsek = max(maxProsek, suma / k);
    }

    cout << fixed << showpoint << setprecision(2) << maxProsek << endl;
    hello
    return 0;
}
