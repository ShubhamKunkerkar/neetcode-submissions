class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> chars_val;
        chars_val.reserve(26);
        priority_queue<int> pq; // freq, char
        int freq[26] = {};
        for (char& c : tasks)
            freq[c - 'A']++;
        for (int i = 0; i < 26; i++)
            if (freq[i])
                pq.push(freq[i]);

        int out = 0;
        while (!pq.empty()) {
            int k = n;
            while (!pq.empty() && k >= 0) {
                auto it = pq.top();
                if (it - 1 != 0) {
                    chars_val.push_back(it - 1);
                }
                out++;
                pq.pop();
                k--;
            }
            for (int i = 0; i < chars_val.size(); i++) {
                pq.push(chars_val[i]);
            }
            if (!pq.empty()) {
                out += k + 1;
            }
            chars_val.clear();
        }
        return out;
    }
};