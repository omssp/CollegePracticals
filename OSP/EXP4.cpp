#include "iostream"
using namespace std;
struct process {
    int bt;
    int at;
    int wt;
    int tat;
    process() {
        wt = 0;
    }
};
int minimumProcess(process *p, int currT, int size_of_process);
int main() {
    int n;
    int total_bt = 0;
    cout << "Enter the total number of process : ";
    cin >> n;
    process *p_array = new process[n];
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Enter the Arrival Time of P" << i << " : ";
        cin >> p_array[i].at;
        cout << "Enter the  Burst Time of  P" << i << " : ";
        cin >> p_array[i].bt;
        p_array[i].tat = p_array[i].bt;
        total_bt += p_array[i].bt;
    }
    for (int i = 0; i < total_bt; ++i) {
        int min_proc_no = minimumProcess(p_array, i, n);
        p_array[min_proc_no].bt--;
        for (int j = 0; j < n; ++j) {
            if ( p_array[j].at <= i && p_array[j].bt > 0) {
                if ( j != min_proc_no ) {
                    p_array[j].wt++;
                }
            }
        }
    }

    int total_wt = 0;
    int total_tat = 0;
    cout << "\nProcess\t\tAT\tBT\tWT\tTAT";
    for (int i = 0; i < n; ++i) {
        cout << "\nP" << i << "\t\t"
             << p_array[i].at << "\t"
             << p_array[i].tat << "\t";
        p_array[i].tat += p_array[i].wt;
        cout << p_array[i].wt << "\t"
             << p_array[i].tat;
        total_wt += p_array[i].wt;
        total_tat += p_array[i].tat;
    }

    cout << "\n\nAverage   Watitng  Time  is : " << (float)total_wt / n << endl;
    cout << "Average Turn Around Time is : " << (float)total_tat / n << endl;
}
int minimumProcess(process *p, int currT, int size_of_process) {
    int *array_of_arrived = new int(size_of_process);
    int size_of_arrived = 0;
    for (int i = 0; i < size_of_process; ++i) {
        if (p[i].at <= currT) {
            array_of_arrived[size_of_arrived++] = i;
        }
    }
    int smallest_bt = 32565;
    int smallest_bt_process_no = 0;
    for (int i = 0; i < size_of_arrived; ++i) {
        if (p[array_of_arrived[i]].bt < smallest_bt && p[array_of_arrived[i]].bt > 0) {
            smallest_bt = p[array_of_arrived[i]].bt;
            smallest_bt_process_no = array_of_arrived[i];
        }
    }
    return smallest_bt_process_no;
}