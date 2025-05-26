class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //was thinking of using the division operator then times the previous one. 
        //but why cant?
        int n = nums.size();

        vector<int> output(n);
        output[0] = 1;
        for(int i = 1; i<n;i++)
        {
            output[i] = output[i-1] * nums[i-1];
        }

        int right = 1;
        for(int i = n-1; i>=0; i--)
        {
            output[i] *=  right;
            right *= nums[i];
        }
        return output;
    }
};