#include<bit/stdc++.h>
using namespace std;
int dp[300][20000];
void solve() {
  int n;
  cin >> n;
	ferryLen = n * 100;
	cars.clear();
	memset(dp, -1, sizeof dp);
	while (cin >> n, n) {
		cars.push_back(n);
	}
	flag = 0;
	lim = (int)cars.size();
  auto cal = [&]() {
    for (int i = 0; i < lim; ++i) {

    } 
  };
	cout << flag << "\n"; 
	for (int i = 0; i < flag; ++i) {
		(ans[i] == 0) ? cout << "port\n" : cout << "starboard\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas) {	
		solve();
		if (cas != T) cout << "\n";
	}
}
