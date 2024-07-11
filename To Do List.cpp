#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
  string name;
  bool completed;
};

vector<Task> todoList;

void addTask() {
  string taskName;
  cout << "Alright, let's add a new task. What should I call it? ";
  getline(cin, taskName);
  todoList.push_back({taskName, false});
  cout << "Got it, the task has been added!" << endl;
}

void viewTasks() {
  cout << "Here's the current to-do list:" << endl;
  for (int i = 0; i < todoList.size(); i++) {
      cout << "[" << (todoList[i].completed ? "X" : " ") << "] " << todoList[i].name << endl;
  }
}

void markTaskAsCompleted() {
  int taskIndex;
  cout << "Okay, which task do you want to mark as completed? Enter the index: ";
  cin >> taskIndex;
  cin.ignore(); // Ignore the newline character
  if (taskIndex >= 0 && taskIndex < todoList.size()) {
      todoList[taskIndex].completed = true;
      cout << "Great, the task has been marked as completed!" << endl;
  } else {
      cout << "Hmm, that's not a valid task index. Let's try that again." << endl;
  }
}

void removeTask() {
  int taskIndex;
  cout << "Which task do you want to remove? Enter the index: ";
  cin >> taskIndex;
  cin.ignore(); // Ignore the newline character
  if (taskIndex >= 0 && taskIndex < todoList.size()) {
      todoList.erase(todoList.begin() + taskIndex);
      cout << "Okay, the task has been removed." << endl;
  } else {
      cout << "Hmm, that's not a valid task index. Let's try that again." << endl;
  }
}

int main() {
  int choice;
  while (true) {
      cout << "\nWelcome to the To-Do List Manager!" << endl;
      cout << "What would you like to do?" << endl;
      cout << "1. Add a new task" << endl;
      cout << "2. View the current tasks" << endl;
      cout << "3. Mark a task as completed" << endl;
      cout << "4. Remove a task" << endl;
      cout << "5. Exit the program" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      cin.ignore(); // Ignore the newline character

      switch (choice) {
          case 1:
              addTask();
              break;
          case 2:
              viewTasks();
              break;
          case 3:
              markTaskAsCompleted();
              break;
          case 4:
              removeTask();
              break;
          case 5:
              cout << "Alright, see you next time!" << endl;
              return 0;
          default:
              cout << "Hmm, that's not a valid choice. Let's try that again." << endl;
              break;
      }
  }
}