#define ll long long int

int Solution::divide(int A, int B) {
    ll ret = 0;
    if(A == INT_MIN && B == -1)
        return INT_MAX;
    if(B == 1)
        return A;    
    ll sign = A > 0 ^ B > 0 ? -1 : 1;    
    ll lA = labs(A), lB = labs(B);
    while(lA >= lB) {
        ll temp = lB, cnt = 1;
        while((temp << 1) <= lA) {
            temp <<= 1;
            cnt <<= 1; 
        }
        lA -= temp;
        ret += cnt;
    }
    return (int)sign * ret;
}

