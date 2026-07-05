/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopyInBetween(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
    }
    void connectRandomPointers(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=temp->next;
            if(temp->random){   
            copyNode->random = temp->random->next; 
        }
        else{
            copyNode->random = NULL;   
        }
        
        temp = temp->next->next;  
        }
    }

    Node* getDeepCopyList(Node* head){
        Node* dummynode=new Node(-1);
        Node* res=dummynode;
        Node* temp=head;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummynode->next;
    }
    Node* copyRandomList(Node* head) {
            if(!head) return nullptr;   
    
        // Step 1: Insert copy of
        // nodes in between
        insertCopyInBetween(head); 
        // Step 2: Connect random
        // pointers of copied nodes
        connectRandomPointers(head);  
        // Step 3: Retrieve the deep
        // copy of the linked list
        return getDeepCopyList(head);
    }
};