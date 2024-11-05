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
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
