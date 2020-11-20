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
		// cout << 2 << " ";
		primes[0] = 2;
		for (int i = 3; i <= 1120; i += 2) {
			if (P[i]) {
				// cout << i << " ";
				primes[limit++] = i;
			}
		}
		// cout << endl << cnt << endl;
	};
	genPrimes();
	//for (int i = 0; i < limit; ++i) cout << primes[i] << " "; 
	//cout << endl;
	int bin[limit] = {0};
	int dp[1125][188][15];
	memset(dp, -1, sizeof dp);
	function<int(int, int, int)> findSum = [&](int idx, int taken, int sum) {			
		if (taken < 0) return 0;
		if (sum < 0) return 0;
		if (dp[sum][idx][taken] != -1) {
			// cout << "hit" << idx << " " << taken << " " << sum << endl;
			return dp[sum][idx][taken];
		}	
		if (sum == 0) {
			if (taken) return 0;
			//for (int i = 0; i < limit; ++i) {
				//if (bin[i]) cout << primes[i] << " ";
			//}
			//cout << endl;
			return dp[sum][idx][taken] = (taken == 0) ? 1 : 0;
		}
		if (idx >= limit) return 0;		
		bin[idx] = 1;
		int left = findSum(idx + 1, taken - 1, sum - primes[idx]);
		bin[idx] = 0;
		int right = findSum(idx + 1, taken, sum);
		return dp[sum][idx][taken] = left + right;
	};
	while (cin >> n >> k, n + k) {
		cout << findSum(0, k, n) << endl;	 
	}
}
int main() {
	solve();
	return 0;
}