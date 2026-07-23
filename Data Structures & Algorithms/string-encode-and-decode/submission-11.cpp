class Solution {
public:
    vector<int> sizes;
    string encode(vector<string>& strs) {
        string a = "";
        for(int i = 0; i < strs.size(); i++){
            sizes.push_back(strs[i].size());
            a += strs[i];
        }
        return a;
    }

    vector<string> decode(string s) {
        int index = -1;
        vector<string> vec;
        int j = 0; 
        for(int i =0; i < s.size();){
            if(index == -1 || j == sizes[index]){
                index++;
                vec.push_back("");
                if(sizes[index] == 0){
                    vec.push_back("");
                    index++;
                }
                j = 0;
            }
            if(i < s.size() && sizes[index] != 0){
                j++;
                vec[index] += s[i];
                i++;
            }
        }
        for(int i = index+1; i < sizes.size(); i++){
            vec.push_back("");
        }
        return vec;
    }
};
