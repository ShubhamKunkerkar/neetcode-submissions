class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        unordered_set<int> prev;
        for (int i = 0; i < heights.size(); i++) {
            int m = heights[i];
            if (!prev.contains(i)) {
                for (int j = i; j < heights.size() && !prev.contains(j); j++) {
                    if (heights[j] <= m) {
                        prev.insert(j);
                    }
                    m = min(heights[j], m);
                    area = max(area, m * (j - i + 1));
                }
            }

            if (m == heights[i])
                prev.insert(i);
        }
        return area;
    }
};