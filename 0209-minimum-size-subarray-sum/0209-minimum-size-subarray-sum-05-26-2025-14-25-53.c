
int minSubArrayLen(int target, int* nums, int numsSize) {
   int minLength = INT_MAX;
   int left = 0;
   int sum = 0;
   int right = 0;

   for(right = 0; right < numsSize; right ++)
   {
    sum += nums[right];

    while(sum>=target)
    {
        int windowSize = right-left+1;
        if((windowSize < minLength))
        {
            minLength = windowSize;
        }
        sum -= nums[left];
        left++;
    }
   }
   return minLength == INT_MAX ? 0:minLength;
}