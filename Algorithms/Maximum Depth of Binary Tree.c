/*
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

/****************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    if (NULL == root) {
        return 0;
    }
    
    /* find max depth of left subtree */
    int ldeep = maxDepth(root->left);
    /* find max depth of right subtree */
    int rdeep = maxDepth(root->right);
    return ldeep > rdeep ? ldeep + 1 : rdeep + 1;
    
}