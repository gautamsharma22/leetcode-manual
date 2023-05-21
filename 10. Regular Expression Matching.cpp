// class Solution {
// public:
//     int n=0;
//     int m=0;
//     bool match(string &s,string &p,int i,int j) {
//         if(i == m && j == n) return true;
//         if(j == n) return false;
//         bool check=(i<m) && (s[i] == p[j] || p[j]=='.');
//         if(j+1 < n && p[j+1] == '*'){
//             return match(s,p,i,j+2) || check && match(s,p,i+1,j);
//         }
//         if(check){
//             return match(s,p,i+1,j+1);
//         }
//         return false;
//     }
//     bool isMatch(string s, string p) {
//         m=s.length();
//         n=p.length();
//         return match(s,p,0,0);
//     }
// };
class Solution {
public:
    int dp[25][25];
    int n=0;
    int m=0;
    bool match(string &s,string &p,int i,int j) {
        if(i == m && j == n) return dp[i][j] = true;
        if(j == n) return dp[i][j] = false;
        if(dp[i][j]!=-1)return dp[i][j];
        bool check=(i<m) && (s[i] == p[j] || p[j]=='.');
        if(j+1 < n && p[j+1] == '*'){
            return dp[i][j] = match(s,p,i,j+2) || check && match(s,p,i+1,j);
        }
        if(check){
            return dp[i][j] = match(s,p,i+1,j+1);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        m=s.length();
        n=p.length();
        memset(dp,-1,sizeof(dp));
        return match(s,p,0,0);
    }
};