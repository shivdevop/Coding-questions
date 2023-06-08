class Solution {
public:
 bool checkStraightLine(vector<vector<int>>& coordinates) {
    int m = coordinates.size();
    if (m == 2)
        return true;

    float slope, c;
    if ((coordinates[1][0] - coordinates[0][0]) != 0) {
        slope = static_cast<float>(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        c = coordinates[0][1] - (slope * coordinates[0][0]);
    } else {
        int x = coordinates[0][0];
        for (int i = 2; i < m; i++) {
            if (coordinates[i][0] != x)
                return false;
        }
        return true; // All x-coordinates are the same, so it's a vertical line
    }

    for (int i = 2; i < m; i++) {
        // if ((coordinates[i][0] - coordinates[i - 1][0]) == 0) {
        //     if (coordinates[i][0] != coordinates[i - 1][0])
        //         return false;
        // } else {
            int y = slope * coordinates[i][0] + c;
            if (y != coordinates[i][1])
                return false;
        // }
    }

    return true;
}

};