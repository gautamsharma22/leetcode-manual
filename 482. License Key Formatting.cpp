class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n=s.length()-1;
        string x;
        int flag=0;
        for(int i=n;i>=0;i--){
            if(s[i]!='-'){
            x.push_back(toupper(s[i]));
            flag++;
            }
            if(flag==k){
                x.push_back('-');
                flag=0;
            }
        }
        if (x.size() > 0 && x.back() == '-') {
           x.pop_back();
        }
        reverse(x.begin(),x.end());
        return x;
    }
};