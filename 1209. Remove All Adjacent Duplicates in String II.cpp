class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() || s[i]!=st.top().first){
                st.push({s[i],1});
            }else{
                auto prev=st.top();
                st.pop();
                st.push({s[i],prev.second+1});
                if(st.top().second==k)st.pop();
            }
        }
        

        string ans="";
        while(!st.empty()){
            auto x=st.top();
            while(x.second--){
                ans.push_back(x.first);
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};