#include<bits/stdc++.h>
using namespace std;
// 2 + 5 + 8 + 11 + ..
void recur(int cnt, int s, int ans, int n) {
	if (cnt > n) cout << ans << endl;
	else recur(cnt + 1, s + 3, ans + s, n);
}
int main() {
	int n;
	cin >> n;
	recur(1, 2, 0, n);	
}