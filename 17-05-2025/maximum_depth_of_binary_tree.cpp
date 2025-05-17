//Date: 17-05-2025
//Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree
//Final submission: https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/1636663068

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Approach: just calculate maximum of left and right subtree
//Time complexity: O(n), space complexity - O(h)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
