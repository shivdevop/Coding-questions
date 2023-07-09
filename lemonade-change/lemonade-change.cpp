class Solution {
public:
   bool lemonadeChange(vector<int>& bills) {
      int count5 = 0;
    int count10 = 0;
    
    if (bills[0] > 5)
        return false;
    
    for (int i = 0; i < bills.size(); i++) {
        int bill = bills[i];
        
        if (bill == 5) {
            count5++;
        } else if (bill == 10) {
            if (count5 > 0) {
                count5--;
                count10++;
            } else {
                return false;
            }
        } else if (bill == 20) {
            if (count10 > 0 && count5 > 0) {
                count10--;
                count5--;
            } else if (count5 >= 3) {
                count5 -= 3;
            } else {
                return false;
            }
        }
    }
    
    return true;
}

};
//if the first amount is greater than 5 then directly false

//need to maintain a change variable and constant update it
//if change is less than bill-5 then return false
// else
// just update the change