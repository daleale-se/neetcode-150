#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // hashmap

        unordered_map<int, bool> hm;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (hm.find(nums[i]) != hm.end()) {
                return true;
            } else {
                hm.insert({nums[i], true});
            }            
        }
        return false;

        // unordered_map<int, int> dict;
        // for (int num: nums){
        //     if (dict[num] >=1)
        //         return true;
        //     dict[num] ++;
        // }
        // return false;

        // auxiliar arr

        // vector<int> aux;
        // int i = 0;
        // bool duplicated = false;
        // while(nums.size() > 0 && i < nums.size() && !duplicated) {
        //     if (count(aux.begin(), aux.end(), nums[i]) > 0) {
        //         duplicated = true;
        //     } else {
        //         aux.push_back(nums[i]);
        //         i++;
        //     }
        // } 
        // return duplicated;

        // sorting

        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]){
        //         return true;
        //     }
        // }
        // return false;  

        // O(n^2)

        // int i = 0;
        // int left;
        // int right;
        // bool res = false;
        // while(i < nums.size() && !res) {
        //     left = i + 1;
        //     right = nums.size() - 1;
        //     while(left <= (nums.size() + i)/2 && !res) {
        //         if (nums[i] == nums[left] || nums[i] == nums[right]) {
        //             res = true;
        //         } else {
        //             left++;
        //             right--;
        //         }
        //     }
        //     i++;
        // }
        // return res;

        // hashset 
        
        // unordered_set<int> seen;
        // for (int num : nums) {
        //     if (seen.count(num) > 0)
        //         return true;
        //     seen.insert(num);
        // }
        // return false;

    }
};

int main() {

    int myArr[] = {16,2,77,29};
    vector<int> myVector (myArr, myArr + sizeof(myArr) / sizeof(int) );

    Solution* sol = new Solution();
    cout << sol->containsDuplicate(myVector) << endl;

    return 0;
}