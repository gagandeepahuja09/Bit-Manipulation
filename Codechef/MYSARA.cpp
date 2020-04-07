#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long n, ret = 1, MOD = 1e9 + 7;
        cin >> n;
        long prev = 0, curr;
        for(int i = 0; i < n; i++) {
            cin >> curr;
            long ans = 1;
            for(int j = 0; j < 32; j++) {
                bool a = (((prev) & (1 << j)) > 0);
                bool b = (((curr) & (1 << j)) > 0);
                if(a == 0) {
                    continue;
                }
                else if(b == 0) {
                    ans = 0;
                }
                else if(b == 1) {
                    ans = (ans * 2) % MOD;
                }
            }
            //cout << ans << endl;
            ret = (ret * ans) % MOD;
            prev = curr;
        }
        cout << ret << endl;
    }
}
