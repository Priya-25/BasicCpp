/*
This is a simple Task Management program, in this program, the user can :
1. Add a Task: Enter a description for the task, and it is added to the list.
2. Mark a Task as Completed: View the list of tasks, choose a task by index, and mark it as completed.
3. View Tasks: See the list of tasks with their descriptions and completion status.
4. Exit: Quit the task manager.
*/


#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;
};

class TaskManager {
public:
    void run() {
        while (true) {
            displayMenu();
            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    addTask();
                    break;
                case 2:
                    markTaskAsCompleted();
                    break;
                case 3:
                    viewTasks();
                    break;
                case 4:
                    std::cout << "Exiting the task manager. Goodbye!\n";
                    return;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
    }

private:
    std::vector<Task> tasks;

    void displayMenu() {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. View Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
    }

    void addTask() {
        Task newTask;
        std::cin.ignore(); // Clear the input buffer
        std::cout << "Enter task description: ";
        std::getline(std::cin, newTask.description);
        newTask.completed = false;
        tasks.push_back(newTask);
        std::cout << "Task added successfully.\n";
    }

    void markTaskAsCompleted() {
        viewTasks();
        std::cout << "Enter the index of the task to mark as completed: ";
        int index;
        std::cin >> index;

        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid index. No task marked as completed.\n";
        }
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
        } else {
            std::cout << "\nTask List:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i << ". ";
                if (tasks[i].completed) {
                    std::cout << "[Completed] ";
                }
                std::cout << tasks[i].description << "\n";
            }
        }
    }
};

int main() {
    TaskManager taskManager;
    taskManager.run();

    return 0;
}
