// program C++ pentru a cauta un pattern in text folosind
// algoritmul KMP (Knuth-Morris-Pratt)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void constructLps(string &pat, vector<int> &lps) {

    // len stocheaza lungimea celui mai lung prefix care
    // este si sufix pentru indexul anterior
    int len = 0;

    // lps[0] este intotdeauna 0
    lps[0] = 0;

    int i = 1;
    while (i < pat.length()) {

        // daca caracterele se potrivesc, se incrementeaza
        // lungimea lps
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }

        // daca exista o nepotrivire
        else {
            if (len != 0) {

                // actualizam len cu valoarea lps de la indexul anterior
                // pentru a evita comparatiile redundante
                len = lps[len - 1];
            }
            else {

                // daca nu exista un prefix care sa se potriveasca, setam lps[i] la 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string &pat, string &txt) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);
    vector<int> res;

    // construim lps pentru pattern
    constructLps(pat, lps);

    // pointerii i si j, pentru a parcurge textul si pattern-ul
    int i = 0;
    int j = 0;

    while (i < n) {

        // daca caracterele se potrivesc, mutam amandoi pointerii inainte
        if (txt[i] == pat[j]) {
            i++;
            j++;

            // daca intregul pattern este gasit
            // salvam indexul de start in rezultat
            if (j == m) {
                res.push_back(i - j);

                // folosim LPS de la indexul anterior pentru a
                // sari peste comparatii inutile
                j = lps[j - 1];
            }
        }

        // daca exista o nepotrivire
        else {

            // folosim valoarea lps de la indexul anterior
            // pentru a evita comparatii redundante
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

int main() {
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = search(pat, txt);
    // afisam toate pozitiile la care a fost gasit pattern-ul
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}
