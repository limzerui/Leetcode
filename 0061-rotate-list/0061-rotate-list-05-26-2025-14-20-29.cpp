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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;

        int len = 1;
        ListNode* tail = head;
        while(tail->next != nullptr){
            tail = tail->next;
            len++;
        }

        tail->next = head;

        k = k%len;
        int stepsToNewHead = len-k;
        ListNode* newTail = tail;
        while(stepsToNewHead--){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next =nullptr;
        return newHead;
    }
};