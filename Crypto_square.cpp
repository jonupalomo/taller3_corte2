#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // TODO: add your solution here
    string frase;
    cout << "Dame la cadena de caractéres: ";
    getline(cin, frase);
    transform(frase.begin(), frase.end(), frase.begin(), ::tolower);

    string frase_limpia = "";
    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] != ' ' && frase[i] != ',' && frase[i] != '.') {
            frase_limpia += frase[i];
        }
    }

    cout << "Frase limpia: " << frase_limpia << endl;

    int lon = frase_limpia.length();
    if (lon == 0) {
        return 0;
    }
    int r = 0;
    int c = 0;
    while (r * c < lon) {
        if (c <= r) {
            c++;
        } else {
            r++;
        }
    }
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            int pos = i * c + j;
            if (pos < lon) {
                cout << frase_limpia[pos];
            } else {
                cout << ' ';
            }
        }
        if (j < c - 1) {
            cout << ' '; 
        }
    }
    cout << endl;
    return 0;
}