#include<bits/stdc++.h>
using namespace std;
// 1 * 2 + 2 * 3 + 3 * 4 + ..
void recur(int cnt, int s, int ans, int n) {
	if (cnt > n) cout << ans << endl;
	else recur(cnt + 1, s, ans + cnt * (cnt + 1), n);
}
int main() {
	int n;
	cin >> n;
	recur(1, 2, 0, n);	
}