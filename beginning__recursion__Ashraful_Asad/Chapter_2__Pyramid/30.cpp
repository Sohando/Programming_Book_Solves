#include<bits/stdc++.h>
using namespace std;
// 				1
//			2	2
// 		3	3	3
//			2	2
// 				1
void recursion3(int i, int j) {
	if (i > j) {
		cout << "\n";
		return;
	}
	printf("%d ", j);
	recursion3(i + 1, j);
}
void recursion2(int i, int j) {
	if (i > j) {		
		return;
	}
	printf("  ");
	recursion2(i + 1, j);
}
void recursion(int i, int n) {
	if (i > n) return;
	recursion2(i, n);
	recursion3(1, i);
	recursion(i + 1, n);
	recursion2(i - 1, n);
	recursion3(1, i - 1);
}
int main() {
	int n;
	cin >> n;
	recursion(1, n);
}