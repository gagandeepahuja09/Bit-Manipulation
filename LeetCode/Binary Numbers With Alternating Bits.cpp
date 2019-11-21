class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while(n) {
            int t = n % 2;
            if(prev != -1 && t != 1 - prev) {
                return false;
            }
            prev = t;
            n /= 2;
        }
        return true;
    }
};
