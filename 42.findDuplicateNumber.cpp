// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         vector<int> aux;
//         for(int i = 0; i < nums.size(); ++i) {
//             if (find(aux.begin(), aux.end(), nums[i]) != aux.end()) {
//                 return nums[i];
//             } else {
//                 aux.push_back(nums[i]);
//             }
//         }
//         return 0;
//     }
// };


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Step 1: Use Floyd's Tortoise and Hare cycle detection algorithm
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Move slow by one step and fast by two steps
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find the entrance to the cycle (the duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
