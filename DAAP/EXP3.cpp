// selection sort
#include "iostream"

class list {
private:
	int *arr;
	int len;
public:
	list( int length ) {
		arr = new int(length);
		len = length;
	}
	int min( int start_pos ) {
		int min_location = start_pos;
		int min = arr[start_pos];
		for (int i = start_pos; i < len; ++i) {
			if ( arr[i] < min ){
				min = arr[i];
				min_location = i;
			}
		}
		return min_location;
	}
	void swap(int from_loc, int to_loc) {
		int temp = arr[from_loc];
		arr[from_loc] = arr[to_loc];
		arr[to_loc] = temp;
	}
	void input() {
		std :: cout << "\n Enter Each of the Number in list\n";
		for (int i = 0; i < len; ++i) {
			std :: cout << "  Number " << (i + 1) << " : ";
			std :: cin >> arr[i];
		}
	}
	void display() {
		std :: cout << "\n The List is\n\n";
		std :: cout << "[ ";
		for (int i = 0; i < len; ++i) {
			std :: cout << arr[i] << ", ";
		}
		std :: cout << "\b\b ]";
	}
};

int main() {

	int num;

	std :: cout << "\n\t\tSelection Sort\n\n";
	std :: cout << "\n Enter the total numbers in the list : ";
	std :: cin >> num;

	list one(num);

	one.input();

	for (int i = 0; i < num; ++i) {
		one.swap(i, one.min(i));
	}

	one.display();

	return 0;
}