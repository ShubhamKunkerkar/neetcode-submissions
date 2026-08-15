class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> out;
        vector<int> curr;

        backtrack(nums, -1, curr, out);

        return out;
    }

    void backtrack(vector<int>& nums, int index, vector<int>& curr,
                   vector<vector<int>>& out) {

        out.push_back(curr);

        for (int i = index + 1; i < nums.size(); i++) {

            if (i > index + 1 && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);

            backtrack(nums, i, curr, out);

            curr.pop_back();
        }
    }
};