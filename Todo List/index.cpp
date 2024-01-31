#include <iostream>
#include <vector>

using namespace std;

struct TodoItem
{
    string task;
    bool completed;

    TodoItem(const string &t) : task(t), completed(false) {}
};

class TodoList
{
private:
    vector<TodoItem> items;

public:
    void addItem(const string &task)
    {
        TodoItem newItem(task);
        items.push_back(newItem);
        cout << "Task added: " << task << endl;
    }

    void displayList() const
    {
        cout << "ToDo List:" << endl;
        for (size_t i = 0; i < items.size(); ++i)
        {
            cout << "[" << (i + 1) << "] ";
            if (items[i].completed)
            {
                cout << "[X] ";
            }
            else
            {
                cout << "[ ] ";
            }
            cout << items[i].task << endl;
        }
    }

    void markComplete(size_t index)
    {
        if (index > 0 && index <= items.size())
        {
            items[index - 1].completed = true;
            cout << "Task marked as complete: " << items[index - 1].task << endl;
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }

    void removeItem(size_t index)
    {
        if (index > 0 && index <= items.size())
        {
            cout << "Task removed: " << items[index - 1].task << endl;
            items.erase(items.begin() + index - 1);
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }
};

int main()
{
    TodoList todoList;
    char choice;

    do
    {
        cout << "\nToDo List Application" << endl;
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Mark Task as Complete\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            string task;
            cout << "Enter task: ";
            cin.ignore(); // Clear the buffer
            getline(cin, task);
            todoList.addItem(task);
            break;
        }
        case '2':
            todoList.displayList();
            break;
        case '3':
        {
            size_t index;
            cout << "Enter the task index to mark as complete: ";
            cin >> index;
            todoList.markComplete(index);
            break;
        }
        case '4':
        {
            size_t index;
            cout << "Enter the task index to remove: ";
            cin >> index;
            todoList.removeItem(index);
            break;
        }
        case '5':
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != '5');

    return 0;
}
