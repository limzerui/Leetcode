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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { //traverse to the end then compare from the back? then return
        int lenA = 0;
        int lenB = 0;
        ListNode* Acopy = headA;
        ListNode* Bcopy = headB;
        while(Acopy)
        {
            lenA ++;
            Acopy = Acopy->next;
        }
        while(Bcopy)
        {
            lenB ++;
            Bcopy = Bcopy->next;
        }
        if(lenA > lenB)
        {
            int adjust = lenA-lenB;
            for(int i = 0; i<adjust; i++)
            {
                headA = headA->next;
            }
        }
        else if(lenB > lenA)
        {
            int adjust = lenB-lenA;
            for(int i = 0; i<adjust; i++)
            {
                headB = headB->next;
            }
        }
        while(headB && headA)
        {
            if(headB == headA)
            {
                return headB;
            }
            headB = headB->next;
            headA = headA->next;
        }
        return nullptr;
    }
};