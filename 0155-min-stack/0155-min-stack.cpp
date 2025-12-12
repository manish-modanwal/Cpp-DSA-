class MinStack {
public:
    vector<pair<long ,long>>st;
    int minEle;
    MinStack() {
     
    }
    
    void push(int val){
        if(st.empty())
        {   minEle=val;
            st.push_back({val,val});
            return;
        }

        if(val<minEle)
        {
            st.push_back({val,val});
            minEle=val;
        }else{
            st.push_back({val,minEle});
        }



    }
    
    void pop() {
        st.pop_back();
         if (!st.empty()) {
            minEle = st.back().second; 
        }
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */