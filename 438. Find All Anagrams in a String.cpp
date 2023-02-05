class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> index;
        if(p.size()>s.size())return index;
        vector<int> pCount(26);
        vector<int> sCount(26);
        for(int i=0;i<p.size();i++){
            pCount[p[i]-'a']++;
            sCount[s[i]-'a']++;
        }
        if(pCount==sCount){
            index.push_back(0);
        }
        for(int i=p.size();i<s.size();i++){
            sCount[s[i-p.size()]-'a']--;
            sCount[s[i]-'a']++;
            if(pCount==sCount){
                index.push_back(i-p.size()+1);
            }
        }
        return index;
    }
};