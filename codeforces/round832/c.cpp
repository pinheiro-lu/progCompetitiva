#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) //printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	ll n, sum = 1e10;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];   
        if (a[i] < sum) sum = a[i];
    }

    if ((sum) % 2 == 0) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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
