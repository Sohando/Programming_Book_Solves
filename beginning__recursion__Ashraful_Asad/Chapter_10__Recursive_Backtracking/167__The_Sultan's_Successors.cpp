#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> board(8, vector<int>(8));
int _max = -1000000;
int rows[8];
int cols[8];
int ldia[20];
int rdia[20];
bool isPlaceAble(int r, int c) {	
	return (!rows[r] and !cols[c]) and (!ldia[r - c + 8 - 1] and !rdia[r + c]);
}
void play(int row, int col, int sum) {
	if (row >= 8) _max = max(_max, sum);
	for (int c = 0; c < 8; ++ c) {
		if (isPlaceAble(row, c)) {			
			cols[c] = rows[row] = 1;
			ldia[row - c + 8 - 1] = rdia[row + c] = 1;
			play(row + 1, c, sum + board[row][c]);
			cols[c] = rows[row] = 0;
			ldia[row - c + 8 - 1] = rdia[row + c] = 0;
		}
	}
}
void solve() {	
	for (int r = 0; r < 8; ++r) {
		for (int c = 0; c < 8; ++c) {
			cin >> board[r][c];
		}
	}
	memset(rows, 0, sizeof rows);
	memset(cols, 0, sizeof cols);
	memset(ldia, 0, sizeof ldia);
	memset(rdia, 0, sizeof rdia);
	play(0, 0, 0);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	for (int cas = 1; cas <= k; ++cas) {
		_max = -1;
		solve();
		// cout << _max << '\n';
		printf("%5d\n", _max);
	}
}
 