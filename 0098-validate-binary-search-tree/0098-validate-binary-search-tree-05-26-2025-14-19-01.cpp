#include <climits>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool result;
        //recurse the whole tree. 
        //but how to verify whole tree done. 
        //is when dh the left and right anyore

        return helper(root, LLONG_MIN, LLONG_MAX);

    }

    bool helper(TreeNode* node, long long lower, long long upper){
        if(!node) return true;
        if(node->val <= lower || node->val >= upper) return false;
        return helper(node->left, lower, node->val) && helper(node->right, node->val, upper);
    }
};