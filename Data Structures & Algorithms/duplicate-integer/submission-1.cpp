class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> prev = {};
        for(int i = 0; i < nums.size(); i++){
            if(prev.find(nums[i]) != prev.end()){
                return true;
            }
            else{
                prev.insert(nums[i]);
            }
        }
        return false;
    }
};