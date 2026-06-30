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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==NULL){
            return list2;

        }
        if (list2==NULL){
            return list1;
            
        }

        //recursive case
        ListNode * list=NULL;
        if(list1->val >list2->val){
            list=list2;
            ListNode* headfromMyFriend=mergeTwoLists(list1 , list2->next);
            list->next=headfromMyFriend;
        }
        else{
            list=list1;
            ListNode* headfromMyFriend=mergeTwoLists(list1->next , list2);
            list->next=headfromMyFriend;

        }
        return list;
    }
};