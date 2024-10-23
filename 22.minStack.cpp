class MinStack {
private:
    vector<int> stack;
    vector<int> minVal;
public:
    MinStack() {}
    
    void push(int val) {
        stack.push_back(val);
        if (minVal.size() == 0 || minVal.back() >= val) {
            minVal.push_back(val);
        }
    }
    
    void pop() {
        if (stack.back() == minVal.back()) {
            minVal.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minVal.back();
    }
};


// class MinStack {
// private:
//     std::stack<int> stack;
//     std::stack<int> minStack;

// public:
//     MinStack() {}

//     void push(int val) {
//         stack.push(val);
//         val = std::min(val, minStack.empty() ? val : minStack.top());
//         minStack.push(val);
//     }

//     void pop() {
//         stack.pop();
//         minStack.pop();
//     }

//     int top() {
//         return stack.top();
//     }

//     int getMin() {
//         return minStack.top();
//     }
// };
