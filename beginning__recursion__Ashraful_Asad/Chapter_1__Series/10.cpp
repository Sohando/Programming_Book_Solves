#include<bits/stdc++.h>
using namespace std;
// 1 * 1^2 + 2 * 3^2 + 3 * 5^2 + ...
void recur(int cnt, int s, int ans, int n) {
	if (cnt > n) cout << ans << endl;
	else recur(cnt + 1, s + 3, ans + s * (2 * cnt - 1), n);
}
int recursion(int i, int n) {
	if (i > n) return 0;
	else return i * (2 * i - 1) * (2 * i - 1) + recursion(i + 1, n);
}
int main() {
	int n;
	cin >> n;
	// recur(1, 2, 0, n);	
	recursion(1, n);
}