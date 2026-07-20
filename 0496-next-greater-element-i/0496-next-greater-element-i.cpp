class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int x:nums1){
            int ans=-1;

            //found x 
            for(int i=0;i<nums2.size();i++){
                if(nums2[i]==x){
                    for(int j=i+1;j<nums2.size();j++){
                        if(nums2[j]>x){
                            ans=nums2[j];
                            break;
                        }
                    }
                    break;
                }
            }
            res.push_back(ans);
        }
        return res;
    
    }
};