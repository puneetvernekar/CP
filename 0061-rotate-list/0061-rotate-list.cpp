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
    if(head==NULL ||head->next==NULL|| k==0)
	return head;
	ListNode *ptr=head;
	int n=1;
	while(ptr->next!=NULL)
	{ptr=ptr->next;
	n++;}
	ptr->next=head;
	k=n-(k%n)-1;
	ListNode *tar=head;
	while(k--)
	{
		tar=tar->next;
	
	}
	ListNode *ans=tar->next;
	tar->next=NULL;
	return ans;
    }
};