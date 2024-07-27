#include <bits/stdc++.h>
using namespace std;

		
void solve() {
	int n;
	cin >> n;
	stack<int> q;

	if (~n & 1) {
		cout << "-1\n";
		return;
	}

	while (n != 1) {
		if ((n-1)/2 & 1) {
			n = (n-1)/2;
			q.push(2);
		} else if ((n+1)/2 & 1) {
			n = (n+1)/2;
			q.push(1);
		} else {
			cout << "-1\n";
			return;
		}
	}
	if (q.size() > 40) {
		cout << "-1\n";
		return;
	}
	cout << q.size() << '\n';
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
	cout << '\n';

}	

int main() {
	int t;

	cin >> t;

	while (t--) solve();

	return 0;
}
