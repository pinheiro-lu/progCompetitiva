#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define pii pair<int,int>
#define INF 1000000000
#define all(x) x.begin(), x.end()
#define IOS ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
#define int long long // PROIBIDO EM 27 PAISES
typedef vector<int> vi;
typedef vector<long long> vll;

void testcases() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

bool isNumber(char c) {
    string numbers = "0123456789";
    for (auto x : numbers) {
        if (c == x) return true;
    }
    return false;
}

string transform(string s) {
    string ans = "";
    for (auto x : s) {
        if (isNumber(x)) {
            ans+=x;
        }
    }
    // cout << ans << '\n';
    return (ans);
}

void solve() {
    int n;cin>>n;
    char c;
    string curr = "";
    string s;
    vector<string> text;
    while (cin >> s) {
        text.pb(s);
    }
    vector<string> v;
    v.pb(text[0]);
    for (int i = 1; i < text.size(); i++) {
        string last = text[i-1];
        string curr = text[i];
        if (isNumber(last[last.size()-1]) && isNumber(curr[0])) {
            if (v.size() != 0) {
                v.pop_back();    
            }
            v.pb(last+curr);
        } else {
            v.pb(curr);
        }
    }
    vector<int> v1;
    for (auto x : v) {
        string t = transform(x);
        if (t != "") {
            int num = stoll(t);
            v1.pb(num);
        }
    }
    for (int i = 0; i < v1.size()-2; i++) {
        if (v1[i] + 1 == v1[i+1] && v1[i+1] == v1[i+2] - 1) {
            cout << "123" << '\n';
            return;
        }
    }   
    cout << ":)" << '\n';
}

signed main() {

    // testcases();
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}
