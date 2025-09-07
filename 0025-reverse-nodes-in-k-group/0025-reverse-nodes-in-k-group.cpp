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

// Helper function to check if there are at least k nodes left
bool hasKNodes(ListNode* head, int k) {
    int count = 0;
    while (head != nullptr && count < k) {
        head = head->next;
        count++;
    }
    return count == k;
}

// Function to reverse k nodes
ListNode* Reverse(ListNode* head, int k) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* forward = nullptr;
    int count = 0;

    // Reverse first k nodes
    while (curr != nullptr && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Recursively call for the next part
    if (forward != nullptr && hasKNodes(forward, k)) {
        head->next = Reverse(forward, k);
    } else {
        head->next = forward;
    }

    return prev;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        if (!hasKNodes(head, k)) return head;

        return Reverse(head, k);
    }
};
