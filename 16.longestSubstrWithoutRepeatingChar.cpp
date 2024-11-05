class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen; 
        int maxLongSeq = 0;
        int start = 0; 

        for (int end = 0; end < s.size(); ++end) {
            char c = s[end];
            if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= start) {
                start = lastSeen[c] + 1;
            }
            lastSeen[c] = end;
            maxLongSeq = max(maxLongSeq, end - start + 1);
        }

        return maxLongSeq;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         int maxLength = 0;
//         unordered_set<char> charSet;
//         int left = 0;
        
//         for (int right = 0; right < n; right++) {
//             if (charSet.count(s[right]) == 0) {
//                 charSet.insert(s[right]);
//                 maxLength = max(maxLength, right - left + 1);
//             } else {
//                 while (charSet.count(s[right])) {
//                     charSet.erase(s[left]);
//                     left++;
//                 }
//                 charSet.insert(s[right]);
//             }
//         }
        
//         return maxLength;
//     }
// };