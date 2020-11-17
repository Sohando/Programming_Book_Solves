#include<bits/stdc++.h>
using namespace std;
// 2 + 4 + 6 + ..
void recur(int s, int ans, int n) {
	if (s > n) cout << ans << endl;
	else recur(s + 1, ans + 2 * s, n);
}
int main() {
	int n;
	cin >> n;
	recur(1, 0, n);	
}