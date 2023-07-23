class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
      //create a map of map and vector of strings 
      vector<vector<string>> ans;
      map<map<char,int>,vector<string>> mp;
      
      for(int i=0;i<strs.size();i++)
      {
        //for every new string first we declare a map to track the frequency of each char in that string
        map<char,int> freqmap;
        string curr=strs[i];
        
        for(int k=0;k<strs[i].length();k++)
        freqmap[curr[k]]++;//freqmap of that string is ready 

        //lets push that particular freq map 
        mp[freqmap].push_back(curr);
      }        

      for(auto it:mp)
      ans.push_back(it.second);

      return ans;
        
    }
};