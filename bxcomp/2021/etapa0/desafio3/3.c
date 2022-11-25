#include <stdio.h>
#include <stdlib.h>

#define dbg(args...) //printf(args);
#define dbgi(args) printf(#args); printf(" = %ld\n", args);
#define dbgf(args) printf(#args); printf(" = %lf\n", args);

typedef long long ll;
typedef int bool;

#define true 1
#define false 0

int x, y, z;

bool ver (char a[3][3], char b) {

	for (int i = 0; i < 3; i++) {
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][2] == b) {
			a[i][0] = a[i][1] = a[i][2] = 'X';
			x = i * 10; y = i * 10 + 1; z = i * 10 + 2;
			return true;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[2][i] == b) {
			a[0][i] = a[1][i] = a[2][i] = 'X';
			x = i; y = i + 10; z = i + 20;
			return true;
		}
	}

	if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] == b) {
		a[0][0] = a[1][1] = a[2][2] = 'X';
		x = 0; y = 11; z = 22;
		return true;
	}

	if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[2][0] == b) {
		a[0][2] = a[1][1] = a[2][0] = 'X';
		x = 2; y = 11; z = 20;
		return true;
	}

	return false;
}

void solve(void) {
	// char ** a = (char **) malloc(sizeof(char *) * 3);

	// a[0] = (char * ) malloc (sizeof(char) * 3);
	// a[1] = (char * ) malloc (sizeof(char) * 3);
	// a[2] = (char * ) malloc (sizeof(char) * 3);
	
	char a[3][3];
	
	bool perdeu = false;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	
	dbg("oi\n");

	perdeu = ver(a, 'O');
	
	if (perdeu) {
		puts("Tic-Tac de cereja eh bom tambem");
		return;
	}

	bool ganhou = ver(a, 'V');

	if (!ganhou) {
		puts("Bora outra valendo os dois Tic-Tac ?");
		return;
	}

	puts ("Hora de tirar o bafo");
	printf("%d-%d-%d\n", x+11, y+11, z+11);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c ", a[i][j]);
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
