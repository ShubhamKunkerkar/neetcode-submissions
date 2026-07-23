class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        unordered_map<int, int> slide;
        vector<int> out;
        for(int i = 0; i < nums.size(); i++){
            if(!slide.contains(nums[i]))
                slide[nums[i]]  = 1;
            else
                slide[nums[i]]++;
            if(i < k)
                pq.push(nums[i]);
            if(i == k-1)
                out.push_back(pq.top());
            if(i > k -1){
                slide[nums[i-k]]--;
                if(slide[nums[i-k]] == 0)
                    slide.erase(nums[i-k]);
                pq.push(nums[i]);
                while(!slide.contains(pq.top()))
                    pq.pop();
                out.push_back(pq.top());
            }
        }
        return out;
    }
};