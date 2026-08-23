class MinStack {
public:
  stack<int> st;       // Normal stack: saare elements store karega
    stack<int> minSt;    // Minimum stack: current minimums store karega
    MinStack() {
      
    }
    
    void push(int val) {
        st.push(val);

        // Agar minStack empty hai,
        // toh ye first element hi minimum hoga
        if(minSt.empty()) {
            minSt.push(val);
        }

         // Agar new value current minimum se chhoti/equal hai,
        // toh ise bhi minStack mein store karo
        else if(val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
          // Agar actual top minimum ke equal hai,
        // toh minimum stack se bhi remove karo
        if(st.top() == minSt.top()) {
            minSt.pop();
        }


        // Actual stack se top remove karo
      return   st.pop();
    }
    
    int top() {
       return st.top();
    }
    
    int getMin() {
        // minStack ka top hamesha current minimum hai
        return minSt.top();
    }

};
