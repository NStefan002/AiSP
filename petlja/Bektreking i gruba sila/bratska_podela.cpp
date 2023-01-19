#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <iomanip>
        

using namespace std;

void nadjiMinRazliku(vector<double> &vrednosti, vector<bool> &podela, double zbir1, double zbir2, int i, double &minRazlika);

int main()
{
    int n;
    cin >> n;

    vector<double> vrednosti(n);
    double zbirSvihVrednosti = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vrednosti[i];
        zbirSvihVrednosti += vrednosti[i];
    }

    double minRazlika = numeric_limits<double>::max();
    vector<bool> podela(n, false);
    nadjiMinRazliku(vrednosti, podela, 0, zbirSvihVrednosti, 0, minRazlika);
    cout << fixed << setprecision(2) << showpoint << minRazlika << endl;

    return 0;
}

void nadjiMinRazliku(vector<double> &vrednosti, vector<bool> &podela, double zbir1, double zbir2, int i, double &minRazlika)
{
    /* true u nizu podela znaci da predmet pripada prvom bratu, a false da pripada drugom. Posto su na pocetku
    svi elementi niza inicijalizovani na falsem na pocetku svi predmeti pripadaju drugom bratu. */
    minRazlika = min(minRazlika, fabs(zbir1 - zbir2));
    if (i == podela.size())
    {
        return;
    }
    
    // podela[i] = false; -> elementi niza inicijalizovani na false
    nadjiMinRazliku(vrednosti, podela, zbir1, zbir2, i + 1, minRazlika);

    podela[i] = true;
    nadjiMinRazliku(vrednosti, podela, zbir1 + vrednosti[i], zbir2 - vrednosti[i], i + 1, minRazlika);
}