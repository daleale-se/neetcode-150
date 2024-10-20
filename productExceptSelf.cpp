class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int product = 1;
        // int quantityOfZeros = 0;
        // for (int i = 0; i < nums.size(); ++i) {
        //     int n = nums[i];
        //     if (n == 0) {
        //         quantityOfZeros++;
        //     } else {
        //         product *= n;
        //     }
        // }

        // vector<int> products;
        // for (int i = 0; i < nums.size(); ++i) {
        //     int cur = nums[i];
        //     if (quantityOfZeros == 1) {
        //         if (cur == 0) {
        //             products.push_back(product);
        //         } else {
        //             products.push_back(0);
        //         }
        //     } else if (quantityOfZeros == 0) {
        //         products.push_back(product / cur);
        //     } else {
        //         products.push_back(0);
        //     }
        // }
        // return products;

        int n = nums.size();
        vector<int> products(n, 1); 
        
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            products[i] = leftProduct;
            leftProduct *= nums[i];
        }
        
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            products[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return products;
    }   
};
