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
    vector<int> inorderTraversal(TreeNode* root) {
        //traverse the left first
        //print out the current
        //print out the right subtree
        //recursive
        vector<int> result;
        dfs(root, result);
        return result;
    }

    void dfs(TreeNode* node, vector<int>& result){
        if(node == nullptr) return;
        dfs(node->left, result);
            result.push_back(node->val);
        dfs(node->right, result);
    }


};

