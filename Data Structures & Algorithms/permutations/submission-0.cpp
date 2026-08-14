class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> curr;
        unordered_set<int> used_indexes;
        backtrack(out, nums, -1, curr, used_indexes);
        return out;
    }
    void backtrack(vector<vector<int>>& out, vector<int>& nums, int index, vector<int>& curr, unordered_set<int>& used_indexes){
        if(curr.size() == nums.size()){
            out.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used_indexes.contains(i))
                continue;
            curr.push_back(nums[i]);
            used_indexes.insert(i);
            backtrack(out, nums, i, curr, used_indexes);
            curr.pop_back();
            used_indexes.erase(i);
        }
        
    }
};