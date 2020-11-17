#include<bits/stdc++.h>
using namespace std;
// 1 * 2^2 + 2 * 3^2 + 3 * 4^2 + ..
int recursion(int i, int n) {
	if (i > n) return 0;
	else return i * (i + 1) * (i + 1) + recursion(i + 1, n);
}
int main() {
	int n;
	cin >> n;
	recursion(1, n);
}