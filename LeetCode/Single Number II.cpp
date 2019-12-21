class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        vector<int> v(32, 0);
        for(int i = 0; i < 32; i++) {
            for(int n : nums) {
                if(n & (1 << i))
                    v[i]++;
            }    
        }
        for(int i = 0; i < 32; i++) {
            if(v[i] % 3 == 1) {
                ans += (1 << i);
            }    
        }
        return ans;
    }
};
