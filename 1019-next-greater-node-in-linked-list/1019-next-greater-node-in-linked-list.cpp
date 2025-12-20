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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>listarr;
       
      
        while(head)
        {
            listarr.push_back(head->val);
            
            head=head->next;
        }

        int n=listarr.size();
         vector<int> nextGr(n, 0);
        stack<int>st;
        for(int i=listarr.size()-1;i>=0;i--)
        {
           while(!st.empty() &&st.top() <= listarr[i]){
                    st.pop();
           }

           if(st.empty())
           {
                nextGr[i]=0;
           }else{
                nextGr[i]=st.top();
           }
            st.push(listarr[i]);
        }
        return nextGr;
    }
};