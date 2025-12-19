class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<pair<int,int>>st;
        int n= heights.size();
        int maxArea=0;

        for(int i=0;i<n;i++)
        {
           int start=i;

            while(!st.empty() && st.top().first>=heights[i])
            {
                auto[height,idx]=st.top();

                st.pop();

                maxArea=max(maxArea,height*(i-idx));

                start=idx;
            }
            st.push({heights[i],start});
        }

        while(!st.empty())
        {
            auto[height,idx]=st.top();

                st.pop();
            maxArea=max(maxArea,height*(n-idx));    

        }
      return maxArea;     
    }
};