class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {};
        int left = 0;
        int max_freq = 0;
        int result = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            max_freq = max(max_freq, count[s[right] - 'A']);

            while ((right - left + 1) - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};