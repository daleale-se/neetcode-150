class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;  
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = s.top(); s.pop();
                int left = s.top(); s.pop();
                if (token == "+") {
                    s.push(left + right);
                } else if (token == "-") {
                    s.push(left - right);
                } else if (token == "*") {
                    s.push(left * right);
                } else if (token == "/") {
                    s.push(left / right);  
                }
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
