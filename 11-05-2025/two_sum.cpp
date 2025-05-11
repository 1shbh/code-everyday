//Date: 11-05-2025
//Problem: https://leetcode.com/problems/two-sum
//Final submission: https://leetcode.com/problems/two-sum/submissions/1631012951



#include <bits/stdc++.h>
using namespace std;

//Approach 1
//Bruteforce solution, just add each element with each other and check if equal to target.
//Time Complexity - O(n^2), Space Complexity - O(1)
class Solution1 {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            for (int i = 0; i < nums.size(); i++){
                for (int j = i+1; j < nums.size(); j++){
                    if (nums[i]+nums[j] == target)
                        return {i,j};
                }
            }
            return {};
        }
};


//Approach 2
//Using a hashmap to store each element and its respective index. Checking if an element's complement (target-i) exists in the hashmap.
//Time Complexity - O(n),  Space complexity - O(n)
class Solution2 {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> myhash;
            for (int i = 0;  i < nums.size(); i++) {
                myhash[nums[i]] = i;
            }

            for (int i = 0; i < nums.size(); i++) {
                int comp = target - nums[i];
                if (myhash.find(comp) != myhash.end() && myhash[comp] != i)
                    return {i, myhash[comp]};
            }
            return {};
        }
};


//Approach 3 
//Single pass hash table, checking if an element's complement exists in the hash table, if not add the element to the map.
//Time Complexity - O(n), Space Complexity - O(n)
class Solution3 {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> myhash;

            for (int i = 0; i < nums.size(); i++) {
                int comp = target - nums[i];
                if (myhash.find(comp) != myhash.end()) {
                    return {i, myhash[comp]};
                }
                myhash[nums[i]] = i;
            }
            return {};
        }
};

