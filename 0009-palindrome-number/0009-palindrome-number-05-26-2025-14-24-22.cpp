class Solution {
public:
    bool isPalindrome(int x) {
        //need to find out how many digits x has?
        
        if(x<0)
        {
            return false;
        }

        long reverse = 0;
        int xcopy = x;

        while(x>0)
        {
            reverse = (reverse*10) + (x%10);
            x/=10;
        }
        return reverse == xcopy;
    }
};