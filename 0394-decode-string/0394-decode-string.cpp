class Solution {
public:
    string decodeString(string s) {

        stack<string> st;

        for (char ch : s) {
            if (ch != ']') {
                st.push(string(1, ch));   // FIX 1: char → string
            } 
            else {
                // extract string inside []
                string str = "";
                while (!st.empty() && st.top() != "[") {
                    str = st.top() + str;
                    st.pop();
                }

                st.pop(); // remove '['

                // extract number (can be multi-digit)
                string numStr = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    numStr = st.top() + numStr;
                    st.pop();
                }

                int n = stoi(numStr);

                // repeat string
                string repeated = "";
                while (n--) {
                    repeated += str;
                }

                st.push(repeated);
            }
        }

        // build final answer
        string output = "";
        while (!st.empty()) {
            output = st.top() + output;
            st.pop();
        }

        return output;
    }
};
