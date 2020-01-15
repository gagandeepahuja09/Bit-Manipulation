class Solution {
public:
    int getMask(string word) {
        int mask = 0;
        for(char c : word) {
            mask |= (1 << (c - 'a'));
        }
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;
        for(string w : words) {
            int mask = getMask(w);
            freq[mask]++;
        }
        vector<int> ret;
        for(string p : puzzles) {
            int count = 0;
            int mask = getMask(p);
            int maskFirstChar = 1 << (p[0] - 'a');
            for(int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                if((sub & maskFirstChar) && freq.count(sub)) {
                    count += freq[sub];
                }
            }
            ret.push_back(count);
        }
        return ret;
    }
};
