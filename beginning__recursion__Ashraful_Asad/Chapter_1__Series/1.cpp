#include<bits/stdc++.h>
using namespace std;
// 1 + 2 + 3 + 4 + ..
void recur(int n, int ans) {
	if (n == 0) cout << ans << endl;
	else recur(n - 1, ans + n);
}
int main() {
	int n;
	cin >> n;
	recur(n, 0);	
}