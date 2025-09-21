class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ct1 = 0;
        int ct2 = 0;
        ListNode *currA = headA;
        ListNode *currB = headB;

        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA != nullptr || tempB != nullptr)
        {
            if(tempA != nullptr){
                ct1++;
                tempA = tempA->next;
            }

            if(tempB != nullptr){
                ct2++;
                tempB = tempB->next;
            }
        }

      
        if(ct1 > ct2)
        {
            int diff = ct1 - ct2;
            while(diff--)
            {
                currA = currA->next;
            }
        }
        else
        {
            int diff = ct2 - ct1;
            while(diff--)
            {
                currB = currB->next;
            }
        }

      
        while(currA != nullptr && currB != nullptr)
        {
            if(currA == currB)
            {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }

        return nullptr; 
    }
};
