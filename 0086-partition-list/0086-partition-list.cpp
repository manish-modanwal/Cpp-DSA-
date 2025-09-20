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
    ListNode* partition(ListNode* head, int x) 
    {
        if (!head) return nullptr;

        ListNode* lesshead = nullptr;
        ListNode* lesstail = nullptr;
        ListNode* currNode = head;
        ListNode* prevNode = nullptr;

        while (currNode != nullptr)
        {
            if (currNode->val < x)
            {
                
                if (prevNode != nullptr) {
                    prevNode->next = currNode->next;
                } else {
                    head = currNode->next; // update head if first node is < x
                }

                ListNode* nextNode = currNode->next; 
                currNode->next = nullptr; 

                
                if (lesshead == nullptr) {
                    lesshead = currNode;
                    lesstail = currNode;
                } else {
                    lesstail->next = currNode;
                    lesstail = currNode;
                }

                currNode = nextNode; // move forward
            }
            else
            {
                prevNode = currNode;
                currNode = currNode->next;
            }
        }

      
        if (lesstail != nullptr) {
            lesstail->next = head;
            return lesshead;
        }

        return head;
    }
};
