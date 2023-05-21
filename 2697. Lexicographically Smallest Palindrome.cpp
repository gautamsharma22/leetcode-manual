class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int count=0;
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
                continue;
            }else{
                if(s[start]<s[end]){
                    s[end]=s[start];
                    start++;
                    end--;
                }else{
                    s[start]=s[end];
                    start++;
                    end--;
                }
            }
        }
        return s;
    }
};