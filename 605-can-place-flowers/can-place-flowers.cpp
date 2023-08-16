class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
     
      int length=flowerbed.size();
      if(length==1 && flowerbed[0]==0 )
      return (n<=1)?true:false;
      if(length==1 && flowerbed[0]==1)
      return (n==0)?true:false;
      int i=0;
      while(n>0 && i<length)
      {
        if(flowerbed[i]==0 && i-1>=0 && i+1<length && flowerbed[i-1]==0 && flowerbed[i+1]==0)
        {flowerbed[i]=1;n--;}
        else if(flowerbed[i]==0 && i-1>=0 && i+1>=length && flowerbed[i-1]==0 )
        {flowerbed[i]=1;n--;}
        else if(flowerbed[i]==0 && i+1>=0 && i-1<0 &&  flowerbed[i+1]==0 )
           {flowerbed[i]=1;n--;}

           i++;
      }  
      if(n==0)
      return true;
      return false;
    }
};