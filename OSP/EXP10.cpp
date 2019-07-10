#include "iostream"
using namespace std;

int mutex = 1;
int full = 0;
int empty = 3;
int x = 0;

void producer();
void consumer();

int wait(int);
int signal(int);

int main() {
	char ch = '1';
	cout << " 1. Producer\n 2. Consumer\n Q. Quit";

	while ( ch != 'Q' && ch != 'q' ) {
		cout << "\nEnter your choice : ";
		cin >> ch;

		switch ( ch ) {
			case '1':	if ( mutex == 1 && empty != 0 )
							producer();
						else
							cout << "\nBuffer is full!!" << endl;
						break;
			case '2':	if ( mutex == 1 && full != 0 )
							consumer();
						else
							cout << "\nBuffer is empty!!" << endl;
		}
	}
	return 0;
}
int wait(int x) {
	return --x;
}
int signal(int x) {
	return ++x;
}
void producer() {
	mutex = wait( mutex );
	full = signal( full );
	empty = wait( empty );
	x++;
	cout << "\nProducer produces item " << x << endl;
	mutex = signal( mutex );
}
void consumer() {
	mutex = wait( mutex );
	full = wait( full );
	empty = signal( empty );
	cout << "\nConsumer consumes item " << x << endl;
	x--;
	mutex = signal( mutex );
}