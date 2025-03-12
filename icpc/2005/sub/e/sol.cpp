#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

ll converte(ll d, string s) {
	if (s == "Gb") {
		d <<= 20;
	} else if (s == "Mb") {
		d <<= 10;
	}
	return d;
}

struct Arq {
	bool free;
	string nome;
	ll ini;
	ll tam;
};

bool err;

vector<Arq> disco;

void rm0() {
	for (auto it = disco.begin(); it != disco.end();) {
		if (it->tam == 0) {
			it = disco.erase(it);
		} else {
			++it;
		}
	}
}

void join_blanks() {
	for (int i = 1; i < disco.size(); ++i) {
		if (disco.at(i).free && disco.at(i-1).free) {
			disco.at(i).tam += disco.at(i-1).tam;
			disco.at(i).ini = disco.at(i-1).ini;
			disco.at(i-1).tam = 0;
		}
	}
	rm0();
}

void otimize() {
	for (int i = 1; i < disco.size(); ++i) {
		if (disco.at(i-1).free) {
			if (disco.at(i).free) {
				disco.at(i).tam += disco.at(i-1).tam;
				disco.at(i).ini = disco.at(i-1).ini;
				disco.at(i-1).tam = 0;
			} else {
				swap(disco.at(i-1), disco.at(i));
				disco.at(i-1).ini = disco.at(i).ini;
				disco.at(i).ini = disco.at(i-1).ini + disco.at(i-1).tam;
			}
		}
	}
	rm0();
}

bool ins(string nome, ll t) {
	//cerr << "ins " << nome << ' ' << t << '\n';
	auto mn = disco.begin();
	ll mnt = LLONG_MAX;
	for(auto arq = disco.begin(); arq != disco.end(); ++arq) {
		if (arq->free && arq->tam >= t) {
			if (arq->tam < mnt) {
				mn = arq;
				mnt = arq->tam;
			}
		}
	}
	if (mnt < LLONG_MAX) {
		auto arq = mn;
		arq = disco.insert(arq, {false, nome, arq->ini, t});
		++arq;
		arq->ini += t;
		arq->tam -= t;
		//cerr << arq->nome << ' ' << arq->ini << ' ' << arq->tam << '\n';
		rm0();
		return true;
	}
	return false;
}

void insert(string nome, ll t) {
	if (!ins(nome, t)) {
		otimize();
		if (!ins(nome, t)) err = true;
	}
}

// lembrar de extender bloco de livre se remover um sucessor
void remove(string nome) {
	for (int i = 0; i < disco.size(); ++i) {
		if (disco.at(i).nome == nome) {
			disco.at(i).free = true;
			join_blanks();
			break;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (true) {
		int n;
		cin >> n;
		if (!n) break;
		ll d;
		disco.clear();
		err = false;
		string s;
		string aux;
		cin >> aux;
		s = aux.substr(aux.size()-2);
		d = stoll(aux.substr(0, aux.size()-2));

		d = converte(d,s);
		disco.push_back({true, "", 0, d});
		for (int i = 0; i < n; ++i) {
			string command;
			cin >> command;
			if (command == "insere") {
				string nome, tp;
				ll t;
				cin >> nome >> aux;
				tp = aux.substr(aux.size()-2);
				t = stoll(aux.substr(0, aux.size()-2));
				t = converte(t, tp);
				insert(nome, t);
			} else if (command == "remove") {
				string nome;
				cin >> nome;
				remove(nome);
			} else {
				otimize();
			}
		}
		if (err) {
			cout << "ERRO: disco cheio\n";
			continue;
		}
		array<ll, 8> ans;
		fill(ans.begin(), ans.end(), 0);
		int i = 0;
		for (Arq arq : disco) {
			if (arq.free) {
				while (arq.ini + arq.tam >= d/8*i) {
					if (i == 8) break;
					//cerr << "arq ini " << arq.ini <<' ' <<  d/8*i << '\n';
					if (arq.ini >= d/8*(i+1)) {
						//cerr << "saindo com i " << i << '\n';
						++i; continue;
					}
					if (arq.ini + arq.tam <= d/8*(i+1)) {
						ans.at(i) += arq.tam - (max(d/8*i-arq.ini, 0LL));
						//cerr <<  arq.tam - (max(d/8*i-arq.ini, 0)) << '\n';
						break;
					} else {
						ans.at(i) += d/8*(i+1)-max(arq.ini, d/8*i);
						++i;
					}
				}
			}
		}

		//for (int i = 0; i < 8; ++i) cerr << ans.at(i) << ' ';
		//cerr << '\n';

		for (int i = 0; i < 8; ++i) {
			cout << "[";
			ll p = 100LL*ans.at(i)/(d/8);
			//cerr << p << ' ' << ans.at(i) << ' ' << d/8;
			if (100LL*ans.at(i)%(d/8)) ++p;
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
