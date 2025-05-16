//Date: 16-05-2025
//Problem: https://leetcode.com/problems/find-the-duplicate-number
//Final submission: https://leetcode.com/problems/find-the-duplicate-number/submissions/1635700471

#include <bits/stdc++.h>
using namespace std;

//Approach 1, had to look up and study the algorithm required (Floyd's Algorithm)
//Treat the array like a linked list, find the cycle, apply Floyd's Tortoise and Hare algorithm to find the starting point of the cycle. The starting point = required duplicate.
//Time complexity - O(n), space complexity - O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }

        fast = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
        
    }
};