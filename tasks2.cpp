/*
In this program we can:
Add Projects: Create projects to organize our tasks.
View Projects: See a list of available projects.
Manage Tasks: Add tasks, view tasks, mark tasks as completed within a specific project.
*/


#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;
    std::string dueDate;

    Task(const std::string& desc, const std::string& date) : description(desc), completed(false), dueDate(date) {}
};

struct Project {
    std::string name;
    std::vector<Task> tasks;

    Project(const std::string& pname) : name(pname) {}
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
                    addProject();
                    break;
                case 2:
                    viewProjects();
                    break;
                case 3:
                    manageTasks();
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
    std::vector<Project> projects;

    void displayMenu() {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Project\n";
        std::cout << "2. View Projects\n";
        std::cout << "3. Manage Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
    }

    void addProject() {
        std::cin.ignore();  // Clear the input buffer
        std::cout << "Enter project name: ";
        std::string projectName;
        std::getline(std::cin, projectName);

        projects.emplace_back(projectName);
        std::cout << "Project added successfully.\n";
    }

    void viewProjects() {
        if (projects.empty()) {
            std::cout << "No projects available.\n";
        } else {
            std::cout << "\nProject List:\n";
            for (size_t i = 0; i < projects.size(); ++i) {
                std::cout << i + 1 << ". " << projects[i].name << "\n";
            }
        }
    }

    void manageTasks() {
        viewProjects();
        std::cout << "Enter the project number to manage tasks (0 to cancel): ";
        int projectIndex;
        std::cin >> projectIndex;

        if (projectIndex < 1 || projectIndex > static_cast<int>(projects.size())) {
            std::cout << "Invalid project number. Returning to the main menu.\n";
            return;
        }

        Project& selectedProject = projects[projectIndex - 1];

        while (true) {
            displayTaskMenu(selectedProject);
            int taskChoice;
            std::cin >> taskChoice;

            switch (taskChoice) {
                case 1:
                    addTask(selectedProject);
                    break;
                case 2:
                    viewTasks(selectedProject);
                    break;
                case 3:
                    markTaskAsCompleted(selectedProject);
                    break;
                case 4:
                    return;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
    }

    void displayTaskMenu(const Project& project) const {
        std::cout << "\nTask Management Menu for Project '" << project.name << "':\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Back to Projects\n";
        std::cout << "Enter your choice: ";
    }

    void addTask(Project& project) {
        std::cin.ignore();  // Clear the input buffer

        std::cout << "Enter task description: ";
        std::string description;
        std::getline(std::cin, description);

        std::cout << "Enter due date (e.g., '2023-12-31'): ";
        std::string dueDate;
        std::getline(std::cin, dueDate);

        project.tasks.emplace_back(description, dueDate);
        std::cout << "Task added successfully.\n";
    }

    void viewTasks(const Project& project) const {
        if (project.tasks.empty()) {
            std::cout << "No tasks available for project '" << project.name << "'.\n";
        } else {
            std::cout << "\nTask List for Project '" << project.name << "':\n";
            for (size_t i = 0; i < project.tasks.size(); ++i) {
                const Task& task = project.tasks[i];
                std::cout << i + 1 << ". " << std::setw(30) << std::left << task.description;
                std::cout << " Due: " << task.dueDate;
                if (task.completed) {
                    std::cout << " [Completed]";
                }
                std::cout << "\n";
            }
        }
    }

    void markTaskAsCompleted(Project& project) {
        viewTasks(project);
        std::cout << "Enter the task number to mark as completed (0 to cancel): ";
        int taskIndex;
        std::cin >> taskIndex;

        if (taskIndex < 1 || taskIndex > static_cast<int>(project.tasks.size())) {
            std::cout << "Invalid task number. Returning to task management menu.\n";
            return;
        }

        Task& selectedTask = project.tasks[taskIndex - 1];
        selectedTask.completed = true;
        std::cout << "Task marked as completed.\n";
    }
};

int main() {
    TaskManager taskManager;
    taskManager.run();

    return 0;
}
