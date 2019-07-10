#include "iostream"
using namespace std;

struct process {
  int * allocated;
  int * max;
  int * needed;
  int done_flag;
};

int main() {

  int total_processes, total_resources;
  int * available_resources;

  cout << "Enter Total Number of Processes : ";
  cin >> total_processes;

  cout << "Enter Total Number of Resources : ";
  cin >> total_resources;

  process * p_array = new process[total_processes];

  cout << "\nEnter Allocation Matrix\n";
  for (int i = 0; i < total_processes; ++i) {
    cout << " P" << i << " : ";
    p_array[i].allocated = new int(total_resources);
    for (int j = 0; j < total_resources; ++j) {
      cin >> p_array[i].allocated[j];
    }
  }

  cout << "\nEnter Max Matrix\n";
  for (int i = 0; i < total_processes; ++i) {
    cout << " P" << i << " : ";
    p_array[i].needed = new int(total_resources);
    p_array[i].max = new int(total_resources);
    for (int j = 0; j < total_resources; ++j) {
      cin >> p_array[i].max[j];
      p_array[i].needed[j] = p_array[i].max[j] - p_array[i].allocated[j];
    }
  }

  cout << "Enter Available Resources : ";
  available_resources = new int(total_resources);
  for (int j = 0; j < total_resources; ++j) {
    cin >> available_resources[j];
  }

}