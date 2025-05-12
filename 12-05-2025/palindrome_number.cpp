//Date: 12-05-2025
//Problem: https://leetcode.com/problems/palindrome-number/description/
//final submission: https://leetcode.com/problems/palindrome-number/submissions/1632098534

#include <bits/stdc++.h>
using namespace std;

//Approach 1
//Add each digit into a new reversed integer manually and then finally compare both.

//Time complexity - O(log x), space complexity - O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int dummy = x;
        int reversed = 0;

        int remain;
        while (dummy != 0) {
            remain = dummy % 10;
            dummy /= 10;
            if (reversed > (INT_MAX - remain) / 10)
                return false;
            reversed = reversed * 10 + remain;
        }

        if (x == reversed)
            return true;
        else
            return false;
        
    }
};
