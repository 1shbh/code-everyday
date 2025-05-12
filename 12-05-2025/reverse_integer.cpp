//Date: 12-05-2025
//Problem: https://leetcode.com/problems/reverse-integer    
//Final submission: https://leetcode.com/problems/reverse-integer/submissions/1632118917

#include <bits/stdc++.h>
using namespace std;

//Approach 1
//Reverse normally, check for overflow and underlfow check because the questions asks us to only use a signed 32 bit integer.
//(Took way too long to figure out the checks) 
class Solution {
public:
    int reverse(int x) {
        int dummy = x;
        int reversed = 0, remain;

        while (dummy != 0) {
            remain = dummy % 10;
            dummy /= 10;

            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && remain > 7))
                return 0;
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && remain < -8))
                return 0;
            reversed = reversed * 10 + remain;
        }
        return reversed;
        
    }
};