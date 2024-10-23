class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        int half = filtered.size() / 2;
        int startRight = half;
        if (filtered.size() % 2 != 0){
            startRight++;
        }
        for(int i = 0; i < half; ++i) {
            if(filtered.at(half - 1 - i) != filtered.at(startRight + i)) {
                return false;
            }
        }
        return true;
    }
};