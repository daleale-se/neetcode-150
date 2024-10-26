class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            int h = heights[stk.top()];
            stk.pop();
            int width = stk.empty() ? n : n - stk.top() - 1;
            maxArea = max(maxArea, h * width);
        }

        return maxArea;
    }
};
