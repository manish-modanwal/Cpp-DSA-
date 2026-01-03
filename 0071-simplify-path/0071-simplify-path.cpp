class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string str = "";

        for (int i = 0; i < path.size(); i++) {
            if (path[i] != '/') {
                str += path[i];
            } else {
                if (!str.empty()) {
                    if (str == "..") {
                        if (!st.empty()) st.pop();
                    } else {
                        if (str != ".") st.push(str);
                    }
                   
                }
                 str = "";
            }
        }

        // last part handle
        if (!str.empty()) {
            if (str == "..") {
                if (!st.empty()) st.pop();
            } else {
                if (str != ".") st.push(str);
            }
        }

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};
