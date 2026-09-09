bool enqueSort(vector<int>& task1, vector<int>& task2) {
    return ((task1[0] == task2[0]) ? ((task1[1] == task2[1]) ? (task1[2] < task2[2]) : (task1[1] < task2[1])) : (task1[0] < task2[0]));
}

struct taskPriority {
    bool operator()(vector<int>& a, vector<int>& b) {
        return ((a[1] == b[1]) ? (b[2] < a[2]) : (b[1] < a[1]));
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // So we have to simulate the behaviour of a CPU whose working is already given to us.
        // So the CPU works in this way that, um, if no jobs are encued and all the previously encued jobs have finished, then CPU rests idle. At the time, some job is in queued, or multiple jobs are in queued. It chooses the one with minimum processing time and it finishes it, and this way we have to figure out the completion sequence of tasks, given when they are uncued and what is their processing?
        // Just like a timed simulation, we can maybe order the tasks according to their enqueue time, so that the task which has NQ time least is at the left of the array, and the tasks whose enqueue time is greater is at the end of the array, right?
        // This way, we can keep a queue, which contains, which contains jobs that are already enqueued to be processed at the CPU, and we keep adding tasks to this queue as the time passes.
        // And from this queue, we keep choosing the smallest processing time task, and keep adding tasks as the time progresses, until all the jobs are done, and this way, we update the sequence in which we complete the tasks.

        for(int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end(), enqueSort);

        priority_queue<vector<int>, vector<vector<int>>, taskPriority> cpuQueue;

        vector<int> ans;

        unsigned long long int currTime = 0;
        int i = 0;

        while((i < tasks.size()) || (!cpuQueue.empty())) {
            if(cpuQueue.empty()) {
                cpuQueue.push(tasks[i]);
                currTime = tasks[i][0];
                i++;
            }

            vector<int> taskToBeExecuted = cpuQueue.top();
            cpuQueue.pop();
            ans.push_back(taskToBeExecuted[2]);

            currTime += taskToBeExecuted[1];

            while((i < tasks.size()) && (tasks[i][0] <= currTime)) {
                cpuQueue.push(tasks[i]);
                i++;
            }
        }

        return ans;
    }
};