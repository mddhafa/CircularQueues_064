#include <iostream>
using namespace std;


class Queues {
	int front, rear, max = 5;
	int queue_array[5];

public:
	Queues() {
		front = -1;
		rear = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;
	}
};