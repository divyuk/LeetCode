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
    int getImportance(vector<Employee*> employees, int id) {
        // Create a map to quickly lookup employees by their ID
        unordered_map<int, Employee*> employeeMap;
        for (auto employee : employees) {
            employeeMap[employee->id] = employee;
        }
        
        // Start DFS from the given employee ID
        return dfs(employeeMap, id);
    }
    
private:
    int dfs(unordered_map<int, Employee*>& employeeMap, int id) {
        // Base case: if the employee is not found, return 0
        if (employeeMap.find(id) == employeeMap.end()) {
            return 0;
        }
        
        // Get the employee object
        Employee* employee = employeeMap[id];
        int totalImportance = employee->importance;
        
        // Traverse through the direct subordinates and recursively calculate their importance
        for (int subordinateId : employee->subordinates) {
            totalImportance += dfs(employeeMap, subordinateId);
        }
        
        return totalImportance;
    }
};