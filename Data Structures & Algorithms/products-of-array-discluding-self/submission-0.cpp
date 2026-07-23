class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> b;
        b.push_back(1);
        int postfix = 1;
        for (int i = 0; i < nums.size()-1; i++) {
            b.push_back(b[i] * nums[i]);
        }
        std::cout << '\n';
        for (int i = nums.size() - 1; i > 0; i--) {
            postfix *= nums[i];
            b[i - 1] *= postfix;
        }
        return b;
    }
};