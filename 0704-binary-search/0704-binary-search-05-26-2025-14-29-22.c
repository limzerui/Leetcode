#include <math.h>

int search(int* nums, int numsSize, int target) {
    int leftPointer = 0;
    int rightPointer = numsSize - 1;
    while (leftPointer <= rightPointer)
    {
        int middlePointer = floor((leftPointer + rightPointer) / 2);
        if (nums[middlePointer] == target)
        {
            return middlePointer;
        }
        if (nums[middlePointer] < target)
        {
            leftPointer = middlePointer + 1;
        }
        else
        {
            rightPointer = middlePointer - 1;
        }
    }
    return -1;
}