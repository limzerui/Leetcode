bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    //instinct would be to first look at the last 
    int totalElements = matrixSize * matrixColSize[0];
    int numberPerRow = matrixColSize[0];
    int start = 0;
    int end = matrixSize - 1;
    while (start <= end)
    {
        if (matrix[start][numberPerRow - 1] >= target)
        {
            end = start;
            break;
        }
        else
        {
            start ++;
        }
        if (matrix[end][0] <= target)
        {
            start = end;
            break;
        }
        else
        {
            end --;
        }

    }
    //look through the start and end row
    //do the bin search within the row. 
    int left = 0;
    int right = numberPerRow - 1;
    while (left <= right)
    {
        int middle = left + (right - left)/2;
        if (matrix[start][middle] == target)
        {
            return true;
        }
        if (matrix[start][middle] < target)
        {
            left = middle + 1;
        }
        if (matrix[start][middle] > target)
        {
            right = middle - 1;
        }
    }
    return false;

    return false;
}