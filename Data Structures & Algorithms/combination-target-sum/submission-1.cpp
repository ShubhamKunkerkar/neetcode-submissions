class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> curr;
        branch(candidates, target, 0, out, -1, curr);
        return out;
    }
    void branch(vector<int>& candidates, int target, int sum, vector<vector<int>> &out, int index, vector<int>& curr){
        if(index != -1){
            sum += candidates[index];
        }
        if(sum > target){
            return;
        }
        if(sum == target){
            out.push_back(curr);
            return;
        }
        for(int i = (index == -1 ? 0 : index); i < candidates.size(); i++){
            curr.push_back(candidates[i]);
            branch(candidates, target, sum, out, i, curr);
            curr.pop_back();
        }
    }
};
