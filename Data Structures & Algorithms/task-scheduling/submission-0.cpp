struct comp {
    bool operator()(pair<int, int>& task1, pair<int, int>& task2) {
        return task2.first > task1.first;
    }
};

class Solution {

    bool tasksCompleted(vector<int>& tasksLeft) {
        for(int tasks: tasksLeft) {
            if(tasks > 0) {
                return false;
            }
        }

        return true;
    }

    void fillLegibleTasks(
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp>& legibleTasks,
        vector<int>& tasksLeft, vector<int>& lastExecuted, int cpuCycle, int n
    ) {
        for(int i = 0; i < 26; i++) {
            if(((cpuCycle - lastExecuted[i] - 1) == n) && (tasksLeft[i] > 0)) {
                legibleTasks.push({tasksLeft[i], i});
            }
        }
    }

public:
    int leastInterval(vector<char>& tasks, int n) {
        // We have a total of 26 tasks that we can assign to the CPU, right?
        // How many CPUs do we have?

        // Let's say we have a list tasks ["A", "A"] and n = 2 then the only way execute tasks on this CPU would be as : {A -> idle -> idle -> A}
        // So, as far as I understand the problem, we keep on incrementing the CPU cycles and at each cycle we decide if this task can be executed at this point or not depending upon the last execution time of that task. And if no task can be executed at this point then we leave that CPU cycle as idle.
        // At any point there might be multiple tasks which can be delegated to the CPU at a point how do we select the appropriate task at that point in order for the CPU to take minimum time to execute all the tasks.
        // One thing I can think of is to keep the count of the number of tasks left for each category and execute the task that has most number of tasks left at a point.

        vector<int> tasksLeft(26);
        vector<int> lastExecuted(26, (-1 * n));

        for(char task: tasks) {
            tasksLeft[task - 'A']++;
        }

        int cpuCycle = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> legibleTasks;

        while(!tasksCompleted(tasksLeft)) {
            cpuCycle++;

            fillLegibleTasks(legibleTasks, tasksLeft, lastExecuted, cpuCycle, n);

            if(!legibleTasks.empty()) {
                pair<int, int> taskDetail = legibleTasks.top();
                legibleTasks.pop();

                tasksLeft[taskDetail.second]--;
                lastExecuted[taskDetail.second] = cpuCycle;
            }
        }

        return cpuCycle;
    }
};