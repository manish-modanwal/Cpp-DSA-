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
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* curr = head;

        while(curr)
        {
            Node* clone= new Node(curr->val);
            clone->next=curr->next;
            curr->next=clone;
            curr=clone->next;
        }


        curr= head;

        while(curr)
        {
            if(curr->random)
            {
                curr->next->random= curr->random->next;
            }
            curr=curr->next->next;
        }

                Node* currOriginal = head;
        Node* currClone = head->next;
        Node* clonedHead = head->next;

        while (currOriginal) {
            currOriginal->next = currClone->next;       // restore original next

            if (currClone->next) {
                currClone->next = currClone->next->next; // set clone next
            }

            currOriginal = currOriginal->next; // move original
            currClone = currClone->next;       // move clone
        }

        return clonedHead;
    }
};

