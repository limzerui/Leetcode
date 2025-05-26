class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastnonzeroindex = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[lastnonzeroindex] = nums[i];
                lastnonzeroindex++;
            }
        }
        for(int i = lastnonzeroindex ; i<nums.size(); i++)
        {
            nums[i] = 0;
        }
        
    }
};