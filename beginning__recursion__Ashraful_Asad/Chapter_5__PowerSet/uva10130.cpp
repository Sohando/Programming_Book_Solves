#include<bits/stdc++.h>
using namespace std;
struct Products {
	int W; int P;
} item[1001];
int dp[1001][31];
int SuperSale(int idx, int N, int limit) {
	if (idx >= N) return 0;	
	// cout << idx << " " << taken << " " << limit << " " << dp[idx][limit] << endl;
	if (dp[idx][limit] != -1) {
		// cout << "dictonary: " << idx << " " << dp[idx][limit] << endl;
		return dp[idx][limit];
	}
	// if (limit <= 0) return taken;	
	int left = 0, right = 0;
	if (limit - item[idx].W >= 0)
		left = item[idx].P + SuperSale(idx + 1, N, limit - item[idx].W);
	right = SuperSale(idx + 1, N, limit);
	dp[idx][limit] = max(left, right);
	// cout << idx << " " << limit << " " << dp[idx][limit] << endl;
	return dp[idx][limit];
}
void solve() {
	int n, t;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> item[i].P >> item[i].W;
	}
	int ans = 0;
	cin >> t;
	for (int i = 0, x; i < t; ++i) {
		cin >> x;
		int ret = SuperSale(0, n, x);
		// cout << x << " " << ret << endl;
		ans += ret;
	}
	cout << ans << "\n";
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		// cout << "Case: " << T << endl;
		memset(dp, -1, sizeof dp);
		solve();
	}
	return 0;
}