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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //how do i know which is the head of the tree?
        // that would be the first one in the preorder,
        //the left would be 
        //find the root in the inorder
        //the left side of the vector of the root is in the left subtree
        unordered_map<int, int> map; //value and index for inorder?
        for(int i = 0; i<inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return helper(0,0,inorder.size()-1, preorder,map);
    }

    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, unordered_map<int,int>& map){
        if(inStart>inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIdx = map[rootVal];
        int leftSize = inRootIdx - inStart;

        root->left = helper(preStart +1, inStart, inRootIdx-1, preorder, map);
        root->right = helper(preStart+1+leftSize, inRootIdx+1, inEnd, preorder, map);

        return root;
    }





};