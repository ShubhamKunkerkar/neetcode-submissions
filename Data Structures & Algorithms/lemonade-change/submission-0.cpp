class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3);
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                change[0]++;
            } else if(bills[i] == 10){
                if(change[0] > 0){
                    change[0]--;
                } else{
                    return false;
                }
                change[1]++;
            } else{
                if(change[0] > 0){
                    change[0]--;
                }else{
                    return false;
                }
                if(change[1] > 0){
                    change[1]--;
                }else{
                    if(change[0] >= 2){
                        change[0] -=2;
                    }else{
                        return false;
                    }
                }
                change[2]++;
            }
        }
        return true;
    }
};