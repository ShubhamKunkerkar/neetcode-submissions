class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> sta = {0};
        if(temperatures.size() == 1){
            return{0};
        }
        vector<int> out(temperatures.size(), 0);
        for(int i = 1; i < temperatures.size(); i++){
            while (sta.size() > 0 && temperatures[i] > temperatures[sta.back()]){
                out[sta.back()] = (i - sta.back());
                sta.pop_back();
            }
            sta.push_back(i);
        }
        return out;
    }
};