class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //do double for loop?
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int a = nums[i];
            int left = i+1;
            int right = nums.size() - 1;
            while(left<right)
            {
                int sum = nums[left] + nums[right] + a;
                if(sum == 0)
                {
                    result.push_back({a, nums[left], nums[right]});
                    while(left<right && nums[left] == nums[left+ 1]) left++;
                    while(left<right && nums[right] == nums[right- 1]) right--;
                    left++;
                    right--;
                }
                else if(sum<0) {
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return result;
    }
};