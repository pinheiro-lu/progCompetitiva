#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) //printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	int n;

    cin >> n;

    string s;

    cin >> s;

    bool change = false;
    int ans = 0;
    int j = 0;

    for (int i = n-1; i > 0; i--) {
        if (s[i] != s[i-1]) {
            j = i;
            break;
        }
    }

    for (int i = 0; i < j; i++) {
        if ((s[i] == '1' && !change) || (s[i] == '0' && change)) {
            change = !change;
            ans++;
        }
    }

    cout << ans << endl;
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
