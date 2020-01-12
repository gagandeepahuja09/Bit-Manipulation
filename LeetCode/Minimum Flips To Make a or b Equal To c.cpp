class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            bool ab = ((a & (1 << i)) >= 1), bb = ((b & (1 << i)) >= 1), cb = ((c & (1 << i)) >= 1);
            if((ab | bb) == cb)
                continue;
            if(!cb) {
                if(ab)
                    ans++;
                if(bb)
                    ans++;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};
