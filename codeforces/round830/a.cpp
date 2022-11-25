#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) //printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	int n;

    cin >> n;

    int a[n+1];
    int mdc, tmp = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) mdc = a[1];
        else {
            int aux = mdc;
            mdc = __gcd(a[i], mdc);
            if (aux == mdc) tmp = i;
        }
    }

    if (tmp == 0) {
        cout << "0\n";
        return;
    }

    int mdc1 = __gcd(a[tmp], tmp);
    int mdc2 = __gcd(a[tmp], mdc);
    int mdc3 = __gcd(a[tmp-1], tmp-1);
    int mdc4 = __gcd(a[tmp-1], mdc);

    int sum;

    if (mdc2 <= mdc4) {
        a[tmp] = mdc1;
        sum = n-tmp + 1;
    } else {
        a[tmp-1] = mdc3;
        sum = n-tmp + 2;
    }

    while (mdc > 1) {
        tmp = 0;
        for (int i = 1; i <= n; i++) {
        if (i == 1) mdc = a[1];
        else {
            int aux = mdc;
            mdc = __gcd(a[i], mdc);
            if (aux == mdc) tmp = i;
        }
    }

    if (tmp == 0) {
        cout << sum << endl;
        return;
    }

     mdc1 = __gcd(a[tmp], tmp);
     mdc2 = __gcd(a[tmp], mdc);
     mdc3 = __gcd(a[tmp-1], tmp-1);
     mdc4 = __gcd(a[tmp-1], mdc);

    
    if (mdc2 <= mdc4) {
        a[tmp] = mdc1;
        sum += n-tmp + 1;
    } else {
        a[tmp-1] = mdc3;
        sum += n-tmp + 2;
    }

    }

    cout << sum << endl;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	
    cin >> t;
	//scanf("%d", &t);
//	while (getchar() != '\n');

	while (t--)
		solve();
		
	return 0;
}
