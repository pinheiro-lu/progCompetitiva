#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    char c;
    
    cin >> c;
    

    float x, sum = 0;
    int k = 11;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> x;
            if (j < k)
            sum+=x;
        }
        k--;
    }
    
    cout << fixed << setprecision(1) << (c == 'S' ? sum : sum/60) << '\n';
 
    return 0;
}
