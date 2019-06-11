/*Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?*/

int Solution::singleNumber(const vector<int> &A) {
    vector<int> v(32, 0);
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < 32; j++) {
            if(A[i] & (1 << j))
                v[j]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < 32; i++) {
        if(v[i] % 3 == 1)
            ans += (1 << i);
    }
    return ans;
}


