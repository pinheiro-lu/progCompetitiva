#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define dbg(args...) printf(args);
#define dbgi(args) //printf(#args); printf(" = %ld\n", args);
#define dbgf(args) printf(#args); printf(" = %lf\n", args);

typedef long long ll;

void solve() {
	char s[200];

	scanf("\n%[^\n]", s);

	char v[10];

	strcpy(v, &s[strlen(s)-strlen("Circulou")]);

	//dbg("%s\n%s", v, s);

	char *c = strrchr(v, 'C');

	if (!c || strcmp(c, "Circulou") == 0 || !strstr(c, "Cir")) {
		puts("Taaaao maravilhoso nosso amoor");
	} else {
		printf("%s", s);
		for (int i = strlen(c); i < strlen("Circulou"); i++) {
			printf("Circulou");
		}
		puts("");
	}
}

int main () {
	
	int t;
	
	scanf("%d", &t);
	
	while (t--)
		solve();
		
	return 0;
}
