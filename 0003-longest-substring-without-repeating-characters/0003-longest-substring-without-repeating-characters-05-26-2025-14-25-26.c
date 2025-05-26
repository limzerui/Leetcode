int max(int a, int b)
{
    return (a>b)? a:b;
}

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int charIndex[128];
    for(int i = 0; i<128; i++)
    {
        charIndex[i] = -1;
    }
    int maxLength = 0;
    int left = 0;

    for(int right = 0; right<n; right++)
    {
        char currentChar = s[right];
        if(charIndex[currentChar] >= left)
        {
            left = charIndex[currentChar]+1;
        }
        charIndex[currentChar] = right;
        maxLength = max(maxLength, right-left+1);
    }
    return maxLength;
}