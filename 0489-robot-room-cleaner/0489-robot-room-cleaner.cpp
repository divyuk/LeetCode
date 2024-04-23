/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    // going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
    vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    unordered_set<string> visited;
    //Robot robot;

    void goBack(Robot &robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void backtrack(Robot &robot, int row, int col, int d) {
        visited.insert(to_string(row) + "," + to_string(col));
        robot.clean();
        // going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
        for (int i = 0; i < 4; ++i) {
            int newD = (d + i) % 4;
            int newRow = row + directions[newD][0];
            int newCol = col + directions[newD][1];
            string newPos = to_string(newRow) + "," + to_string(newCol);

            if (visited.find(newPos) == visited.end() && robot.move()) {
                backtrack(robot, newRow, newCol, newD);
                goBack(robot);
            }
            // turn the robot following chosen direction : clockwise
            robot.turnRight();
        }
    }

public:
    void cleanRoom(Robot& robot) {
        backtrack(robot,0, 0, 0);
    }
};
