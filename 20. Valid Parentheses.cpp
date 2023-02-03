class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(' || ch=='[' || ch=='{'){
                p.push(ch);
            }else{
                if(!p.empty()){
                    if( ( ch == ')' && p.top()== '(' ) ||
                        ( ch ==']' && p.top()=='[') ||
                        ( ch =='}' && p.top()=='{') ){
                        p.pop();
                    }else{
                    return false;
                    }
                }else{
                    return false;
                }
            }
        } 
        if(p.empty()){
            return true;
        }else{
            return false;
        }
    }
};