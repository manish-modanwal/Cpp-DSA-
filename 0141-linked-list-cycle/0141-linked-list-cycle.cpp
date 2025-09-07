class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr) {
            fast = fast->next;

            if (fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            } else {
                return false; // No cycle possible if fast reaches end
            }

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};
