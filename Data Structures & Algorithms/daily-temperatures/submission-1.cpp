class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<int>st;
        
          for(int i = 0; i < temperatures.size(); i++) {
        while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
             
                int prev = st.top();
                st.pop();

                // Current day - previous day
                result[prev] = i - prev;
            }

            // Current day ko stack mein daal do
            st.push(i);
        }
        return result;
    }
};
