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
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode *currcheck=head;
        for(int i=0;i<k;i++)
        {
            if(currcheck==NULL)
            {
                return head;
            }
            currcheck=currcheck->next;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        for(int i=0;i<k;i++)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head->next=reverseKGroup(curr,k);
        
        return prev;
        
    }
};