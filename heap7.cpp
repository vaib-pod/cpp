//621 task scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> pq;
        for(auto it : freq){
            pq.push(it.second);
        }
        int time = 0 ;
        while(!pq.empty()){
            vector<int> temp;
            int cycle = n+1; 
            int i =0;
            while(i<cycle && !pq.empty()){
                int count = pq.top();
                pq.pop();
                count--;
                if(count>0){
                    temp.push_back(count);
                }
                time++;
                i++;
            }
            for(int task : temp){
                pq.push(task);
            }
            if(pq.empty()) break;
            time+=cycle-i;

        }
        return time;
    }
};
