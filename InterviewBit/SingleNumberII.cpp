int Solution::singleNumber(const vector<int> &A) {
    vector<int> v(32);
    int ret = 0;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < 32; j++) {
            if(A[i] & (1 << j))
                v[j]++;
        }
    }
    for(int i = 0; i < 32; i++) {
        if(v[i] % 3 == 1)
            ret += (1 << i);
    }
    return ret;
}

