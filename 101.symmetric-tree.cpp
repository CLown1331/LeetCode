/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (42.34%)
 * Total Accepted:    368.1K
 * Total Submissions: 859K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector < int > a, b;
    void leftFirst(TreeNode* root) {
        if (root == nullptr) {
            a.push_back(-1);
            return;
        }
        a.push_back(root->val);
        leftFirst(root->left);
        leftFirst(root->right);
    }
    void rightFirst(TreeNode* root) {
        if (root == nullptr) {
            b.push_back(-1);
            return;
        }
        b.push_back(root->val);
        rightFirst(root->right);
        rightFirst(root->left);
    }
    bool isSymmetric(TreeNode* root) {
        leftFirst(root);
        rightFirst(root);
        return (a == b);
    }
};

