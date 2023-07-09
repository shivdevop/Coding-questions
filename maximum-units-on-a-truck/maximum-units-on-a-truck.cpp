class Solution {
public:
   static bool comp(vector<int> a,vector<int> b)
  {   return a[1]>b[1]; }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int currsize=0;
        int totalunits=0;
        for(int i=0;i<boxTypes.size();i++)
        {   int boxes=boxTypes[i][0];
            int unitsperbox=boxTypes[i][1];

            if(currsize+boxes <= truckSize)
            {totalunits+=(unitsperbox*boxes);
            currsize+=boxes;}
            else
            {
                totalunits+=unitsperbox*(truckSize-currsize);
                break;
            }
        }
        return totalunits;

    }
};