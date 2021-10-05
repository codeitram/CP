class Solution
{
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> final;
        bool flag = true;
        // if(nums1[0]==nums2[0])final.push_back(nums1[0]);
        
        while (i < nums1.size() and j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                if(flag)
                {
                    final.push_back(nums1[i]);
                    flag =false;
                }
                if( final.back()!=nums1[i])
                final.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return final;
    }
};