#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m;

	cin >> n >> m;

	int s;

	cin >> s;

	int sum = 0;
	while (s--) {
		int x, y, r;

		cin >> x >> y >> r;

		/*sum+=(2*r+1)*(2*r+1);
		if ((y+r)-m > 0) sum-=((y+r)-m)*x;
		if (y-r < 1) sum-=-(y-r-1)*x;
		if ((x+r)-n > 0) sum-=((x+r)-n)*y;
		if (x-r < 1) sum-=-(x-r-1)*y;
		*/
		sum+=(2*r+1)*(2*r+1); 
		if ((y+r)-m > 0) sum-=((y+r)-m)*(2*r+1); 
		if (y-r < 1) sum-=-(y-r-1)*(2*r+1); 
		if ((x+r)-n > 0) sum-=((x+r)-n)*(2*r+1); 
		if (x-r < 1) sum-=-(x-r-1)*(2*r+1); 
		if ((y+r)-m > 0 && (x+r)-n > 0) sum+=((y+r)-m)*((x+r)-n); 
		if ((y+r)-m > 0 && x-r < 1) sum+=((y+r)-m)*(-(x-r-1)); 
		if (y-r < 1 && (x+r)-n > 0) sum+=-(y-r-1)*((x+r)-n); 
		if (y-r < 1 && x-r < 1) sum+=-(y-r-1)*(-(x-r-1));
		

	}

	cout << sum/(n*m) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

