class Solution {
public:
    int maxArea(vector<int>& height) {
       //find the biggest multiplication 
       //we need to start the left at 0 and right at last index(how to get the last index?)
       //
       int maxArea = 0;
       int left = 0;
       int right = height.size() - 1;

       while(left<right)
       {
        maxArea = max(maxArea, (right-left)*min(height[left], height[right]));
        if(height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
       }
       return maxArea;
        
    }
};