class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if(hm.find(complement) != hm.end()) {
                vector<int> res{hm[complement], i};
                sort(res.begin(), res.end());
                return res;
            }
            hm[nums[i]] = i;
        }
        return {};
    }
};