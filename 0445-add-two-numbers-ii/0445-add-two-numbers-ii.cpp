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
    ListNode *rev(ListNode* point)
    {
        ListNode *p=NULL,*c=point,*n;
        while(c)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1=rev(l1);
        l2=rev(l2);
        
        ListNode *node=new ListNode(0);
        ListNode *temphead=node;
        int c=0;
        while(l1!=NULL || l2!=NULL || c)
        {
            int s=0;
            if(l1!=NULL)
            {
                s+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                s+=l2->val;
                l2=l2->next;
            }
            s+=c;
            c=s/10;
            ListNode *NewNode=new ListNode(s%10);
            temphead->next=NewNode;
            temphead=temphead->next;
        }
        node=rev(node->next);
        return node;
    }
};