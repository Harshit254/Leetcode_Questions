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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
//         ListNode* start= new ListNode();
//         start->next=head;
//         ListNode* curr=start;
//         ListNode* end=start;
//         int count=0;
//         for(int i=1;i<=n;i++)
//         {
//             curr=curr->next;
//         }
//             while(curr->next!=NULL)
//         {
//             end=end->next;
//             curr=curr->next;
            
//         }
//         end->next=end->next->next;
        
//         return start->next;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        int t=0;
        if(n==1)
        {
            return NULL;
        }
        if(n==k) return head->next;
        temp=head;
        while(temp!=NULL)
        {
            if(t==n-k-1)
            {
                temp->next=temp->next->next;
            }
            else
            {
                temp=temp->next;
            }
            t++;
        }
        
        return head;
    }
};