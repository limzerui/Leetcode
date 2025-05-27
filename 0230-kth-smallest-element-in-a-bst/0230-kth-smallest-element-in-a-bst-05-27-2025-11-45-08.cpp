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

    int counter = 0;
    int result = -1;
    int kthSmallest(TreeNode* root, int k) {
        //find the smallest , then traverse up?
        //if no more left, then it is the smallest
        inorder(root, k);
        return result;
    }

    void inorder(TreeNode* current, int k){
        if(!current) return;
        inorder(current->left, k);
        counter++;
        if(counter == k){
            result = current->val;
            return;
        }
        inorder(current->right, k);
    }

};