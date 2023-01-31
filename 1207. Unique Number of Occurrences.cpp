class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       vector<int> freq;
        
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int count =0;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]==arr[j]){
                    count++;
                }
                    else{
                        break;
                    }
                }
                freq.push_back(count);
                i=i+count;
            }
            for(int v=0;v<freq.size();v++){
                cout<<freq[v];
            }
            sort(freq.begin(),freq.end());
            for(int i=0;i<freq.size()-1;i++){
                if(freq[i]==freq[i+1])
                    return false;
            }
         return true;
        }
};