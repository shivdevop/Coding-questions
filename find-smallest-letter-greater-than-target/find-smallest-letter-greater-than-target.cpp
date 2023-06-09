class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        char ch;
        int count=0;
        int n=letters.size();
        for(int i=0;i<n;i++)
        {
            if(letters[i]>target)
            {
                count++;
                ch=letters[i];
                break;
            }
        }
        if(count>0)
        return ch;
        else
        return letters[0];
    }
};