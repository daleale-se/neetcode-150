class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (const char& c : s) {
            if (c == ')' || c == ']' || c == '}') {
                if (stack.empty()) return false;
                if (stack.top() == '(' && c != stack.top() + 1 ) return false;
                if ((stack.top() == '[' || stack.top() == '{') && c != stack.top() + 2 ) return false;
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};