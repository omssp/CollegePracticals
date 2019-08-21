// merge sort
#include "iostream"

class Merge {
private:
	int *arr;
	int len;
public:
	Merge( int l ) {
		len = l;
		arr = new int(l);
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
	void merge( int l, int m, int r ) {
		
		int len1 = m - l + 1;
		int len2 = r - m;

		int *arrL = new int(len1);
		int *arrR = new int(len2);

		for (int i = 0; i < len1; ++i) {
			arrL[i] = arr[l + i];
		}
		for (int i = 0; i < len2; ++i) {
			arrR[i] = arr[m + 1 + i];
		}

		int i, j, k = l;
		for ( i = 0, j = 0; i < len1 && j < len2; k++) {
			if ( arrL[i] <= arrR[j] ) 
				arr[k] = arrL[i++];
			else
				arr[k] = arrR[j++];
		}

		while( i < len1 )
			arr[k++] = arrL[i++];
		while( j < len2 )
			arr[k++] = arrR[j++];
	}
	void mergeSort(int l, int r) {
		if ( l < r ) {
			int m = l+(r-l)/2;

			mergeSort( l, m );
			mergeSort( m+1, r );

			merge( l, m, r );
		}
	}
};

int main() {
	int n;
	std :: cout << "Enter total numbers in the list : ";
	std :: cin >> n;

	Merge a(n);

	a.input();
	a.mergeSort( 0, n-1 );
	a.display();

	return 0;
}