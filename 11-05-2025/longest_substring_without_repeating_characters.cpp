//Date: 11-05-2025
//Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters
//Final submission: https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1631226202

#include <bits/stdc++.h>
using namespace std;

//Approach 1
//Check each subtring starting from each element, add characters into a set and check for duplicates each time.
//Time complexity - O(n^2), Space complexity - O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for (int i = 0; s[i]!='\0'; i++) {
            int leng=0;
            unordered_set<int> myset;
            for (int j = i; s[j]!='\0'; j++) {
                myset.insert(s[j]);
                if (myset.size()<j-i+1)
                    break; 
                }
            res = (myset.size() > res)? myset.size() : res;
        }
        return res;
    }
    
};


//Approach 2
//Sliding window approach
//Time Complexity - O(n), Space complexity - O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxL = 0;
        int n = s.length();
        unordered_set<char> charSet;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (charSet.count(s[r]) == 0) {
                charSet.insert(s[r]);
                maxL = max(maxL, r - l + 1);
            }
            else {
                while (charSet.count(s[r])) {
                    charSet.erase(s[l]);
                    l++;
                }
                charSet.insert(s[r]);
            }
        }
        return maxL;
    }
};