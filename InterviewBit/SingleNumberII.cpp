/*Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?*/

int Solution::singleNumber(const vector<int> &A) {
    vector<int> v(32, 0);
    for(int i = 0; i < A.size(); i++) {
        int num = A[i];
        for(int j = 31; j >= 0; j--) {
            v[j] += (num & 1);
            num >>= 1;
            if(!num)
                break;
        }
    }
    int ans = 0;
    for(int i = 31; i >= 0; i--) {
        int x = v[i] % 3;
        if(x == 1)
            ans += (1 << (31 - i));
    }
    return ans;
}

