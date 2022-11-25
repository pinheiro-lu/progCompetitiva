#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	bool v;
    int a, b, c;

    cin >> a >> b >> c;

    if (a == b+c || b == c+a || c == a+b) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
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
