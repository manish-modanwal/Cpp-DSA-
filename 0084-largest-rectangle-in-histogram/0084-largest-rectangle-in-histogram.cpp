class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();   // 🔴 missing line fixed
        stack<pair<int,int>> st;
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int start = i;

            while(!st.empty() && st.top().first > heights[i]) {
                auto [h, idx] = st.top();
                st.pop();

                maxArea = max(maxArea, h * (i - idx));
                start = idx;   // left extend
            }

            st.push({heights[i], start});
        }

        // remaining bars
        while(!st.empty()) {
            auto [h, idx] = st.top();
            st.pop();

            maxArea = max(maxArea, h * (n - idx));
        }

        return maxArea;
    }
};
