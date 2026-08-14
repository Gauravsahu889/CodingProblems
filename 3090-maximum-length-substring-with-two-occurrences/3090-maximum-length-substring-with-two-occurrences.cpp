class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int maxlen=0;

        for(int i=0;i<n;i++){
            int count[26]={0};
            for(int j=i;j<n;j++){
                int idx=s[j]-'a';
                count[idx]++;
                
                if(count[idx]>2){
                    break;
                }
                maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};