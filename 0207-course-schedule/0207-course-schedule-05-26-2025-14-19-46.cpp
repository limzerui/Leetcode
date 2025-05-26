class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(const auto& edge: prerequisites){
            int course = edge[0];
            int prereq  = edge[1];
            graph[prereq].push_back(course);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> inStack(numCourses, false);
    for(int i = 0; i<numCourses; i++){
        if(!visited[i] && !dfs(visited, inStack, graph, i)){
            return false;
        }
    }
    return true;
    
    }

    bool dfs(vector<bool>& visited, vector<bool>& inStack, vector<vector<int>>& graph, int node){
        if(inStack[node]) return false;
        if(visited[node]) return true;

        inStack[node] = true;
        visited[node] = true;

        for(int neighbour: graph[node]){
            if(!dfs(visited, inStack, graph, neighbour))
            return false;
        }
        inStack[node] = false;
        return true;

    }
};