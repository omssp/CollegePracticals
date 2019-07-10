#include "iostream"
using namespace std;

int main() {

	int total_pages, page_size;
	cout << "Enter total number of pages : ";
	cin >> total_pages;

	cout << "Enter the size of each page : ";
	cin >> page_size;

	int** sa = new int*[total_pages];
	for (int i = 0; i < total_pages; ++i) {
		sa[i] = new int[page_size];
		cout << static_cast<void*>(sa[i]) << "\t";
		cout << &sa[i] << endl;
	}
	return 0;
}