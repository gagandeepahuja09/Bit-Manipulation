#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vi>
#define read(a)  for(int i = 0; i < n; i++) cin >> a[i];
#define print(a)  for(int i = 0; i < n; i++) cout << a[i] << " ";

signed main() {
    int t = 1;
    // cin >> t
    while(t--) {
        int n, pos = 0;
        cin >> n;
        vi a(n);
        read(a);
        for(int i = 31; i >= 0; i--) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(a[j] & (1 << i)) {
                    cnt++;
                    pos = j;
                }
            }
            if(cnt == 1)
                break;
        }
        swap(a[0], a[pos]);
        print(a);
        cout << endl;
    }
}
