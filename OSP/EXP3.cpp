#include "iostream"

using namespace std;

int main() {
	int n;

	cout << "Enter the number of Processes : ";
	cin >> n;

	int *bt_array = new int(n);

	int *wt_array = new int(n);
	int *tat_array = new int(n);

	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "Enter the Burst Time for P" << (i+1) << " : ";
		cin >> bt_array[i];

		if ( i == 0 ) {
			wt_array[i] = 0;
			tat_array[i] = bt_array[i];
		} else {
			wt_array[i] = bt_array[i-1] + wt_array[i-1];
			tat_array[i] = wt_array[i] + bt_array[i];
		}

	}
	cout << endl;


	int total_wt = 0;
	int total_tat = 0;

	cout << "The Wait times are :- \n";

	for (int i = 0; i < n; ++i) {
		cout << "P" << (i+1) << " : " << wt_array[i] << endl;
		total_wt += wt_array[i];
	}

	cout << "The Average Wait time is : " << (float)total_wt / n  << endl;


	cout << "\nThe Turn Around times are :- \n";

	for (int i = 0; i < n; ++i) {
		cout << "P" << (i+1) << " : " << tat_array[i] << endl;
		total_tat += tat_array[i];
	}

	cout << "The Average Turn Around time is : " << (float)total_tat / n  << endl;


	return 0;
}
