#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

void converte(int &d, string s) {
	if (s == "Mb") d <<= 10;
	else if (s == "Gb") d <<=20;
}

vector<pair<string, bool>> disco;
bool err;

void optimize() {
	for (int j = 0; j < disco.size(); ++j)
		for (int i = 0; i < disco.size()-1; ++i) {
			if (!disco.at(i).second) swap(disco.at(i), disco.at(i+1));
		}
}

void insert(string arq, int t) {
	int cnt = 0, st = 0;
	set<pair<int, int>> s;
	for (int i = 0; i < disco.size(); ++i) {
		if (disco.at(i).second) {
			if (cnt >= t) s.insert({cnt, st});
			cnt = 0;
			st = i+1;
		} else { 
			cnt++;
		}
	}
	if (cnt >= t) {
		s.insert({cnt, st});
		//cerr << cnt << ' ' << st << '\n';
	}
	if (s.empty())  {
		optimize();
		cnt = 0, st = 0;
		for (int i = 0; i < disco.size(); ++i) {
			if (disco.at(i).second) {
				if (cnt >= t) s.insert({cnt, st});
				cnt = 0;
				st = i+1;
			} else { 
				cnt++;
			}
		}
		if (cnt >= t) s.insert({cnt, st});
	}
	if (s.empty()) {
		//cerr << cnt << ' ' << t << ' ' << st << '\n';
		err = true;
		return;
	}
	//cerr << s.begin() -> f << ' ' << s.begin() -> s << '\n';
	for (int i = s.begin()->s; i < s.begin()->s+t; ++i) {
		disco.at(i).first = arq;
		disco.at(i).second = true;
	}
}

void remove(string arq) {
	for (auto &x : disco) {
		if (x.f == arq) x.s = false;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (true) {
		err = false;
		int n;
		cin >> n;
		if (!n) break;
		int d;
		string s;
		cin >> d >> s;
		converte(d, s);
		disco.assign(d, {"", false});
		//cerr << "assigned\n";
		for (int i = 0; i < n; ++i) {
			string com;
			cin >> com;
			if (com == "insere") {
				string arq, esp;
				int t;
				cin >> arq >> t >> esp;
				converte(t, esp);
				insert(arq, t);
			} else if (com == "remove") {
				string arq;
				cin >> arq;
				remove(arq);
			} else {
				optimize();
			}
		}

		vector<int> ans(8);
		for (int i = 0; i < disco.size(); ++i) {
			ans.at(i*8/d) += !disco.at(i).s;
		}

		if (err) {
			cout << "ERRO: disco cheio\n";
			continue;
		}

		for (int i = 0; i < 8; ++i) {
			cout << '[';
			//cerr << ans.at(i);
			double p = 100.0*ans.at(i)/((double)d/8.0);
			
			if (p > 75) {
				cout << ' ';
			} else if (p > 25) {
				cout << '-';
			} else {
				cout << '#';
			}
			cout << ']';
		}
		cout << '\n';
	}
				
	return 0;
}
