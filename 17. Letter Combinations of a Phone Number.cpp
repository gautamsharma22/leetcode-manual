class Solution {
public:
void combination(vector<string>& MainAns,string ans,int index,string digits,string map[]){
if(index>=digits.length()){
    MainAns.push_back(ans);
    return;
}
int single=digits[index]-'0';
string mappedValue=map[single];
for(int i=0;i<mappedValue.length();i++){
    ans.push_back(mappedValue[i]);
    combination(MainAns,ans,index+1,digits,map);
    ans.pop_back();

}
}
    vector<string> letterCombinations(string digits) {
        vector<string> MainAns;
        if(digits.length()==0){
            return MainAns;
        }
        string ans;
        int index=0;
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        combination(MainAns,ans,index,digits,map);
        return MainAns;
    }
};