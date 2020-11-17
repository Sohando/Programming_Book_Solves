#include<bits/stdc++.h>
using namespace std;
// 1 * 3 * 5 * 7 + 3 * 5 * 7 * 9 + ..
int nthOdd(int n) {
	return 2 * n - 1;
}
int recursion(int i, int n) {
	if (i > n) return 0;
	else return nthOdd(i) * nthOdd(i + 1) * nthOdd(i + 2) * nthOdd(i + 3) + recursion(i + 1, n);
}
int main() {
	int n;
	cin >> n;
	recursion(1, n);
}