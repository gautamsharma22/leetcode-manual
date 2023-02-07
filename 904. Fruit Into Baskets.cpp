class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int second_last_fruit=0;
        int last_fruit=0;
        int last_fruit_count=0;
        int maxcount=0;
        int count=0;
        
        for(int i=0;i<fruits.size();i++){
            if(fruits[i]==last_fruit){
                last_fruit_count++;
            }
            if(fruits[i]==last_fruit || fruits[i]==second_last_fruit){
                count++;
            }else{
                count=last_fruit_count+1;
            }
            if(fruits[i]!=last_fruit){
                last_fruit_count=1;
                second_last_fruit=last_fruit;
                last_fruit=fruits[i];
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};