#include <bits/stdc++.h>
 
using namespace std;

void imprimei (vector <int> a, int n) {
    for (int i = 0; i < n; i++) {
        cout <<"impar[" << i << "] = " << a[i] << '\n';
    }
}

void imprimep (vector <int> a, int n) {
    for (int i = 0; i < n; i++) {
        cout <<"par[" << i << "] = " << a[i] << '\n';
    }
}

int main() {
    vector <int> a(15);
    vector <int> p(15);
    vector <int> im(15);
    int up = 0;
    int ui = 0;
    
    for (int i = 0; i < 15; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            im[ui++] = a[i];
            if (ui == 5) {
                imprimei(im, 5);
                ui = 0;
            }
        } else {
            p[up++] = a[i];
            if (up == 5) {
                imprimep(p, 5);
                up = 0;
            }
        }
    }
    
    imprimei (im, ui);
    imprimep (p, up);
 
    return 0;
}
