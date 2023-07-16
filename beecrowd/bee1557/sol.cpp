#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    do {
        int t = to_string(1<<(n*2-2)).length();
        for (int i = 0; i < n; i++) {
            cout << setw(t) << right << (1<<i); 
            for (int j = 1; j < n; j++) {
                cout << ' ' << setw(t) << right << (1<<j+i);
            }
            cout << '\n';
        }
        cout << '\n';
        cin >> n;
    } while (n);
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
 
    return 0;
}
