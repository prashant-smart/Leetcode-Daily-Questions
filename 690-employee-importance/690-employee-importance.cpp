/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int findImportance(unordered_map<int,vector<int>>& adjLis,unordered_map<int,int>& imp,unordered_map<int,int> &visited,int emp){
        int value=imp[emp];
        visited[emp]++;
        for(auto ngh:adjLis[emp]){
            if(!visited[ngh]){
                value+=findImportance(adjLis,imp,visited,ngh);
            }
        }
        return value;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,vector<int>> adjLis;
        unordered_map<int,int> imp;
        for(auto emp:employees){
            imp[emp->id]=emp->importance;
            for(auto ngh:emp->subordinates){
                adjLis[emp->id].push_back(ngh);
            }
        }
        
        unordered_map<int,int> visited;
        return findImportance(adjLis,imp,visited,id);
        
    }
};