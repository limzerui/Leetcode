/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //keep a an array of visited?
        //then see if the next is inside
        vector<ListNode*> visited;
        ListNode* curr = head;
        while(curr){
            for(auto node: visited){
                if(node==curr) return true;
            }
            visited.push_back(curr);
            curr = curr->next;
        }
        return false;
    }
};