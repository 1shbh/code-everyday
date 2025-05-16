//Date: 16-05=2025
//Problem: https://leetcode.com/problems/determine-if-two-strings-are-close
//Final submission: https://leetcode.com/problems/determine-if-two-strings-are-close/submissions/1635779635

#include <bits/stdc++.h>
using namespace std;

//Approach 1
//Check if same characters exist in both strings, then check if frequencies are equal (irrespective of the character). The operations allow us to create similar strings if the frequencies match.
//Time complexity - O(n+m), space complexity - O(1)
class Solution1 {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> m1, m2;

        for (char c : word1) m1[c]++;
        for (char c : word2) m2[c]++;

        for (auto& [key, _] : m1) {
            if (m2.find(key) == m2.end())
                return false;
        }

        for (auto& [key, _] : m2) {
            if (m1.find(key) == m1.end())
                return false;
        }

        vector<int> v1, v2;

        for (auto& [_, value] : m1) v1.push_back(value);
        for (auto& [_, value] : m2) v2.push_back(value);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1 == v2;
    }
};

//Approach 2
//Use arrays instead
//Time complexity - O(n+m), space complexity - O(1)
class Solution2 {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char ch : word1) freq1[ch - 'a']++;
        for (char ch : word2) freq2[ch - 'a']++;

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] !=0 && freq2[i] == 0))
                return false;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};