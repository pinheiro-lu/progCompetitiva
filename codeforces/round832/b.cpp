#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) //printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	int n;

    cin >> n;

    if (n == 1) {
        cout << "1\n1 2\n";
        return;
    }

    cout << ceil((float)n/2.0) << endl;
    int j = 1;
    int m = n*3;
    
    for (int i = 1; i <= ceil((float)n/2.0); i++) {
        cout << j << ' ' << m << endl;
        j+=3;
        m -= 3;
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
