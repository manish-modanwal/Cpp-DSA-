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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {

     ListNode* newNode= new ListNode(-1);
     ListNode*tail=newNode;
     ListNode* curr1=list1;
     ListNode* curr2=list2;

     while(curr1!=nullptr && curr2!=nullptr)
     {
            if(curr1->val<=curr2->val)
            {
                tail->next=curr1;
                curr1=curr1->next;
                tail=tail->next;
                tail->next=nullptr;
            }
            else{
                tail->next=curr2;
                curr2=curr2->next;
                tail=tail->next;
                tail->next=nullptr;
            }   
     }

     if(curr1==nullptr){tail->next=curr2;}
     if(curr2==nullptr){tail->next=curr1;}

     return newNode->next;

      
    }
};