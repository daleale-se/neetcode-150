#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> count;
        
        // Count the frequency of characters in string s
        for (auto x : s) {
            count[x]++;
        }
        
        // Decrement the frequency of characters in string t
        for (auto x : t) {
            count[x]--;
        }
        
        // Check if any character has non-zero frequency
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }
        
        return true;

        // sorting

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
    }

};

int main() {
    Solution sol;

    cout << sol.isAnagram("car", "rat") << endl;

    return 0;
}