class Solution {
public:
    ListNode* helper(ListNode* head, ListNode* newnode)
    {
        if (!head) return nullptr; 

        ListNode* curr = head->next; 
        int sum = 0;

        while (curr && curr->val != 0) {
            sum += curr->val;
            curr = curr->next;
        }

        if (!curr) return newnode->next; 

        
        ListNode* newly = new ListNode(sum);
        newnode->next = newly;
        newnode = newnode->next;

        
        return helper(curr, newnode);
    }

    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        helper(head, dummy);
        return dummy->next;  // final merged list
    }
};
