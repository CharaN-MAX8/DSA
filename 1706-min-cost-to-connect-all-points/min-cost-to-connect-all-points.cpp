class Edge {
public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Solution {
public:
    vector<int> par;
    vector<int> rank;

    int find(int x){
        if(par[x] == x){
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionByRank(int u, int v){
        int parU = find(u);
        int parV = find(v);

        if(rank[parU] == rank[parV]){
            par[parV] = parU;
            rank[parU]++;
        } else if(rank[parU] > rank[parV]){
            par[parV] = parU;
        } else {
            par[parU] = parV;
        }
     }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<Edge> edge;

        for(int i=0; i<V; i++){
            par.push_back(i);
            rank.push_back(0);
        }

        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){
                int wt = abs(points[i][0] - points[j][0]) + 
                         abs(points[i][1] - points[j][1]);
                edge.push_back(Edge(i, j, wt));
            }
        }

        sort(edge.begin(), edge.end(), [](const Edge &a, const Edge &b){
            return a.wt < b.wt;
        });

        int minCost = 0;
        int count = 0;

        for(int i=0; i<edge.size() && count < V-1; i++){
            Edge e = edge[i];
            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV){
                unionByRank(parU, parV);
                minCost += e.wt;
                count++;
            }
        }
        return minCost;
    }
};