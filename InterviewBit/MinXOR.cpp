int Solution::findMinXor(vector<int> &A) {
    int ret = INT_MAX;
    sort(A.begin(), A.end());
    for(int i = 1; i < A.size(); i++) {
        ret = min(ret, A[i] ^ A[i - 1]);
    }
    return ret;
}

