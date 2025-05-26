class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0;
        int tp = 0;

        while(tp<t.length() && sp<s.length())
        {
            if(s[sp] == t[tp])
            {
                sp++;
            }
            tp++;
        }
        return sp==s.length();
    }
};