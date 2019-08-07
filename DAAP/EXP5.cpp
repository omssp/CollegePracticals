// quicksort algorithm
#include "iostream"

class Quick {
private:
	int *arr;
	int len;
public:
	Quick( int l ){
		len = l;
		arr = new int(l);
	}
	void swap( int *a, int *b ) {
		int t = *a;
		*a = *b;
		*b = t;
	}
	int partition( int low, int high ) {
		int pivot = arr[high];
		int i = low - 1;

		for (int j = low; j < high; ++j) {
			if ( arr[j] <= pivot ) {
				swap( &arr[++i], &arr[j] );
			}
		}
		swap( &arr[i + 1], &arr[high] );
		return (i + 1);
	}
	void quicksort( int low, int high ) {
		if ( low < high ) {
			int pivot = partition( low, high );

			quicksort( low, pivot - 1 );
			quicksort( pivot + 1, high );
		}
	}
	void input() {
		std :: cout << "\n Enter Each of the Number in list\n";
		for (int i = 0; i < len; ++i) {
			std :: cout << "  Number " << (i + 1) << " : ";
			std :: cin >> arr[i];
		}
	}
	void display() {
		std :: cout << "\n The sorted List is\n\n";
		std :: cout << " [ ";
		for (int i = 0; i < len; ++i) {
			std :: cout << arr[i] << ", ";
		}
		std :: cout << "\b\b ]";
	}
};
int main() {

	int n;
	std :: cout << "Enter total numbers in the list : ";
	std :: cin >> n;

	Quick a(n);

	a.input();
	a.quicksort( 0, n-1 );
	a.display();

	return 0;
}