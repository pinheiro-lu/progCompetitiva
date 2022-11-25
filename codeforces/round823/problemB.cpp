#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100000000

void solve (void) {
	int n;
	
	scanf("%d", &n);
	
	int x[n];
	int t[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}
	
	int l = -1, r = MAX, mxl = 0, mnr = MAX;
	while (r - l > 1) {
		int m = (r + l) / 2;
		
		for (int i = 0; i < n; i++) {
			if (t[i] > m) {
				mxl = MAX;
				mnr = 0;
				break;
			}
			mxl = max(mxl, x[i] - m + t[i]);
			mnr = min(mnr, x[i] + m - t[i]);
		}
		
		if (mxl <= mnr) r = m;
		else l = m;
	}
	
	mxl = 0;
	mnr = MAX;
	
	for (int i = 0; i < n; i++) {
		mxl = max(mxl, x[i] - r + t[i]);
		mnr = min(mnr, x[i] + r - t[i]);
	}
	double ans = (double)(mxl + mnr) / 2.0;
	printf("%.7lf\n", ans);
	
	//printf("max: %d, min: %d\n", interMax, interMin);
	
}

int main () {
	int T;
	
	scanf("%d", &T);
	
	while (T--)
		solve();
	
	return 0;
}
