class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //sliding window implementation
        //keep track of the max
        
        int size = nums.size();
        int max_sum = -101001010110101;
        int curr_sum = 0;

        for(int i = 0; i < size; i++){
            curr_sum += nums[i];
            max_sum = max(max_sum, curr_sum);

            if(curr_sum < 0){
                curr_sum = 0;
            }
        }
        return max_sum;



        
        
    }
};