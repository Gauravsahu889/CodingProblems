class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;
        
        // Bug Fix 1: Properly check for list boundaries to avoid crash
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // Cycle detected
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        
        // Bug Fix 2: If there is no cycle, return nullptr immediately
        if (!hasCycle) {
            return nullptr;
        }
        
        // Find the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
