#include<bits/stdc++.h>
using namespace std;
// 4 + 12 + 20 + 28 + ..
void recur(int s, int ans, int n) {
	if (s > n) cout << ans << endl;
	else recur(s + 1, ans + 4 * (2 * s - 1), n);
}
int main() {
	int n;
	cin >> n;
	recur(1, 0, n);	
}