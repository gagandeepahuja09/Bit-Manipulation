/*
Strange Equality

Given a single number N.

2 numbers A and B are defined as follows:

A is the greatest number smaller than N such that XOR sum of A and N is the same as the addition of A and N.

B is the smallest number greater than N such that XOR sum of B and N is the same as the addition of B and N.

You have to find the XOR sum of A and B.

Note: XOR sum of A and B is defined as A^B where '^' is the BITWISE XOR operator.

Constraints:

Your code will be run against a maximum of 100000 Test Cases
1<=N<=10^9

Input: A single integer N

Output: XOR sum of A and B.

Example:

Input:

5

Output:

10
*/

int Solution::solve(int A) {
    int small = A, large = 0, pos = -1;
    bool vis = false;
    for(int i = 30; i >= 0; i--) {
        if(((small & (1<<i)) == 0) && !vis) {
            continue;
        } 
        if(((small & (1<<i)) == 1 << i) && !vis) {
            vis = true;
            if(pos == -1)
                pos = i;
        }
        small ^= (1 << i);  
    }
    large = (1 << (pos + 1));
    return small ^ large;
}

