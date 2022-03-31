#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

using tt = vector <int>;

int median (tt a) {
    sort(a.begin(), a.end());
    int n = sz(a);
    return a[(n + 1) / 2 - 1];
}

int main () {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        tt a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        queue <tt> q;
        map <tt, int> mp;
        q.push(a);
        mp[a] = 0;
        int ans = 0;
        while (!q.empty()) {
            tt u = q.front(); q.pop();
            int f = 1;
            for (int i = 1; i < n; ++i) {
                f &= (u[i] == u[i - 1]);
            }
            if (f) {
                ans = mp[u];
                break;
            }
            for (int l = 0; l < n; ++l) {
                tt v, cur;
                for (int i = 0; i < l; ++i) v.push_back(u[i]);
                for (int r = l; r < n; ++r) {
                    if (l == 0 && r == n - 1) continue;
                    cur.push_back(u[r]);
                    int x = median(cur);
                    for (int i = l; i <= r; ++i) v.push_back(x);
                    for (int i = r + 1; i < n; ++i) v.push_back(u[i]);
                    if (mp.find(v) == mp.end()) {
                        mp[v] = mp[u] + 1;
                        q.push(v);
                    }
                    for (int i = r + 1; i < n; ++i) v.pop_back();
                    for (int i = l; i <= r; ++i) v.pop_back();
                }
            }
        }
        cout << ans << '\n';
    }
}