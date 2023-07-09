class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> change;

        if(bills[0]>5)
        return false;
         
        int i=0;
        while(i<bills.size())
        {
          if(bills[i]==5)
          {
              change[5]++;
            
          }
          else if(bills[i]==10)
          {
              if(change[5]>=1)
              change[5]--;
              else 
              return false;

              change[10]++;
          }
          else 
          {
              if(change[5]>=1 && change[10]>=1)
              {
                  change[5]--;
                  change[10]--;
              }
              else if(change[5]>=3)
              {
                  change[5]-=3;
              }
              else
              return false;

              change[20]++;

          }
          i++;
        }
return true;

    }
};
//if the first amount is greater than 5 then directly false

//need to maintain a change variable and constant update it
//if change is less than bill-5 then return false
// else
// just update the change