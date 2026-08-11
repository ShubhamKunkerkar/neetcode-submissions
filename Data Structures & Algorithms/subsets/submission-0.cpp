class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        subsets2(nums, {}, out, -1);
        return out;
    }
    void subsets2(vector<int>& nums, vector<int> curr, vector<vector<int>>& out, int index) {
        out.push_back(curr);
        for(int i = index+1; i < nums.size(); i++){
            curr.push_back(nums[i]);
            subsets2(nums, curr, out, i);
            curr.pop_back();
        }
    }
};