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
    int goodNodes(TreeNode* root) {
        //need a counter 
        //keep a maximum
        //then update the maximum as u go down
        //do a in order traversal?
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int maxSoFar){
        if(!node) return 0;

        int good = 0;
        if(node->val >= maxSoFar){
            good = 1;
        }
        maxSoFar = max(maxSoFar, node->val);

        return good + dfs(node->left, maxSoFar) + dfs(node->right, maxSoFar);
    }
};