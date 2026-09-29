class DisJoint {
public:
    int n;
    vector<int> par;
    vector<int> rank;

    DisJoint(int n){
        this->n = n;

        for(int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        } else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisJoint ds(20002);

        for(int i=0; i<n; i++){
            ds.unionByRank(stones[i][0], stones[i][1] + 10001);
        }

        unordered_set<int> roots;

        for(int i=0; i<n; i++){
            roots.insert(ds.find(stones[i][0]));
        }

        return n - roots.size();
    }
};