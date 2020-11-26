#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n, k;
	int P[1121], primes[200], limit = 0;
	auto genPrimes = [&]() {
		memset(P, 1, sizeof P);
		limit++;
		for (int i = 3; i * i <= 1120; i += 2) {
			if (P[i]) {
				for (int j = i * i; j <= 1120; j += (i + i)) {
					P[j] = 0;
				}
			}
		};
		primes[0] = 2;
		for (int i = 3; i <= 1120; i += 2) {
			if (P[i]) {
				primes[limit++] = i;
			}
		}
	};
	int dp[1120 + 1][14 + 1];
	auto precal = [&]() {
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 0; i < limit; ++i) {
			for (int j = 1120; j >= primes[i]; --j) {
				for (int x = 1; x <= 14; ++x) {
					dp[j][x] += dp[j - primes[i]][x - 1];
				}
			}
		}
	};
	genPrimes();
	precal();
	while (cin >> n >> k, n + k) {
		cout << dp[n][k] << "\n";
	}
}
int main() {
	solve();
	return 0;
}