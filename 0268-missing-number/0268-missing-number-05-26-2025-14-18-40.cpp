class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //maybe get how many nums are there inside
        size_t count = nums.size();
        sort(nums.begin(), nums.end());
        for(size_t i = 0; i< count; i++)
        {
            if(nums[i] != i){
                return i;
            }
        }
        return nums.size();

    }
};