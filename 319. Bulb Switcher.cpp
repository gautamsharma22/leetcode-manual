class Solution
{
public:
    int bulbSwitch(int n)
    {
        // int count=0;
        // vector<bool> bulb(n,true);
        // for(int i=1;i<n;i++){
        //     for(int j=i;j<n;j+=i+1){
        //         bulb[j]=!bulb[j];
        //         // cout<<" "<<j+1<<endl;
        //     }
        //     // cout<<endl;
        // }
        // for(auto a:bulb){
        //     if(a){
        //         count++;
        //     }
        // }
        // return count;
        return sqrt(n);
    }
};