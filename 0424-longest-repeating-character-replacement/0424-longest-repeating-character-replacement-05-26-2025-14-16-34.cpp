class Solution {
public:
    int characterReplacement(string s, int k) {
        //sliding window
        //convert the first one to the neighbour
        //
        int length = s.size();
        int left = 0;

        vector<int> matrix(26,0);
        int max_freq = 0;
        int maxLength = 0;

        for(int right = 0; right < length; right++){
            matrix[s[right]-'A']++;
            max_freq = max(max_freq, matrix[s[right]-'A']);
            if((right-left+1)-max_freq>k){
                matrix[s[left]-'A']--;
                left++;
                max_freq = *max_element(matrix.begin(), matrix.end());
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};