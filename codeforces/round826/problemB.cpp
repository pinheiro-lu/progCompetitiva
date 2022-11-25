#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

void solve(void) {
	int n;
    
    cin >> n;

    if (n == 1 || n == 3) cout << -1 << endl;
    else if (n == 2) cout << "2 1" << endl;
    else {
        for (int i = 3; i <= n; i++) {
            cout << i << ' ';
        }
        cout << "2 1" << endl;
    }
    
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
