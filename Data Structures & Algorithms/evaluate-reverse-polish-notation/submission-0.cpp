class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        vector<int> sta;
        for(int i =0; i < tokens.size(); i++){
            if(isdigit(tokens[i][0]))
                sta.push_back(stoi(tokens[i]));
            else{
                if(tokens[i].size() > 1 && isdigit(tokens[i][1])){
                    sta.push_back(stoi(tokens[i]));
                    continue;
                }
                int arith = 0;
                int n = static_cast<int>(sta.size());
                if(tokens[i] == "+")
                    arith = sta[n - 2] + sta[n - 1];
                else if(tokens[i] == "-")
                    arith = sta[n - 2] - sta[n - 1];
                else if(tokens[i] == "*")
                    arith = sta[n - 2] * sta[n - 1];
                else if(tokens[i] == "/")
                    arith = sta[n - 2] / sta[n - 1];
                sta.pop_back();
                sta.pop_back();
                sta.push_back(arith);
            }

        }
        return sta[0];
    }
};