class Solution {
public:
    /*
        Approach:-
        Only one main observation is Used         
        -> (If any character that has lower value comes before an character having higher value then its value is treated as negative);
        -> (If any character has higher value than next char then its added); 
    */
    int romanToInt(string s) {
        unordered_map<char,int> mapp;
        mapp.insert({'I',1});
        mapp.insert({'V',5});
        mapp.insert({'X',10});
        mapp.insert({'L',50});
        mapp.insert({'C',100});
        mapp.insert({'D',500});
        mapp.insert({'M',1000});
        int sum=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(i+1<n && mapp[s[i]]<mapp[s[i+1]]){
                sum+=(-mapp[s[i]]);
            }else{
                sum+=(mapp[s[i]]);
            }
        }
        return sum;
    }
};