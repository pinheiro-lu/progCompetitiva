#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) //printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	int n;

    cin >> n;

    int fat[n+10];

    int i = 1;
    fat[1] = 1;
    int max = i; 
    while (fat[i] <= n) {
        fat[i+1] = fat[i] * i;
        i++;
        max++;
    }

    i = max;
    int soma = 0, k = 0;
    
    while (soma < n) {
        if (soma + fat[i] <= n) {
            k++;
            soma += fat[i];
            dbg("soma = %d\n", soma);
        } else i--;
    }

    cout << k << endl;

}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	
    //cin >> t;
	//scanf("%d", &t);
//	while (getchar() != '\n');

	while (t--)
		solve();
		
	return 0;
}
