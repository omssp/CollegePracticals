#include "iostream"
using namespace std;


int main() {

	int total_pages, total_frames;

	cout << "Enter the total number of pages  : ";
	cin >> total_pages;

	cout << "Enter the total number of frames : ";
	cin >> total_frames;

	int *string = new int(total_pages);
	int *frame_array = new int(total_frames);
	for (int j = 0; j < total_frames; ++j) {
		frame_array[j] = -1;
	}

	cout << "Enter the STRING of Page Numbers :-\n";
	for (int i = 0; i < total_pages; ++i) {
		cin >> string[i];
	}

	int frame_counter = 0;
	int fault_counter = 0;
	cout << "\nSTRING\t\t   PAGE FRAMES\n";
	for (int i = 0; i < total_pages; ++i) {

		cout << "  " << string[i] << "\t\t";
		bool miss = true;

		for (int j = 0; j < total_frames; ++j) {
			if ( frame_array[j] == string[i]) {
				miss = false;
				break;
			}
		}

		if ( miss ) {
			frame_array[ (frame_counter++) % total_frames ] = string[i];
			fault_counter++;
		}

		for (int j = 0; j < total_frames; ++j) {
			cout << frame_array[j] << "\t";
		}
		if ( !miss ) {
			cout << "\b\b\b\b\b*";
		}
		cout << endl;
	}

	cout << "\n\n Total Page Faults  : " << fault_counter;

	return 0;
}
