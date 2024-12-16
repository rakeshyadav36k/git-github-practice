/**
 * There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, 
 * where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. 
You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. 
The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.
 */

class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<P> pq; 

        for(int i = 0; i < n; i++){
            double current_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_PR - current_PR;
            pq.push({delta, i});
        }

        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++; // increment total passing student in the class
            classes[idx][1]++; // increment total student in the class

            double current_PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = new_PR - current_PR;
            pq.push({delta, idx});            
        }

        double result = 0.0;
        for(int i = 0; i < n; i++){
            result += (double)classes[i][0]/classes[i][1];
        }

        return result/n;
    }
};