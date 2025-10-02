class Solution {
public:
    ListNode* helper(ListNode* head, ListNode* newnode)
    {
        if (!head) return nullptr;

        ListNode* curr = head->next; // skip starting 0
        int sum = 0;

        while (curr && curr->val != 0) {
            sum += curr->val;
            curr = curr->next;
        }

        if (sum > 0) {   // only create node if sum > 0
            ListNode* newly = new ListNode(sum);
            newnode->next = newly;
            newnode = newly;
        }

        helper(curr, newnode);

        return newnode->next;
    }

    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        helper(head, dummy);
        return dummy->next;
    }
};
