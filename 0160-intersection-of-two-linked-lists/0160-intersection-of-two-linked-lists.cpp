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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=0,b=0;
        auto temp=headA;
        while(temp){
            temp=temp->next;
            a++;
        }
        temp=headB;
          while(temp){
            temp=temp->next;
            b++;
        }
        if(a>b)for(int i=0;i<a-b;i++)headA=headA->next;
        else for(int i=0;i<b-a;i++)headB=headB->next;
        while(headA && headB){
            if(headA==headB)return headA;

            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }
};