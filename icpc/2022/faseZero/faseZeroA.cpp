#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	char nome[21];

	scanf("%[^\n]", nome);
	//fgets(nome, 21, stdin);

	while (getchar() != '\n');

	char line[101];
	fgets(line, 101, stdin);
	
	float n1, n2, n3, n4, nf;
	switch (sscanf (line, "%f %f %f %f", &n1, &n2, &n3, &n4)) {
		case 1:
		nf = n1/2;
		break;
		case 2:
		nf = (n1+n2)/2;
		break;
		case 3:
		nf = (n1 + n2 + n3)/3;
		break;
		case 4:
		float aux = min(n1, n2);
		aux = min(aux, n3);
		nf = (n1 + n2 + n3 - aux + max(aux, n4)) / 3;
		break;
	}

	printf("%s: %.1f\n", nome, nf);
}

int main () {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	
	int t = 1;
	
	scanf("%d", &t);
	while (getchar() != '\n');

	while (t--)
		solve();
		
	return 0;
}
