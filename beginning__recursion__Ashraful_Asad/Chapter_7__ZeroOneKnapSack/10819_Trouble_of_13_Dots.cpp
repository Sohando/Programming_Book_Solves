#include<bits/stdc++.h>
using namespace std;
int dp[110][10010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int M, N;
  auto solve = [&]() {
    vector<pair<int, int>> vi;
    for (int i = 0, x, y; i < N; ++i) {
      cin >> x >> y;
      vi.push_back({x, y});
    }
    memset(dp, -1, sizeof dp);
    // index, amount
    function<int(int, int)> play = [&](int idx, int amount) {
      if (amount > M + 200) return -100;
      if (idx == N) {        
        // cout << "amount" << amount << endl;
        if (amount <= M) return 0;        
        if (amount > 2000 and amount <= M + 200) return 0;
        return -100;
      }
      if (dp[idx][amount] != -1) return dp[idx][amount];      
      int l = 0, r = 0;
      int pay = amount + vi[idx].first; 
      if (pay <= M + 200) {
        l = vi[idx].second + play(idx + 1, pay);
      } else l = -100;
      r = play(idx + 1, amount);
      return dp[idx][amount] = max(l, r);
    };
    int ans = play(0, 0);
    cout << ans << "\n";
  };
  while (cin >> M >> N) {
    solve();
  }
  return 0;
}
