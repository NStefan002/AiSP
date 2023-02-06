#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<unsigned> ipAdrese(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ipAdrese[i];
    }

    sort(begin(ipAdrese), end(ipAdrese));

    int brJedinstvenih = 1;
    for (int i = 1; i < n; i++)
    {
        if (ipAdrese[i] != ipAdrese[i - 1])
        {
            brJedinstvenih++;
        }
    }
    
    cout << brJedinstvenih << endl;

    return 0;
}
