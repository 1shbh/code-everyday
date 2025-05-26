//Date: 26-05-2025
//Problem: https://leetcode.com/problems/subtree-of-another-tree
//Final submission: https://leetcode.com/problems/subtree-of-another-tree/submissions/1645166472
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

//Approach 1: Have a helper function to check if a subtree starting from a node is equal to given subtree. Use this function for every subtree starting from the top.
//Time complexity - O(n.m), space complexity - O(max(n,m))
class Solution1 {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isEqual(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
    bool isEqual(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)  return true;
        if (!root || !subRoot) return false;
        if (root->val != subRoot->val) return false;

        return isEqual(root->left, subRoot->left) && isEqual(root->right, subRoot->right);
    }

};

//Approach 2: Serialization (from solution)
//Time complexity: O(n.m) , space complexity - O(n+m)
class Solution2 {
public:
    string serialize(TreeNode* node) {
        if (!node) return "N";
        return "(" + to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right) + ")";
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootSerialized = serialize(root);
        string subRootSerialized = serialize(subRoot);
        return rootSerialized.find(subRootSerialized) != string::npos;
    }
};