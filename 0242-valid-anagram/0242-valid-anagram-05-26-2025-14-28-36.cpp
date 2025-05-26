class Solution {
public:
    bool isAnagram(string s, string t) {
        //put everything in a dictionary using a for loop
        if(s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> numMap;

        for(char c : s)
        {
            numMap[c]+=1;
        }

        for(char c : t)
        {
            numMap[c]-=1;
            if(numMap[c]<0)
            {
                return false;
            }
        }
        return true;
    }
};