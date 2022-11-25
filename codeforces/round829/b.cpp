#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) //printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	int n;

    cin >> n;

    if (n == 4) {
        cout << "2 4 1 3\n";
        return;
    }

    int j = n, k = n/2;
    int a = n;
    for (int i = 1; i < a; i+=2) {
        cout << j << " " << k << " ";
        j--;
        k--;
    }
    if (n % 2) cout << j;
    cout << endl;
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
