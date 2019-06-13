unsigned int Solution::reverse(unsigned int n) {
    unsigned int ans = 0;
    for(int i = 0; i < 32; i++) {
        if(n & (1 << i))
            ans |= (1 << (31 - i));
    }
    return ans;
}

/*unsigned int Solution::reverse(unsigned int n) {
    unsigned int ans = 0;
    int cnt = 32;
    while(n) {
        // left shift(multiply by 2)
        ans <<= 1;
        if(n & 1)
            ans ^= 1;
        // right shift(divide by 2)    
        n >>= 1;
        cnt--;
    }
    ans <<= cnt;
    return ans;
}*/


