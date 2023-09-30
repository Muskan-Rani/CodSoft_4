#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string name;
    bool completed;

    Task(const string& taskName) : name(taskName), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskName) {
        tasks.push_back(Task(taskName));
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].name << endl;
        }
    }

    void markAsCompleted(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex - 1);
            cout << "Task removed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    TodoList todoList;
    char choice;

    do {
        cout << "\nTo-Do List Manager:" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Consume the newline character

        switch (choice) {
            case '1': {
                string taskName;
                cout << "Enter task name: ";
                getline(cin, taskName);
                todoList.addTask(taskName);
                break;
            }
            case '2':
                todoList.viewTasks();
                break;
            case '3': {
                size_t taskIndex;
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                todoList.markAsCompleted(taskIndex);
                break;
            }
            case '4': {
                size_t taskIndex;
                cout << "Enter task index to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case '5':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}

