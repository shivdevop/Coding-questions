class Solution {
public:

    int maxEvents(vector<vector<int>>& events) {
         int n=events.size();
   
      
       priority_queue<int,vector<int>,greater<int>> pq;//created a priority queue for pushing and getting the earliest ending day so that we can attend that event first  

        sort(events.begin(),events.end());
        int countans=0;
        int i=0;
        for(int day=1;day<=100000;day++) //traversing over the days 
        { 
            //agar koi bhi event ka ending date khtm ho chuka hai toh wo kisi kaam ka nhi use queue se hata do
            while(!pq.empty() && pq.top()<day)
            {
                pq.pop();
            }

            //jo bhi events aaj wale din start ho rhe hai unhe queue mei laga do
            while(i<n && events[i][0]==day)
            {
                pq.push(events[i][1]);
                i++;
            }

            //ed din mei koi ek event attend ho sakta hai toh ek event attend krlo aur saath mei bhi check bhi krlo ki kahi ending date pehle ka toh nhi hai kyuki naye elements bhi push hue hai !!!
            if(!pq.empty() && pq.top()>=day)
            {
                pq.pop();
                countans++;
            }

            //agar events aur nhi bache hai attend krne ke liye (queue empty) and list of events bhi khtm ho chuke hai add krne ke liye then break
            if(pq.empty()  &&  i==n)
            break;
        }
        return countans;
    }
};