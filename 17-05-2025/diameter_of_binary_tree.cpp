//Date: 17-05-2025
//Problem: https://leetcode.com/problems/diameter-of-binary-tree
//Final submission: https://leetcode.com/problems/diameter-of-binary-tree/submissions/1636688687

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

//Approach 1
//Brute force solution, check max depth of every left and right subtrees,  repeatedly calculate diameters and find maximum diameter.
//Time complexity - O(n^2), space complexity - O(h)
class Solution1 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftDepth = maxDepth(root->left);
        int righDepth = maxDepth(root->right);
        int diameter = leftDepth + righDepth;
        int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(diameter, sub);

        
    }
    int maxDepth(TreeNode* root){
        if (root == nullptr) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

//Approach 2 (from solutions)
//Use DFS to compute depth of each subtree and update the global maximum diameter.
//Time complexity - O(n), space complexity - O(h)
class Solution2 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);

        res = max(res, left + right);

        return 1 + max(left, right);
    }
};

