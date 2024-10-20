class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string str : strs) {
            string newStr = to_string(str.size()) + "-" + str;
            encoded += newStr;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        string strLen = "";
        while (i < s.size()) {
            strLen += s.at(i);
            if (s.at(i + 1) == '-') {
                strs.push_back(s.substr(i + 2, stoi(strLen)));
                i += stoi(strLen) + 2;
                strLen = "";
            } else {
                i++;
            }
        }
        return strs;
    }
};