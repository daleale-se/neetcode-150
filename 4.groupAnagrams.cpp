class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;
        vector<vector<string>> res;
        string key;
        for (string word : strs) {
            key = word;
            sort(key.begin(), key.end());
            hm[key].push_back(word);
        }
        for (const auto& pair : hm) {
            res.push_back(pair.second);
        }
        return res;
    }
};
