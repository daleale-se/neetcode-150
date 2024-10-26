class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int rowIndex;
                
        while (top <= bottom) {
            int middle = top + (bottom - top) / 2;
            if (target < matrix[middle][0]) {
                bottom = middle - 1; 
            } else if (middle < matrix.size() - 1 && target >= matrix[middle + 1][0]) {
                top = middle + 1;
            } else {
                rowIndex = middle;
                break;
            }
        }

        int left = 0;
        int right = matrix[rowIndex].size() - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (matrix[rowIndex][middle] == target) {
                return true;
            }
            if (target < matrix[rowIndex][middle]) {
                right = middle - 1; 
            } else {
                left = middle + 1;  
            }
        }

        return false;
    }
};