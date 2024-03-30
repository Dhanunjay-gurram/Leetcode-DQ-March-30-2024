class Solution {
public:
    /*
     We used set concept like:
        if we have count of subarrays containing k and k-1 distinct elements respectively
     then their difference would give us the no of subarrays that are containing exactly k distinct elements
     */
    int atmostKDistinctSA(vector<int>& nums,int k){
        
        //Variables
        int left = 0,right = 0;
        int count = 0,ans = 0;
        
        //Map to store the frequency of the elements
        unordered_map<int,int> up;
        
        while(right<nums.size()){
            
        //Storing the frequency of the nums[right] element
            up[nums[right]]++;
            
            //To handle the condition of bringing the no of distinct elements <= k
            while(up.size()>k){
                
                //Decreasing the subarray from the left
                up[nums[left]]--;
                
                //If the nums[left]'s freq becomes zero which implies it is no longer in the subarray
                //thereby not contributing to the no of distinct elements
                //we erase the element from the map
                if(up[nums[left]]==0){
                    up.erase(nums[left]);
                }
                //Increment statement for left
                left++;
            }
            
            //After the loop :
            //It is guranteed that the subarray have atmost k distinct elements
            //We effectively count all the subarrays that end at the right index and satisfy the condition of having at most k distinct elements.
            //i.e. {nums[left] to nums[right]},{nums[left+1] to nums[right]}, {nums[left+2] to nums[right]}, ... ,{nums[right-1],nums[right]}, {nums[right]}  counting to right -left +1
            ans += right-left+1;
            
            //Increment statement
            right++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostKDistinctSA(nums,k) - atmostKDistinctSA(nums,k-1);
    }
};
