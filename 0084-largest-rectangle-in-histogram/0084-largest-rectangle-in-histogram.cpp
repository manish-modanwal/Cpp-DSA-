class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n, n); // Initialize with n (no smaller element to the right)
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            // Find index of next smaller element
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if(!st.empty()) {
                next[i] = st.top();
            }
            
            st.push(i);
        }
        return next;
    }
    
    vector<int> prevSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n, -1); // Initialize with -1 (no smaller element to the left)
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            // Find index of previous smaller element
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if(!st.empty()) {
                prev[i] = st.top();
            }
            
            st.push(i);
        }
        return prev;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmaller(heights);
        vector<int> prev = prevSmaller(heights);
        
        int maxArea = 0;
        
        for(int i = 0; i < heights.size(); i++) {
            int width = next[i] - prev[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        
        return maxArea;
    }
};