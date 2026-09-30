class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int index = 0;
        queue<int> q;
        for(int i =0;i<tickets.size();i++){
            q.push(i);   
        }
        int t =0;
        while(!q.empty()){
            int aadmi = q.front();
            q.pop();
            tickets[aadmi]--;
            t++;

            if(aadmi == k && tickets[aadmi] ==0){
                return t;
            }
            if(tickets[aadmi] > 0){
                q.push(aadmi);
            }
        }
        return t;
    }
};