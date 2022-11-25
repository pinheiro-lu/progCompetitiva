#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define dbg(args...) //printf(args);
#define dbgi(args) //printf(#args); printf(" = %ld\n", args);
#define dbgf(args) printf(#args); printf(" = %lf\n", args);

typedef long long ll;

#define MAX 10000

char tab[40] = "rx47ziny3p9b01tw2vc8kmdoqjeg5lhfsua6";

char convertChar (char a) {
	if (a >= 'a' && a <= 'z')
		return tab[a - 'a'];
	return tab[26 + a - '0'];
}

void convert (char a[MAX]) {
	for (int i = 0; a[i] != '\0'; i++) {
		a[i] = convertChar(a[i]);
	}
}

void solve() {
	char a[MAX], b[MAX];

	scanf("%s %s", a, b);

	char c[MAX];
	int i, l = 0;
	for (i = 0; a[i] != '\0'; i++) {
		if (b[i] != a[i]) {
			c[l++] = b[i];
		}
	}
	if (b[i] != '\0') {
		for (; b[i] != '\0'; i++) {
			c[l++] = b[i];
		}
	}
	c[l] = '\0';

	convert(c);

	dbg("%s\n%s\n", a, b)
	dbgi(l)

	printf("%s\n", c);
}

int main () {
	
	int t;
	
	scanf("%d", &t);
	
	while (t--)
		solve();
		
	return 0;
}
