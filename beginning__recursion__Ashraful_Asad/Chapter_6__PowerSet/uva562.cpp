#include<bits/stdc++.h>
using namespace std;
int N, A[100], S[100], sum, mini = INT_MAX, dp[101][500001];
void read() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> S[i];
	}
}
int solve(int index, int sum1) {
	if (index == N) {
		int sum2 = abs(sum - sum1);
		// cout << sum1 << " " << sum2 << endl;
		return abs(sum2 - sum1);
	}
	if (dp[index][sum1] != -1) return dp[index][sum1];
	A[index] = 0;
	int left = solve(index + 1, sum1);
	A[index] = 1;
	int right = solve(index + 1, sum1 + S[index]);
	return dp[index][sum1] = min(left, right);
}
int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		read();
		memset(dp, -1, sizeof dp);
		sum = accumulate(S, S + N, 0);
		int ans = solve(0, 0);
		cout << ans << "\n";
	}
	return 0;
}