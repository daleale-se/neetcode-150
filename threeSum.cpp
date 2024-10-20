class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        unordered_set<int> set;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                int cur = nums[i];
                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right) {
                    if (cur + nums[left] + nums[right] == 0) {
                        if (set.count(nums[left]) == 0 && set.count(nums[right]) == 0) {
                            vec.push_back({cur, nums[left], nums[right]});
                            set.insert({nums[left], nums[right]});
                        }
                        right--;
                        left++;
                    } else if (cur + nums[left] + nums[right] > 0) {
                        right--;
                    } else {
                        left++;
                    }
                }
                set.clear();
            }
        }
        return vec;
    }
};
