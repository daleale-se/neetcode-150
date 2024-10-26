class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0); 
        stack<int> stk; 
        
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }
            
            if (!stk.empty()) {
                result[i] = stk.top() - i;
            }
            
            stk.push(i);
        }
        
        return result;
    }
};