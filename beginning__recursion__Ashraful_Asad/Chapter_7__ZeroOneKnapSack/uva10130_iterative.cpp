#include<bits/stdc++.h>
using namespace std;
void solve() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		int n;
		cin >> n;
		int P[n + 1], W[n + 1], maxw = -1;
		for (int i = 1; i <= n; ++i) {
			cin >> P[i] >> W[i];
		}
		int dp[n + 1][30 + 1];
		auto precal = [&](int N) {
			// cout << maxw << endl;
			for (int i = 0; i <= N; ++i) {
				dp[i][0] = 0;
			}
			for (int i = 0; i <= maxw; ++i) {
				dp[0][i] = 0;
			}
			for (int i = 1; i <= N; ++i) {
				for (int w = 1; w <= maxw; ++w) {
					dp[i][w] = dp[i - 1][w];
					if (w >= W[i] and dp[i][w] < P[i] + dp[i - 1][w - W[i]]) {
						dp[i][w] = P[i] + dp[i - 1][w - W[i]];
					}
				}
			}
		};	
		int q;
		cin >> q;
		int ans = 0;
		int Q[q];
		for (int i = 0; i < q; ++i) {
			cin >> Q[i];
			maxw = max(maxw, Q[i]);
		}
		// cout << maxw << endl;
		precal(n);
		for (int i = 0; i < q; ++i) {
			// cin >> x;
			ans += dp[n][Q[i]];
		}
		cout << ans << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}