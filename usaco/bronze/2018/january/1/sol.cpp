#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct {
	int rx;
	int ty;
	int lx;
	int by;
} Rect;

int calc_area(Rect &cow) {
	if (cow.rx - cow.lx < 0 || cow.ty - cow.by < 0) return 0;
	return ((cow.rx - cow.lx) * (cow.ty - cow.by));
}

void solve() {
	Rect in, out;

	cin >> in.lx >> in.by >> in.rx >> in.ty;
	cin >> out.lx >> out.by >> out.rx >> out.ty;

	Rect cow;

	cow.lx = out.ty >= in.ty && out.by <= in.by && out.lx <= in.lx?
		max(in.lx, out.rx) :
		in.lx;

	cow.by = out.lx <= in.lx && out.rx >= in.rx && out.by <= in.by?
		max(in.by, out.ty) :
		in.by;

	cow.rx = out.ty >= in.ty && out.by <= in.by && out.rx >= in.rx?
		min(in.rx, out.lx) :
		in.rx;

	cow.ty = out.lx <= in.lx && out.rx >= in.rx && out.ty >= in.ty?
		min(in.ty, out.by) :
		in.ty;

	int area = calc_area(cow);

	cout << area << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	while (t--) solve();

	return 0;
}
