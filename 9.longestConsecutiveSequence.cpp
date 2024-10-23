class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 1;
        int finalLongest = 0; 
        for (const auto& n: set) {
            if (set.find(n - 1) == set.end()) {
                int i = n + 1;
                while (set.find(i) != set.end()){
                    longest++;
                    i++;
                }
            }
            if (longest > finalLongest) {
                finalLongest = longest;
            }
            longest = 1;
        }
        return finalLongest;
    }
};