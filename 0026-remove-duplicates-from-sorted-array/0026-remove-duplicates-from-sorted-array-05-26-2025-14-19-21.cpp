class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //iterate through the array
        //the next one should be a new one
        int slow = 0;
        int fast = 1;
        while(fast<nums.size()){
            if(nums[fast] != nums[slow]){
                slow++;
                nums[slow] = nums[fast];
            }
            fast++; 
        }
        return slow+1;
    }
};