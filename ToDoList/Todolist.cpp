#include <iostream>
#include <vector>
#include <string>

class ToDoList {
private:
    std::vector<std::string> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back(task);
        std::cout << "Task added: " << task << std::endl;
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            std::cout << "Task removed: " << tasks[index] << std::endl;
            tasks.erase(tasks.begin() + index);
        } else {
            std::cout << "Invalid task index" << std::endl;
        }
    }

    void displayTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "To-Do List:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i] << std::endl;
            }
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    std::string task;
    int index;

    while (true) {
        std::cout << "\n1. Add Task\n2. Remove Task\n3. Display Tasks\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task: ";
                std::cin.ignore();
                std::getline(std::cin, task);
                todo.addTask(task);
                break;
            case 2:
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                todo.removeTask(index - 1);
                break;
            case 3:
                todo.displayTasks();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}