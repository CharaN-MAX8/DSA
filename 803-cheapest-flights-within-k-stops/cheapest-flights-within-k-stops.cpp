class Solution {
public:
    class Info{
    public:
        int u;
        int cost;
        int stop;

        Info(int u, int cost, int stop){
            this->u = u;
            this->cost = cost;
            this->stop = stop;
        }
    };

    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Info> q;
        q.push(Info(src, 0, -1));
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            Info curr = q.front();
            q.pop();

            for(int i=0; i<flights.size(); i++){
                if(flights[i][0] == curr.u){
                    int v = flights[i][1];
                    int wt = flights[i][2];

                    if(dist[v] > curr.cost + wt && curr.stop+1 <= k){
                        dist[v] = curr.cost + wt;
                        q.push(Info(v, dist[v], curr.stop+1));
                    }
                }
            }
        }

        if(dist[dst] == INT_MAX){
            return -1;
        }

        return dist[dst];
    }
};