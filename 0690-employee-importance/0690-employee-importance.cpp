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
        
        // Initialize the total importance
        int totalImportance = 0;
        
        // Perform BFS starting from the given employee ID
        queue<int> q;
        q.push(id);
        
        while (!q.empty()) {
            int currId = q.front();
            q.pop();
            
            // Add the importance of the current employee
            totalImportance += employeeMap[currId]->importance;
            
            // Add the subordinates of the current employee to the queue
            for (int subId : employeeMap[currId]->subordinates) {
                q.push(subId);
            }
        }
        
        return totalImportance;
    }
};