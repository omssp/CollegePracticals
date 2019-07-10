#include "iostream"
using namespace std;
struct process {
  int bt;
  int wt;
  int tat;
  process() {
    wt = 0;
  }
};
int main() {
  int n, time_slice;
  int total_bt = 0;
  cout << "Enter the total number of process : ";
  cin >> n;
  process * p_array = new process[n];
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << "Enter the Burst Time of P" << i << " : ";
    cin >> p_array[i].bt;
    p_array[i].wt = p_array[i].bt;
    total_bt += p_array[i].bt;
  }

  cout << endl << "Enter the Time Slice : ";
  cin >> time_slice;

  for (int i = 0; i < total_bt;) {
    for (int j = 0; j < n; ++j) {
      if (p_array[j].bt != 0) {
        if (p_array[j].bt > time_slice) {
          p_array[j].bt -= time_slice;
          i += time_slice;
        } else {
          p_array[j].tat = i + p_array[j].bt;
          i += p_array[j].bt;
          p_array[j].bt = 0;
        }
      }
    }
  }
  int total_wt = 0;
  int total_tat = 0;
  cout << "\nProcess\t\tBT\tWT\tTAT";
  for (int i = 0; i < n; ++i) {
    p_array[i].bt = p_array[i].wt;
    p_array[i].wt = p_array[i].tat - p_array[i].bt;

    cout << "\n P" << i << "\t\t" <<
      p_array[i].bt << "\t" <<
      p_array[i].wt << "\t" <<
      p_array[i].tat;

    total_wt += p_array[i].wt;
    total_tat += p_array[i].tat;
  }

  cout << "\n\nAverage Watitng Time is : " << (float) total_wt / n << endl;
  cout << "Average Turn Around Time is : " << (float) total_tat / n << endl;
}