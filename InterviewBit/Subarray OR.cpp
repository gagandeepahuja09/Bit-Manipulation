#define MOD 1000000007
#define ll long long int
/*
SUBARRAY OR

Given an array of integers A of size N.

Value of a subarray is defined as BITWISE OR of all elements in it.

Return the sum of Value of all subarrays of A % 10^9 + 7
*/

int Solution::solve(vector<int> &A) {
    ll sum = 0;
    ll n = A.size(), ans = 0;
    for(int i = 0; i < 32; i++) {
        ll t = 0, currs = 0;
        for(int j = 0; j < n; j++) {
            if((A[j] & (1 << i)) == 0) {
                t++;
            }
            else {
                currs += ((t) * (t + 1) / 2);
                t = 0;
            }
        }
        currs += ((t) * (t + 1) / 2);
        ans += (((1 << i) % MOD * ((n * (n + 1) / 2) % MOD - currs % MOD + MOD) % MOD) % MOD) % MOD;
        ans %= MOD;
    }
    return ans ;
}

