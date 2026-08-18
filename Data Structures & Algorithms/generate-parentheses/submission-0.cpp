class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string bracks = "";
        for (int i = 0; i < n; i++)
            bracks += '(';
        for (int i = 0; i < n; i++)
            bracks += ')';
        string curr;
        unordered_set<int> used_indexes;
        backtrack(out, bracks, curr, used_indexes);
        return out;
    }
    void backtrack(vector<string>& out, string& bracks, string& curr,
              unordered_set<int> used_indexes) {

        if (curr.size() == bracks.size()) {
            stack<char> s;
            for (int i = 0; i < curr.size(); i++) {
                if (!s.empty() && s.top() == '(' && curr[i] == ')') {
                    s.pop();
                } else {
                    s.push(curr[i]);
                }
            }
            if (s.empty())
                out.push_back(curr);
            return;
        }

        for (int i = 0; i < bracks.size(); i++) {
            if (bracks.contains(i))
                continue;
            if(i > 0 && bracks[i] == bracks[i-1] && !bracks.contains(i))
                continue;
            curr += bracks[i];
            used_indexes.insert(i);
            backtrack(out, bracks, curr, used_indexes);
            curr.pop_back();
            used_indexes.erase(i);
        }
    }
};