class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairs;
        
        for (int i = 0; i < position.size(); ++i) {
            pair<int,int> pair(position[i], speed[i]);
            pairs.push_back(pair);
        }

        sort(pairs.begin(), pairs.end(), [](auto &left, auto &right) {
            return left.first < right.first;
        });

        stack<float> stk;
        stk.push((float)(target - pairs.back().first)/pairs.back().second);

        for (int i = pairs.size() - 2; i >= 0; --i) {
            float curMed = (float)(target - pairs[i].first)/pairs[i].second;
            if (stk.top() < curMed) {
                stk.push(curMed);
            }
        }

        return stk.size();
    }
};