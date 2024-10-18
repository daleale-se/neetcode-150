class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        for (int i = 0; i < nums.size(); ++i) {
            hm[nums[i]]++;
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            int maxKey;
            bool foundMax = false;
            for (auto& [key, value]: hm) {
                if (!foundMax || value > hm[maxKey]) {
                    maxKey = key;
                    foundMax = true;
                }
            }
            hm.erase(maxKey);
            res.push_back(maxKey);
        }
        return res;
    }
};