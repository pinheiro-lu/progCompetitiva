#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

void solve(void) {
	int n,s=0,m=0,l=0, maxl = 0;
    
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s+=a[i];
        if(a[i] > m) m = a[i];
    }

    for (int i = 1; i <= n; i--) {
        int tmp, aux = 0, j;
        if (!(s % i) && s/i >= m) {
            tmp = s/i;
            for (j = 0; j < n; j++) {
                aux += a[j];
                l++;
                if (aux == tmp) {
                    aux = 0;
                    if (l > maxl) {
                        maxl = l;
                    }
                    l = 0;
                } else if (aux > tmp) {l=0;break;}
            }
            if (j == n) break;
        }
    }
    cout << maxl << endl;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}
