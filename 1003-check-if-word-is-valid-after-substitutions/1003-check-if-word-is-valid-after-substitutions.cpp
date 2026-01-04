class Solution {
public:
    bool isValid(string s) {

        stack<char>st;

        for(auto ch :s)
        {
            st.push(ch);
            
             char c;
             char b;
             char a;
            if(st.size()>=3)
            {
                 c= st.top();
                        st.pop();
                 b= st.top();
                        st.pop();  
                 a= st.top();
                        st.pop(); 

               if(!(c=='c' && b=='b'  && a=='a'))
            {
                st.push(a);
                st.push(b);
                st.push(c);
            }                      
            }

            
        }

        return st.empty();
        
    }
};