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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++){ //0 to n-1 chalega yo
            fast=fast->next;
        }
        if(fast==NULL){ //if n==length of ll , then delete linked list simple 
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }
        while( fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* delNode=slow->next; //use delete keyword 
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};