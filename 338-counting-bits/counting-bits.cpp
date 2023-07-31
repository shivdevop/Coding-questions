class Solution {
public:
    vector<int> countBits(int n) {
    
    vector<int> tracksetbits(n+1,0);
   for(int i=0;i<=n;i++)
   {
     if(i%2==0)
     tracksetbits[i]=tracksetbits[i/2];
     else 
     tracksetbits[i]=tracksetbits[i/2]+1;
   }
   return tracksetbits;
    }
};