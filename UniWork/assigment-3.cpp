#include <iostream>
using namespace std;
const int siz = 500;
class Todo
{
private:
    string highPriority[siz]; // array fo
    string mediumPriority[siz];
    string lowPriority[siz];
    string routinePriority[siz];

    int highIndex;
    int mediumIndex;
    int lowIndex;
    int routineIndex;

public:
    Todo()
    {
        highIndex = 0;
        mediumIndex = 0;
        lowIndex = 0;
        routineIndex = 0;
    }

    void addTask(string task, string priority)
    {
        if (priority == "High" && highIndex < siz)
        {
            highPriority[highIndex++] = task;
        }
        else if (priority == "Medium" && mediumIndex < siz)
        {
            mediumPriority[mediumIndex++] = task;
        }
        else if (priority == "Low" && lowIndex < siz)
        {
            lowPriority[lowIndex++] = task;
        }
        else if (priority == "Routine" && routineIndex < siz)
        {
            routinePriority[routineIndex++] = task;
        }
        else
        {
            cout << "Task list is overloaded" << endl;
        }
    }

    void completeTask()
    {
        if (highIndex > 0)
        {
            cout << "Completed High Priority Task: " << highPriority[0] << endl;
            for (int i = 0; i < highIndex - 1; i++)
            {
                highPriority[i] = highPriority[i + 1];
            }
            --highIndex;
        }
        else if (mediumIndex > 0)
        {
            cout << "Completed Medium Priority Task: " << mediumPriority[0] << endl;
            for (int i = 0; i < mediumIndex - 1; ++i)
            {
                mediumPriority[i] = mediumPriority[i + 1];
            }
            --mediumIndex;
        }
        else if (lowIndex > 0)
        {
            cout << "Completed Low Priority Task: " << lowPriority[0] << endl;
            for (int i = 0; i < lowIndex - 1; ++i)
            {
                lowPriority[i] = lowPriority[i + 1];
            }
            --lowIndex;
        }
        else if (routineIndex > 0)
        {
            cout << "Completed Routine Task: " << routinePriority[0] << endl;
            for (int i = 0; i < routineIndex - 1; ++i)
            {
                routinePriority[i] = routinePriority[i + 1];
            }
            --routineIndex;
        }
        else
        {
            cout << "No tasks to complete." << endl;
        }
    }
};

int main()
{
    Todo taskManager;

    // Example: Adding tasks with different priorities
    taskManager.addTask("Task 1", "Medium");
    taskManager.addTask("Task 2", "High");
    taskManager.addTask("Task 3", "Routine");
    taskManager.addTask("Task 4", "Low");

    // Completing tasks in the specified order
    taskManager.completeTask();
    taskManager.completeTask();
    taskManager.completeTask();
    taskManager.completeTask();
    taskManager.completeTask(); // No tasks left

    return 0;
}
