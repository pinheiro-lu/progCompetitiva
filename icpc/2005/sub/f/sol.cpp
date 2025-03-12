#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

ll s;
int	d;
bool imp;
vector<string> nums;
array<bool, 10>used;

vector<vector<int>> tec{
	{7, 8, 9}, 
	{2, 4, 5},
	{1, 3, 4, 5, 6},
	{2, 5, 6},
	{1, 2, 5, 7, 8},
	{1, 2, 3, 4, 6, 7, 8, 9},
	{2, 3, 5, 8, 9},
	{0, 4, 5, 8},
	{0, 4, 5, 6, 7, 9},
	{0, 5, 6, 8}
};

void solve (string cur, int dig) {
	cur += dig+'0';
	ll sum = stoll(cur);
	for (string n : nums) {
		sum += stoll(n);
	}
	if (sum > s) return;
	if (sum == s) {
		imp = false;
		for (string n : nums) cout << n << ' ';
		cout << cur << '\n';
	}
	if (cur.size() == d) {
	    nums.push_back(cur);
		cur="";
	}
	for (int x : tec.at(dig)) {
		if (!used.at(x)) {
			used.at(x) = true;
			solve(cur, x);
			used.at(x) = false;
		}
	}
	if (cur == "") nums.pop_back();
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt = 1;
	while (true) {
		cin >> s >> d;
		if (s == -1) break;
		imp = true;
		cout << '#' << tt++ << '\n';
		for (int i = 0; i < 10; ++i) {
			used.at(i) = true;
			solve("", i);
			used.at(i) = false;
		}
		if (imp) cout << "impossivel\n";
	}



	return 0;
}
