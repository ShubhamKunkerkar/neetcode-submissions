class Solution {
public:
    bool isValid(string s) {
        stack<char> val;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(')
                val.push(s[i]);
            else if (!val.empty() && val.top() == '{' && s[i] == '}')
                val.pop();
            else if (!val.empty() && val.top() == '[' && s[i] == ']')
                val.pop();
            else if (!val.empty() && val.top() == '(' && s[i] == ')')
                val.pop();
            else
                return false;
        }
        if(val.size() != 0)
            return false;
        return true;
    }
};