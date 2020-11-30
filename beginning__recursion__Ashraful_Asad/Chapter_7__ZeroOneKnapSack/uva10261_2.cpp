#include<bits/stdc++.h>
using namespace std;
vector<int> cars;
int flag;
int bin[10000], ans[10000];
int dp[300][30000];
int ferryLen, lim;
int load(int idx, int lTaken, int taken) {	
	if (idx > lim) return 0;	
	if (dp[idx][lTaken] != -1) {
		return dp[idx][lTaken];
	}
	if (idx > flag) {
		flag = idx;
		for (int i = 0; i < idx; ++i) {
			ans[i] = bin[i];
		}
	}
	int left = 0, right = 0;
	if (lTaken + cars[idx] <= ferryLen) {
		bin[idx] = 0;
		left = cars[idx] + load(idx + 1, lTaken + cars[idx], taken + cars[idx]);
	}
	int rTaken = taken - lTaken;
	if (rTaken + cars[idx] <= ferryLen) {
		bin[idx] = 1;
		right = cars[idx] + load(idx + 1, lTaken, taken + cars[idx]);
	}
	// ans[idx] = (left <= right) ? 0 : 1;
	return dp[idx][lTaken] = max(left, right);
}
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
	load(0, 0, 0);
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