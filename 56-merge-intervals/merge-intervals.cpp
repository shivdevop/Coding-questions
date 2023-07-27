class Solution {
public:
    // static bool comp(vector<int> a,vector<int> b)
    // {
    //     if(a[0]==b[0])
    //     return a[1]<b[1];

    //     return a[0]<b[0];
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        
        vector<int> temp={intervals[0][0],intervals[0][1]};

        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=temp[1] || intervals[i][1]<=temp[1]  )
            {
               temp[0]=min(temp[0],intervals[i][0]);
               temp[1]=max(temp[1],intervals[i][1]);
            }
            else
            {
              ans.push_back(temp);
              temp.clear();
              temp={intervals[i][0],intervals[i][1]};

            }
        }
        ans.push_back(temp);
    return  ans;
    }
};