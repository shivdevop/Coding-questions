class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length();
        int count = 0;
        
        for (char c : s) {
            if (isalnum(c)) {
                count++;
            }
        }
        
        int length = count + (count - 1) / k; // Calculate the final length
        
        string ans;
        ans.resize(length); // Allocate memory for the result
        
        int idx = length - 1;
        int segmentCount = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if (isalnum(c)) {
                ans[idx--] = isalpha(c) ? toupper(c) : c;
                segmentCount++;
                if (segmentCount == k && idx > 0) {
                    ans[idx--] = '-';
                    segmentCount = 0;
                }
            }
        }
        
        return ans;
    }
};
