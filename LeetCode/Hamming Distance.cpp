class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        for(int i = 0; i < 32; i++) {
            int a = 0, b = 0;
            if(x & (1 << i))
                a = 1;
            if(y & (1 << i))
                b = 1;
            cnt += (a + b == 1);
        }
        return cnt;
    }
};
