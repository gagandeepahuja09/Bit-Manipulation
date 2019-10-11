/*Given two Integer A and B. Find a number X such that A xor X is minimum possible
and number of set bits in X equals to B.
*/

int Solution::solve(int A, int B) {
    int X = 0;
    if(!B)
        return X;
    for(int i = 31; i >= 0; i--) {
        if(A & (1 << i)) {
            X += (1 << i);
            B--;
        }
        if(!B)
            return X;
    }
    if(B) {
        for(int i = 0; i < 32; i++) {
            if((A & (1 << i)) == 0) {
                X += (1 << i);
                B--;
            }
            if(!B)
                return X;
        }
    }
    return X;
}

