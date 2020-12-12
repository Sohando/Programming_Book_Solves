#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0)
#define ff first
#define ss second 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int bin[1007][3901];
void solve(int N) {
  vii st(N);
  for (auto &i : st) {
    cin >> i.ff >> i.ss;
  }
  memset(bin, -1, sizeof bin);
  function<int(int, int)> DP = [&](int idx, int maxLoad) {
  	if (idx == N) {
  		//for (int i = 0; i < idx; ++i) {
  			// if (bin[i] == 1) cout << st[i].ff << " ";
  		//} //cout << endl;
  		return 0;
  	}
  	if (bin[idx][maxLoad] != -1) return bin[idx][maxLoad];
  	int l = 0, r = 0;
  	if (maxLoad == INT_MAX) {
  		// bin[idx] = 1;
  		l = 1 + DP(idx + 1, st[idx].ss);
  	} else if (maxLoad - st[idx].ff >= 0) {
			// bin[idx] = 1;
			// cout << idx << " " << maxLoad -st[idx].ff << endl;
			l = 1 + DP(idx + 1, min(maxLoad - st[idx].ff, st[idx].ss));
		}
		// bin[idx] = 0;
		r = DP(idx + 1, maxLoad);
		return bin[idx][maxLoad] = max(l, r);
  };
  int ans = DP(0, 3007);
  cout << (ans ? ans : 1) << '\n';
}
int main() {
  fast;
  int N;
  while (cin >> N, N) {
    solve(N);
  }
  return 0;
}
