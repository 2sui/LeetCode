/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *    3
 *   / \
 *  9  20
 *  /   \
 * 15    7
 * return its level order traversal as:
 * [
 *  [3],
 *  [9,20],
 *  [15,7]
 * ]
 */

/****************************************************************************************/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        transVal(root, res, 0);
        return res;
    }
    
    void transVal(TreeNode* root, vector<vector<int>> &res, int level) {
        
        if (root == NULL) return;
        if (res.size() <= level) {
            res.push_back(vector<int>());
        }
        
        res[level++].push_back(root->val);
        transVal(root->left, res, level);
        transVal(root->right, res, level);
    }
    
};