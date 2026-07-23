class Solution {
public:
    string minWindow(string s, string t) {
        queue<int> indexes;
        unordered_map<char, int> given;
        for (int i = 0; i < t.size(); i++) {
            if (!given.contains(t[i]))
                given[t[i]] = 1;
            else
                given[t[i]]++;
        }
        int win_elements = 0;
        pair<int, int> out = {0, 0};
        bool first = true;
        for (int i = 0; i < s.size(); i++) {
            if (given.contains(s[i])) {
                indexes.push(i);
                given[s[i]]--;
                if (given[s[i]] == 0)
                    win_elements++;
                // cout << s[i] << " : "  << i << " : " << win_elements << endl;
                if (win_elements == given.size()) {
                    if (first) {
                        out = {i - indexes.front() + 1, indexes.front()};
                        first = false;
                    } else
                        out = min(out,
                                  {i - indexes.front() + 1, indexes.front()});
                }
                while (!indexes.empty() && win_elements == given.size()) {
                    given[s[indexes.front()]]++;
                    if (given[s[indexes.front()]] > 0 && win_elements > 0) {
                        win_elements--;
                    }
                    out = min(out, {i - indexes.front() + 1, indexes.front()});
                    indexes.pop();
                }
            }
        }

        string o = "";
        for (int i = out.second; i < out.second + out.first; i++) {
            o += s[i];
        }
        return o;
    }
};