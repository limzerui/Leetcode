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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //set the first root as the LCA.
        //if they are both in the same subtree, then the lca isnt found yet
        //if they are in different subtree, then that is the LCA and return it
        //if the current node is equal to either of them, 
        TreeNode* current = root;
        if(!root) return nullptr;
        if ((p->val <= current->val && q->val >= current-> val) ||  (p->val >= current->val && q->val <= current-> val) ){
            return current;
        }
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};
