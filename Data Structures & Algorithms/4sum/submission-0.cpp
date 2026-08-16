class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            for(int j = nums.size() - 1; j > i; j--){
                if(j != nums.size()-1 && nums[j] == nums[j+1])
                    continue;
                int left = i+1;
                int right = j-1;
                bool con = false;
                while(left < right){
                    if(left != i+1 && nums[left] == nums[left-1]){
                        left++;
                        con = true;
                    }
                    if(right != j-1 && nums[right] == nums[right+1]){
                        right--;
                        con = true;
                    }
                    if(con){
                        con = false;
                        continue;
                    }
                    long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum > target)
                        right--;
                    else if(sum < target)
                        left++;
                    else{
                        out.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;    
                    }
                }
            }
        }
        return out;
    }
};