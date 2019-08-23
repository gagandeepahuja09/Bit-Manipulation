class Solution {
public:
    int bitwiseComplement(int N) {
        int ret = 0;
        int i = 31;
        while(i >= 0 && !(N & (1 << i)))
            i--;
        if(i < 0)
            return 1;
        for(int j = i; j >= 0; j--) {
            if(!(N & (1 << j)))
                cout << i, ret += (1 << j);
        }
        return ret;
    }
};
