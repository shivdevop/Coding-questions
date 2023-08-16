class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        map<string,pair<int,int>> mp;//pair of index and count
        for(int i=0;i<list1.size();i++)
        mp[list1[i]]={i,1};

        for(int i=0;i<list2.size();i++)
        {
            if(mp.find(list2[i])!=mp.end())
            {auto& it=mp[list2[i]];
             it.first+=i;
             it.second=2;}
        }
 
        int minsumindex=INT_MAX;
        for(auto it:mp)
        {
          if(it.second.second==2 && it.second.first<minsumindex)
          minsumindex=it.second.first;

        }
        vector<string> ans;
        for(auto it:mp)
        {
            if(it.second.second==2 && it.second.first==minsumindex)
            ans.push_back(it.first);
        }
        return ans;
    }
};