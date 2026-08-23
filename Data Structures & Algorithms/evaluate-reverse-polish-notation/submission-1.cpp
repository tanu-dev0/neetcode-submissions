class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto x : tokens){
            if(x=="+"){
                 int first= st.top();
                 st.pop();
                 int second = st.top();
                 st.pop();
                 int newoperand=first+ second;
                 st.push(newoperand);
            }
           else  if(x=="-"){
                 int first= st.top();
                 st.pop();
                 int second = st.top();
                 st.pop();
                 int newoperand=second-first;
                 st.push(newoperand);
            }
           else  if(x=="*"){
                 int first= st.top();
                 st.pop();
                 int second = st.top();
                 st.pop();
                 int newoperand=first*second;
                 st.push(newoperand);
            }
            else if(x=="/"){
                 int first= st.top();
                 st.pop();
                 int second = st.top();
                 st.pop();
                 int  newoperand=second/first;
                 
                 st.push(newoperand);
            }
            else st.push(stoi(x));

        }

        return st.top();
    }
};
