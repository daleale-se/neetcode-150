class Solution {
public:
    int maxArea(vector<int>& heights) {
        // int area = 0;
        // for (int i = 0; i < heights.size(); ++i) {
        //     for (int j = i + 1; j < heights.size(); ++j) {
        //         int minBar = min(heights[i], heights[j]);
        //         if (area < minBar*(j - i)) {
        //             area = minBar*(j - i);
        //         }
        //     }
        // }
        // return area;

        int area = 0;
        int left = 0;
        int right = heights.size() - 1;
        while (left < right) {
            int minBar = min(heights[left], heights[right]);
            if (area < minBar*(right - left)) {
                area = minBar*(right - left);
            }
            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }
        return area;
    }
};