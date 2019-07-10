#include "iostream"
using namespace std;
struct process {
  int* allocated;
  int* maximum;
  int* needed;
  bool finished;
  process() { finished = false; }
};
int total_processes, total_resources;
int *available, *work;
process* p_array;

int main() {
  cout << "Enter the total number of process\t: ";
  cin >> total_processes;

  cout << "Enter the total number of resources\t: ";
  cin >> total_resources;

  p_array = new process[total_processes];

  cout << endl << "Enter the Allocation Matrix" << endl << endl;
  for (int i = 0; i < total_processes; ++i) {
    cout << " P" << i << " : ";
    p_array[i].allocated = new int(total_resources);
    for (int j = 0; j < total_resources; ++j) {
      cin >> p_array[i].allocated[j];
    }
  }
  cout << endl << "Enter the MAX Matrix" << endl << endl;
  for (int i = 0; i < total_processes; ++i) {
    cout << " P" << i << " : ";
    p_array[i].maximum = new int(total_resources);
    p_array[i].needed = new int(total_resources);
    for (int j = 0; j < total_resources; ++j) {
      cin >> p_array[i].maximum[j];
      p_array[i].needed[j] = p_array[i].maximum[j] - p_array[i].allocated[j];
    }
  }

  cout << endl << "\nEnter the Available Resources : ";
  available = new int(total_resources);
  for (int j = 0; j < total_resources; ++j) {
    cin >> available[j];
  }

  system("cls");

  cout << "\tAllocation\tMAX\t\tAvailable" << endl;
  cout << "\t";
  for (int i = 0; i < total_resources; ++i) {
    cout << (char)(i + 65) << " ";
  }
  cout << "\t\t";
  for (int i = 0; i < total_resources; ++i) {
    cout << (char)(i + 65) << " ";
  }
  cout << "\t\t";
  for (int i = 0; i < total_resources; ++i) {
    cout << (char)(i + 65) << " ";
  }
  for (int i = 0; i < total_processes; ++i) {
    cout << "\nP" << i << "\t";
    for (int j = 0; j < total_resources; ++j) {
      cout << p_array[i].allocated[j] << " ";
    }
    cout << "\t\t";
    for (int j = 0; j < total_resources; ++j) {
      cout << p_array[i].maximum[j] << " ";
    }
    cout << "\t\t";
    if (i == 0) {
      for (int j = 0; j < total_resources; ++j) {
        cout << available[j] << " ";
      }
    }
  }

  cout << endl << endl;

  cout << "\tAllocation\tNeed\t\tAvailable" << endl;
  cout << "\t";
  for (int i = 0; i < total_resources; ++i) {
    cout << (char)(i + 65) << " ";
  }
  cout << "\t\t";
  for (int i = 0; i < total_resources; ++i) {
    cout << (char)(i + 65) << " ";
  }
  cout << "\t\t";
  for (int i = 0; i < total_resources; ++i) {
    cout << (char)(i + 65) << " ";
  }
  for (int i = 0; i < total_processes; ++i) {
    cout << "\nP" << i << "\t";
    for (int j = 0; j < total_resources; ++j) {
      cout << p_array[i].allocated[j] << " ";
    }
    cout << "\t\t";
    for (int j = 0; j < total_resources; ++j) {
      cout << p_array[i].needed[j] << " ";
    }
    cout << "\t\t";
    if (i == 0) {
      for (int j = 0; j < total_resources; ++j) {
        cout << available[j] << " ";
      }
    }
  }

  // work = new int(total_resources);
  // work = available;

  int toExec;
  cout << endl << endl;
step2:

  for (int i = 0; i < total_processes; ++i) {
    if (p_array[i].finished == false) {
      bool exec_flag = true;
      for (int j = 0; j < total_resources; ++j) {
        if (p_array[i].needed[j] > available[j]) {
          exec_flag = false;
          break;
        }
      }

      if (exec_flag == true) {
        toExec = i;
        cout << "P" << i << ", ";
        goto step3;
        /*for (int j = 0; j < total_resources; ++j) {
                        available[j] += p_array[i].allocated[j];
                }
                p_array[i].finished = true;*/
      } else {
        cout << "yaha wala else";
      }
    }
  }

  goto step4;

step3:
  for (int j = 0; j < total_resources; ++j) {
    available[j] += p_array[toExec].allocated[j];
  }
  p_array[toExec].finished = true;
  goto step2;

step4:
  cout << "\b\b \nThe above is the required safe sequence\n the new available "
          "is : ";
  for (int j = 0; j < total_resources; ++j) {
    cout << " " << available[j];
  }
}