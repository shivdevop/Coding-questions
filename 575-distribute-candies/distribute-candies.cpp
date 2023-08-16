class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
       map<int,int> mp;

       int n=candyType.size();
       for(int i=0;i<n;i++)
       mp[candyType[i]]++;
       
       n=n/2;
       int types=mp.size();
       return (types<=n)?types:n;
    }
};