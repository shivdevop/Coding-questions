class Solution {
public:

bool f(int mid,vector<int> weights,int days)
{       int day = 1;
    int currentWeight = 0;

    for (int weight : weights) {
        if (weight > mid) {
            return false; // A single weight exceeds the capacity, not possible
        }

        if (currentWeight + weight <= mid) {
            currentWeight += weight;
        } else {
            day++;
            currentWeight = weight;
        }

        if (day > days) {
            return false;
        }
    }

    return true;
}
    
    int shipWithinDays(vector<int>& weights, int days) {
    //day diya hua hai 1 toh hume highest range =>sum of all weights rakhna padega ki kya pata sab ek hi baar mei lekar jana pade!!!! 
    int sum=0;
    for(int i=0;i<weights.size();i++)
    sum+=weights[i];
    int low=1;
    int high=sum;//was given in constraint--> the max weight 
    int ans;//denotes  the min weight capacity of the ship
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(f(mid,weights,days))//if this weight capacity has the power to deliver within given days, then maybe check for smaller values as we have to find out the lowest!!!
        {high=mid-1;
        ans=mid;}//we got one answer
        else
        low=mid+1;//possible nhi hua isliye weight capacity badha kr dekhte hai 
    } //end of while
    return ans;  
    }
    
};