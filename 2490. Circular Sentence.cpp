class Solution {
public:
    bool isCircularSentence(string sentence) {
        char start=sentence[0];
        char end=sentence[sentence.size()-1];
        for(int i=0;i<sentence.size();i++){
            if(sentence[i+1]==' '){
                if(sentence[i]!=sentence[i+2]){
                    return false;
                }
            }
        }
        if(start!=end)return false;
        return true;
    }
};