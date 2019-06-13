/*
Xor queries

You are given an array (containing only 0 and 1) as element of N length.

Given L and R, you need to determine value of XOR of all elements from L to R (both inclusive) and number of unset bits (0's) in the given range of the array.

Input

First argument contains the array of size N containing 0 and 1 only (1<=N<=100000). 

Second argument contains a 2D array with Q rows and 2 columns, each row represent a query with 2 columns representing L and R. 

(1<=Q<=100000), (1<=L<=R<=N).

Output

Return an 2D array of Q rows and 2 columns i.e the xor value and number of unset bits in that range respectively for each query.

Examples

Input

1 0 0 0 1
2 4
1 5 
3 5

Output

0 3
0 3
1 2

Explanation

Testcase 1-

In the given case the bit sequence is of length 5 and the sequence is 1 0 0 0 1. For query 1 the range is (2,4), and the answer is (array[2] xor array[3] xor array[4]) = 0, and number of zeroes are 3, so output is 0 3. Similarly for other queries.
*/


//This is general case. For 0 and 1 counting no. of 1s would be enough
vector<vector<int> > Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    vector<int> lxor(n, 0);
    vector<int> rxor(n, 0);
    vector<int> c0(n, 0);
    c0[0] = (A[0] == 0);
    lxor[0] = A[0];
    for(int i = 1; i < n; i++) {
        lxor[i] = lxor[i - 1] ^ A[i];
        c0[i] = c0[i - 1] + (A[i] == 0);
    }
    rxor[n - 1] = A[n - 1];
    for(int i = n - 2; i >= 0; i--)
        rxor[i] = rxor[i + 1] ^ A[i];
    vector<vector<int>> ret;
    for(int i = 0; i < B.size(); i++) {
        vector<int> v;
        int l = B[i][0], r = B[i][1];
        l--; r--;
        int num = lxor[n - 1] ^ (l > 0 ? lxor[l - 1] : 0) ^ (r < n - 1 
        ? rxor[r + 1] : 0);
        v.push_back(num);
        int cnt = c0[r] - (l > 0 ? c0[l - 1] : 0);
        v.push_back(cnt);
        ret.push_back(v);
    }
    return ret;
}

