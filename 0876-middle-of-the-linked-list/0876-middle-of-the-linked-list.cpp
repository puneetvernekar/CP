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
    ListNode* middleNode(ListNode* head) {
        /*int n=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {temp=temp->next;
        n++;}
        n=n/2;
        temp=head;
        while(n)
        {
            temp=temp->next;
            n--;
        }
        return temp;*/

        ListNode *tor=head,*rab=head;
        while(rab!=NULL && rab->next)
        {
            rab=rab->next->next;
            tor=tor->next;
        }
        return tor;
    }
};