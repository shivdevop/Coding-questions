class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        while(x>0 || y>0)
        {
            int lastbit_x=x&1;
            int lastbit_y=y&1;
            x=x>>1;
            y=y>>1;
            count+= ((lastbit_x==lastbit_y)?0:1);
        }
        return count;
    }
};