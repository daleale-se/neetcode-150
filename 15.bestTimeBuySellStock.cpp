// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxProfit = 0;
//         for (int i = prices.size() - 1; i >= 0; --i) {
//             for (int j = 0; j <= i; j++) {
//                 if (maxProfit == 0 || maxProfit < prices[i] - prices[j]) {
//                     maxProfit = prices[i] - prices[j];
//                 }
//             }
//         }
//         return maxProfit;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i]; 
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;  
            }
        }
        
        return maxProfit;
    }
};