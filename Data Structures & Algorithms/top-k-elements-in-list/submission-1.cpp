class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        vector<pair<int, int>> kv;
        for(int i = 0; i < nums.size(); i++){
            if(dict.find(nums[i]) == dict.end()){
                kv.push_back({nums[i], 1});
                dict.insert({nums[i], kv.size()-1});
            }else{
                kv[dict[nums[i]]].second++;
            }
        }
        
        sort(kv.begin(), kv.end(), [](auto &a, auto &b) {
            return a.second < b.second;  // sort only by the char
        });
        // for(auto i : kv){
        //     cout<< i.first <<":" << i.second << " ";
        // }
        vector<int> vec;
for (auto it = kv.rbegin(); it != kv.rbegin() + k && it != kv.rend(); ++it) {
    vec.push_back(it->first);
}
return vec;

    }
};
