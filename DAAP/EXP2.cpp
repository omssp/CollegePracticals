// binary search algorithm
#include "iostream"
//using namespace std;

int max, min;
int *a;

void maxmin(int i, int j) {
	int max1, min1, mid;
	if ( i == j ) {
		max = min = a[i];
	} else {
		if ( i == j-1 ) {
			if ( a[i] < a[j] ) {
				max = a[j];
				min = a[i];
			} else {
				max = a[i];
				min = a[j];
			}
		} else {
			mid = (i + j) / 2;
			maxmin(i, mid);
			max1 = max;
			min1 = min;
			maxmin(mid+1, j);
			if (max < max1) {
				max = max1;
			}
			if (min > min1) {
				min = min1;
			}
		}
	}
}

int main() {
	int i, num;
	std :: cout << "\n\t\tMAXIMUM & MINIMUM\n\n";
	std :: cout << "\n Enter the total numbers in the list : ";
	std :: cin >> num;

	a = new int(num);

	std :: cout << "\n Enter Each of the Number :-\n";
	for (int i = 0; i < num; ++i) {
		std :: cout << "  " << (i + 1) << " : ";
		std :: cin >> a[i];
	}

	max = a[0];
	min = a[0];

	maxmin(0, num-1);

	std :: cout << "\n Largest  Number is : " << max;
	std :: cout << "\n Smallest Number is : " << min;

	return 0;
}