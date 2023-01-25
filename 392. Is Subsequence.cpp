class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0){
            return true;
        }
        if(t.length()==0){
            return false;
        }
        int si=0;
        for(int i=0;i<t.length();i++){
            if(s[si]==t[i]){
                si++;
            }
        }
        if(si==s.length())
            return true;
        else return false;
    }
};