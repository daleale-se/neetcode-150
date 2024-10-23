class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> strs;
        stack<pair<string, pair<int, int>>> stk; 
        stk.push({"(", {1, 0}}); 

        while (!stk.empty()) {
            auto cur = stk.top();
            stk.pop();
            
            string curString = cur.first;
            int openCount = cur.second.first;
            int closeCount = cur.second.second;
            
            if (curString.length() == 2 * n) {
                strs.push_back(curString);
                continue;
            }
            
            if (openCount < n) {
                stk.push({curString + "(", {openCount + 1, closeCount}});
            }
            
            if (closeCount < openCount) {
                stk.push({curString + ")", {openCount, closeCount + 1}});
            }
        }

        return strs;
    }
};
