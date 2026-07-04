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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
        
    }

    ListNode* computeMidPoint(ListNode* head){
        if (head == NULL) {
		// LinkedList is empty
		return NULL;
	}
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* midPoint=computeMidPoint(head);
        ListNode* head2=midPoint->next;
        midPoint->next=NULL;

        head2=reverse(head2);

        while(  head2!=NULL){
            if(head->val!=head2->val){
                return false;
            }
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};