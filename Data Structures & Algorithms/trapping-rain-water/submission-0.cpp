class Solution {
public:
    int trap(vector<int>& height) {
        int i =0;
        int j = height.size()-1;
        int max_height_i = height[i];
        int max_height_j = height[j];
        int area = 0;
        while(i<j){
            if(height[i] < height[j]){
                
                i++;
                max_height_i = max(height[i], max_height_i);
                area += max_height_i - height[i];
                // cout << "i" << " : " << i;
                // cout << ", j" << " : " << j;
                // cout << ", max_left" << " : " << max_height_i;
                // cout << ", max_right" << " : " << max_height_j;
                // cout << ", area" << " : " << area << '\n';
            }
            else if(height[i] >= height[j]){
                
                j--;
                max_height_j = max(height[j], max_height_j);
                area += max_height_j - height[j];
                // cout << "i" << " : " << i;
                // cout << ", j" << " : " << j;
                // cout << ", max_left" << " : " << max_height_i;
                // cout << ", max_right" << " : " << max_height_j;
                // cout << ", area" << " : " << area << '\n';
            } 
        }
        return area;
    }
};
