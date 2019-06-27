// Greedy

int Solution::solve(vector<int> &A) {
    int maxTillNow = 0, mask = 0;
    for(int i = 30; i >= 0; i--) {
        mask |= (1 << i);
        unordered_set<int> st, st2;
        int num = (1 << i);
        for(int j = 0; j < A.size(); j++) {
            int ele = A[j] & mask;
             if(ele & num)
                st.insert(ele);
            else
                st2.insert(ele);
        }
        int candidate = maxTillNow | num;
        for(auto x : st) {
            int val = x ^ candidate;
            if(st2.find(val) != st2.end())
                maxTillNow = candidate;
        }
    }
    return maxTillNow;
}

