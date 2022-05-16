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
    int f(vector<Employee*> employees, int id,unordered_map<int,int> &mp){
        int imp=0;
        for(int i=0;i<employees.size();i++){
            int x=employees[i]->id;
            int y=0;
            if(x==id){
            y=employees[i]->importance;
            vector<int> v=employees[i]->subordinates;
            mp[id]++;
            for(auto it:v){
                if(mp.find(it)==mp.end()){
                imp+=f(employees,it,mp);
                }
            }
            }
            imp+=y;
        }
            return imp;
    }
    int getImportance(vector<Employee*> employees, int id) {
        //unordered_map<int,pair<int,vector<int>>> mp;
        unordered_map<int,int> mp;
        int imp=0;
        for(int i=0;i<employees.size();i++){
            int x=employees[i]->id;
            int y=0;
            if(x==id){
            y=employees[i]->importance;
            vector<int> v=employees[i]->subordinates;
            mp[id]++;
            for(auto it:v){
                if(mp.find(it)==mp.end())
                imp+=f(employees,it,mp);
            }
            }
           // mp[employees[i].id]->first=employees[i]->importance;
          //  mp[employees[i]->id]->second=employees[i]->subordinates;
            imp=imp+y;
        }
        return imp;
    }
};