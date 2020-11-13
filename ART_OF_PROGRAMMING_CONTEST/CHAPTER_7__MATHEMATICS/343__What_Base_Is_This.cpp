#include<bits/stdc++.h>
using namespace std;
long long _pow(int base, int power) {
    long long a = base;
    long long ret = 1;
    while (power > 0) {
        if (power & 1) ret *= a;
        a = a * a;
        power >>= 1;
    }
    return ret;
}
long long convertUtil(string number, int base) {
    int power = (int) number.length() - 1;
    long long ret = 0;
    for (int i = 0; i < (int) number.length(); ++i) {
        int val = 0;
        if (number[i] >= 'A' and number[i] <= 'Z') val = number[i] - 'A' + 10;
        else val = number[i] - '0';
        ret += val * _pow(base, power) * 1LL;
        power--;
    }
    return ret;
}
vector<pair<long long, int>> convert(string number) {
    int _max = -1;
    vector<pair<long long, int>> ans;
    for (int i = 0; i < (int) number.length(); ++i) {
        if (number[i] > _max) _max = number[i];
    }
    if (_max >= 'A' and _max <= 'Z') {
        _max = _max - 65 + 11;         
    } else _max = _max - 48 + 1;
    _max = max(_max, 2);
    for (int i = _max; i <= 36; ++i) {
        ans.push_back({convertUtil(number, i), i});
    }
    return ans;
}
void solve() {
    string X, Y;
    while (cin >> X >> Y) {
        vector<pair<long long, int>> x = convert(X);
        vector<pair<long long, int>> y = convert(Y);
        map<long long, int> has;
        for (int i = 0; i < (int) x.size(); ++i) {
            // cout << x[i].second << " ";
            if (!has[x[i].first])
               has[x[i].first] = x[i].second;
        }
        bool flag = false; 
        for (int i = 0; i < (int) y.size(); ++i) {
            // cout << y[i] << " ";
            if (has[y[i].first]) {
                cout << X << " (base " << has[y[i].first] << ") = " << Y << " (base " << y[i].second << ")" << "\n";
                flag = true;
                break;
            }
        } 
        if (!flag) {
            cout << X << " is not equal to " << Y << " in any base 2..36" << "\n";                
        }
    }    
}
int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
