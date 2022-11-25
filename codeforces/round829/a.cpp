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

    int cq = 0, ca = 0;

    for (int i = 0; i < n; i++) {
        if(s[i] == 'Q') cq++;
        else ca++;
        if (ca > cq) {
            ca = cq = 0;
        }
    }

    cout << (ca < cq || s[n-1] == 'Q' ? "No\n" : "Yes\n");

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
