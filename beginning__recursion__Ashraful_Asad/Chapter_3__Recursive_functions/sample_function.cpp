#include<bits/stdc++.h>
using namespace std;
int N, A[100];
void read() {
	cin >> N;
}
void solve(int index) {
	if (index == N) return;
	A[index] = 123;
	solve(index + 1);
}
void print(int index) {
	if (index == N) return;
	cout << A[index] << "\n";
	print(index + 1);
}
int main() {
	read();
	solve(0);
	print(0);
}