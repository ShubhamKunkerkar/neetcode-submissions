class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        vector<int> curr;
        backtrack(out, curr, 0, k, n);
        return out; 
    }
    void backtrack(vector<vector<int>>& out, vector<int>& curr, int index, int& k, int& n){
        if(curr.size() == k){
            out.push_back(curr);
            return;
        }
        for(int i = index + 1; i <= n; i++){
            curr.push_back(i);
            backtrack(out, curr, i, k, n);
            curr.pop_back();
        }
    }
};