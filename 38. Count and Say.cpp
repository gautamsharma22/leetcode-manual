class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string s="11";
        for(int i=3;i<=n;i++){
            int count =1;
            string t="";
            s=s+'\0'; // Prevent Skipping last value
            for(int j=1;j<s.length();j++){
                if(s[j]==s[j-1]){
                    count++;
                }else{
                    t+=count+'0'; // We can use to_string also 
                    t+=s[j-1];
                    count=1;
                }
            }
            s=t;
        }
        return s;
    }
};

//Notes :
/* 

This problem was same as String compression with some changes and complicated test cases.

Adding '0' with integer allows us get integer to string with values upto 0 to 9.

*/