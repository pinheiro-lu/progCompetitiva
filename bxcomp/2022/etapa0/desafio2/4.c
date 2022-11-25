#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define dbg(args...) //printf(args);
#define dbgi(args) //printf(#args); printf(" = %ld\n", args);
#define dbgf(args) printf(#args); printf(" = %lf\n", args);

typedef long long ll;

void solve() {
	char s[10];
	int n;
	int vi, li, la, ag;

	scanf("%s %i", s, &n);

	if (strcmp(s, "vinho") == 0) {
		vi = n;
		li = n * 45 / 1000;
		la = n * 240 / 1000;
		ag = n * 500 / 1000;
	} else if (strcmp(s, "limao") == 0) {
		li = n;
		vi = n * 1000 / 45;
		la = n * 240 / 45;
		ag = n * 500 / 45;
	} else if (strcmp(s, "laranja") == 0) {
		la = n;
		vi = n * 1000 / 240;
		li = n * 45 / 240;
		ag = n * 500 / 240; 
	} else {
		ag = n;
		vi = n * 1000 / 500;
		li = n * 45 / 500;
		la = n * 240 / 500;
	}

	printf ("%d %d %d %d\n", vi, li, la, ag);
}

int main () {
	
	int t;
	
	scanf("%d", &t);
	
	while (t--)
		solve();
		
	return 0;
}
