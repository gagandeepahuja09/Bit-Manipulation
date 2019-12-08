class Solution {
public:
    int findComplement(int A) {
        int i = 31;
        for(i = 31; i >= 0; i--) {
            if(A & (1 << i))
                break;
        }
        int ans = 0;
        for(int j = i; j >= 0; j--) {
            if((A & (1 << j)) == 0) {
                ans += (1 << j);
            }
        }
        return ans;
    }
};
