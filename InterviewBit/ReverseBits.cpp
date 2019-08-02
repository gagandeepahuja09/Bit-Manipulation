unsigned int Solution::reverse(unsigned int A) {
    unsigned int ret = 0;
    for(int i = 0; i < 31; i++) {
        if(A & (1 << i))
            ret += (1 << (32 - i));
    }
    return ret;
}

