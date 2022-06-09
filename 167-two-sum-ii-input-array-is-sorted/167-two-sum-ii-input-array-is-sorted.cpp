class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // To store pair
        vector<int> pairIndex;
        
        // iterate over each index
        for(int i=0;i<numbers.size()-1;i++){
            int high=numbers.size()-1;
            int low=i+1;
            
            // apply binary search from i+1 to end of array
            
            while(high-low>1){
                int mid=low+(high-low)/2;
                if(numbers[mid]+numbers[i]>target){
                    high=mid-1;
                }else low=mid;
            }
            if(numbers[high]+numbers[i]==target){
                pairIndex.push_back(i+1);
                pairIndex.push_back(high+1);
                break;
            }
            if(numbers[low]+numbers[i]==target){
                pairIndex.push_back(i+1);
                pairIndex.push_back(low+1);
                break;
            }
        }
        return pairIndex;
    }
};