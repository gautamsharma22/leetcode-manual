class Solution {
public:
    bool helper(int &wordSize,int &totalLen,const string &s,unordered_map<string,int> mapp){
        for(int j=0;j<s.size();j+=wordSize){
            string tempStr=s.substr(j,wordSize);
            if(mapp.find(tempStr)!=mapp.end()){
                if(--mapp[tempStr]<0)return false;
            }else{
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> mapp;
        for(auto a:words){
            mapp[a]++;
        }
        int wordSize=words[0].size();
        int totalLen=wordSize*words.size();
        for(int i=0;i+totalLen<=s.size();i+=wordSize){
            if(helper(wordSize,totalLen,s.substr(i, totalLen),mapp)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};