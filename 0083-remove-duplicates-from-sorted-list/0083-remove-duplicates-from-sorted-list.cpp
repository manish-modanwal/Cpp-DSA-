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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* currNode=head;
        
        ListNode* temp;
        ListNode* nextNode;
        if(head!=nullptr)
        {
         nextNode=head->next;
        }else{
            return head;
        }
        while(nextNode!=nullptr)
        {
            if(currNode->val==nextNode->val)
            {
                temp=nextNode;

                nextNode=nextNode->next;
                
                currNode->next=nextNode;

            }
            else{
                currNode=currNode->next;
                nextNode=nextNode->next;
            }
        }
        return head;
    }
};