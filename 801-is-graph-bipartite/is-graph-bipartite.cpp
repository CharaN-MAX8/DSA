class Solution {
public:
    bool helper(int src ,vector<int>& color, vector<vector<int>>& graph){
        queue<int> q;
        color[src] = 0;
        q.push(src);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int v : graph[curr]){
                if(color[v] == -1){
                    color[v] = !color[curr];
                    q.push(v);
                } else {
                    if(color[v] == color[curr]) return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(!helper(i, color, graph)) return false;
            }
        }
        return true;
    }
};