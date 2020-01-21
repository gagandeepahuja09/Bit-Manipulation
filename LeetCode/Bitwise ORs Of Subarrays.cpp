class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> ret, curr;
        for(int i : A) {
            unordered_set<int> next;
            for(int j : curr) {
                next.insert(i | j);
            }
            next.insert(i);
            curr = next;
            for(int j : curr)
                ret.insert(j);
        }
        return ret.size();
    }
};
