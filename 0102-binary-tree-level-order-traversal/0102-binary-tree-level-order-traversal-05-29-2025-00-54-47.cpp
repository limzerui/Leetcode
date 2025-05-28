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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        vector<TreeNode*> currentLevel = {root};
        result.push_back({root->val});

        while(true){
            auto[values, nextLevel, exist] = helper(currentLevel);
            if(!exist) break;
            result.push_back(values);
            currentLevel = nextLevel;
        }
        return result;
    }

    tuple<vector<int>,vector<TreeNode*>, bool> helper(vector<TreeNode*> level){
        vector<int> values;
        vector<TreeNode*> nextLevel;
        for(auto node: level){
            if(node->left){ values.push_back(node->left->val);
                nextLevel.push_back(node->left);
                }
            if(node->right){ values.push_back(node->right->val);
                nextLevel.push_back(node->right);
                }
        }
        bool exist = !values.empty();
        return {values, nextLevel, exist};
    }
};