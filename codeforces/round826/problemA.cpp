#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

void solve(void) {
	string a, b;

    cin >> a >> b;

    if (a.back() == 'S') {
        if (b.back() != 'S') {
            cout << "<" << endl;
            return;
        }
        cout << ((a.length() > b.length()) ? "<" : (a.length() == b.length()) ? "=" : ">") << endl;
        return;
    }
    if (a.back() == 'L') {
        if (b.back() != 'L') {
            cout << ">" << endl;
            return;
        }
        cout << ((a.length() > b.length()) ? ">" : (a.length() == b.length()) ? "=" : "<") << endl;
        return;
    }
    cout << ((b.back() == 'L') ? "<" : (b.back() == 'S') ? ">" : "=") << endl;

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
