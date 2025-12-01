class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
       for(const string &t : tokens){
        if(t=="+"||t=="-" || t=="/" || t == "*" ){
            long long b = st.top() ; st.pop();
            long long a = st.top() ;st.pop();
            long long res;
            if(t=="+" ) res = a+b;
            else if(t == "-") res = a-b;
            else if(t == "*") res = a*b;
            else{
                res = a/b;
            }
            st.push(res);
        }
        else{
            st.push(stoll(t)); //integer non negative;

        }
       }
       return static_cast<int>(st.top());
        


        

        
    }
};