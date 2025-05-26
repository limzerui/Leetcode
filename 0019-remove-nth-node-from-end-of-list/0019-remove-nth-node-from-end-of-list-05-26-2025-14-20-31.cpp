/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //one single pass, at every pass, created a vector of ListNodes
        // vector<ListNode> track;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        // while(curr != nullptr){
        //     track.pushback
        // }
        // track[n-1] //this is the ListNode u want to ignore

        int length = 0;
        while(curr != nullptr){
            length ++;
            curr = curr->next;
        }
        if (n == length) {
            ListNode* newHead= head->next;
            delete head;
            return newHead;
        }
        ListNode* track = head;
        for(int i = 0; i<length -n; i++){
            prev = track;
            track = track->next;
        }
        prev->next = track->next;
        delete track;
        return head;
    }
};