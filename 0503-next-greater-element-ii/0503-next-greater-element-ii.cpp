class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);  // Initialize with -1
        stack<int> st;
        
        // Traverse from right to left, but twice
        for(int i = 2*n - 1; i >= 0; i--) {  // i-- not i++
            int idx = i % n;
            
            while(!st.empty() && st.top() <= arr[idx]) {
                st.pop();
            }
            
            if(i < n) {
                if(!st.empty()) {
                    ans[idx] = st.top();
                }
                // else already -1 (from initialization)
            }
            
            st.push(arr[idx]);  // Push current element
        }
        
        return ans;
    }
};