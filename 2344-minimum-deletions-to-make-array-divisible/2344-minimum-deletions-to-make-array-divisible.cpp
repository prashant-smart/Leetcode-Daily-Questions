class Solution {
public:
   int gg(int a, int b)
    {
      if (a == 0)
        return b;
      return gg(b % a, a);
    }

 
    int fd(vector<int> a, int n)
    {
      int r = a[0];
      for (int i = 1; i < n; i++)
      {
        r = gg(a[i], r);

        if(r == 1)
        {
        return 1;
        }
      }
      return r;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        long long k=fd(numsDivide,numsDivide.size());
        sort(begin(nums),end(nums));
        int ans=0;
        // cout<<k<<" ";
        for(int i=0;i<nums.size();i++){
            if(k%nums[i]==0){
                return i;
            }
            ans++;
        }
        return -1;
    }
};