class Solution {
public:
    bool digitSum(string s,int rem){
        if(rem<0)return false;
        int n=s.length();
        if(s.empty() && rem==0){
            return true;
        }
        bool ans=false;
        for(int i=0;i<n;i++){
            string temp=s.substr(0,i+1);
            int currVal=stoi(temp);
            ans=ans or digitSum(s.substr(i+1),rem-currVal);
            if(ans){
                return true;
            }
        }
        return ans;
    }
    int punishmentNumber(int n) {
        int ans=1;
        for(int i=2;i<=n;i++){
            if(digitSum(to_string(i*i),i)){
                ans+=(i*i);
            }
        }
        return ans;
    }
};