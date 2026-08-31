class Solution {
public:
    void calIndegree(vector<int> &inDeg, vector<vector<int>> &graph){
        for(int u=0; u<inDeg.size(); u++){
            for(int v : graph[u]) inDeg[v]++;
        }
    }

    bool topoSort(int V, vector<vector<int>> &graph){
        vector<int> inDeg(V, 0);
        calIndegree(inDeg, graph);
        queue<int> q;

        for(int i=0; i<V; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int v : graph[curr]){
                inDeg[v]--;
                if(inDeg[v] == 0) q.push(v);
            }
        }

        for(int i=0; i<V; i++){
            if(inDeg[i] != 0){
                return true;
            }
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> graph(V);

        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        return (!topoSort(V, graph));
        
    }
};