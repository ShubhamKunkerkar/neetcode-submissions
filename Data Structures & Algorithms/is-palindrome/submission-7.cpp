#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.length(); i++){
            if(!isalnum(s[i])){
                s.erase(i, 1);
                i--;                // IMPORTANT FIX
            } else {
                s[i] = tolower(s[i]);
            }
        }
        for(const auto& i: s){
            cout<< i;
        }
        for(int i = 0; i < std::ceil(s.length() / 2); i++){
            if(s[i] != s[s.length() - 1 - i]){
                return false;
            }
        }
        // if(s.length() == 1)
        //     return false;
        return true;
    }
};