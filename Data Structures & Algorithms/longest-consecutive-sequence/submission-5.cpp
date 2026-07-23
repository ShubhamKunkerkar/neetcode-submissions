class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_set<int> dict;
        vector<int> a;
        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(nums[i]) == dict.end()) {
                dict.insert(nums[i]);
            }
        }
        int count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(nums[i] + 1) != dict.end() &&
                dict.find(nums[i] - 1) == dict.end()) {
                int k = nums[i];
                int tot = 1;
                while (dict.find(k + 1) != dict.end()) {
                    tot++;
                    k = k + 1;
                    count = max(tot, count);
                }
            }
        }
        

        return count;
    }
};
