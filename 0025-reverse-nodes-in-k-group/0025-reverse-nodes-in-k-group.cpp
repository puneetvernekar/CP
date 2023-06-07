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
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *p=dummy,*temp=head;
        ListNode *c,*n;
        int len=0;
        while(temp!=NULL)
        {len++;
        temp=temp->next;}

        while(len>=k)
        {
            c=p->next;
            n=c->next;
            for(int i=0;i<k-1;i++)
            {
                c->next=n->next;
                n->next=p->next;
                p->next=n;
                n=c->next;
            }
            p=c;
            len=len-k;
        }
        return dummy->next;

    }
};