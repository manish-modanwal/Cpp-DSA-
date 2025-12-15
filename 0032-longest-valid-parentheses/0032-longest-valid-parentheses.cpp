class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int> st;
        st.push(-1);              // 🔹 base index
        int maxlen = 0;           // 🔹 fix

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();

                if(st.empty())
                {
                    st.push(i);  // new base
                }
                else
                {
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }
        return maxlen;
    }
};
