class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ranks(n);

        priority_queue<pair<int,int>> pq;

        for(int i=0;i<n;i++)
        pq.push({score[i],i});

       int count=0;
       while(!pq.empty())
       {   count++;
           auto it=pq.top();
           int position=it.second;
           if(count==1)
           ranks[position]="Gold Medal";
           else if(count==2)
           ranks[position]="Silver Medal";
           else if(count==3)
           ranks[position]="Bronze Medal";
           else
           ranks[position]=to_string(count);

           pq.pop();
       }

       return ranks;
    }
};