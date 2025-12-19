class Solution {
public:
    
    
    vector<int> nextSmaller(vector<int>& heights) {
        vector<int> next(heights.size());  
        stack<int> st;  
        
        for(int i = heights.size() - 1; i >= 0; i--) {
            int element = heights[i];
            
          
            while(!st.empty() && heights[st.top()] >= element) {
                st.pop();
            }
            
            if(st.empty()) {
                // If no smaller to right, set to size
                next[i] = heights.size();
            } else {
                next[i] = st.top();
            }
            st.push(i);
        }
        return next;
    }
    
    vector<int> prevSmaller(vector<int>& heights) {
        vector<int> prev(heights.size()); 
        stack<int> st;  // Local stack
        
        for(int i = 0; i < heights.size(); i++) {
            int element = heights[i];
            
            // Compare heights[st.top()] with element
            while(!st.empty() && heights[st.top()] >= element) {
                st.pop();
            }
            
            if(st.empty()) {
                prev[i] = -1;
            } else {
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