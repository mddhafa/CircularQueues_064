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

		//cek apakah antrian penuh 
		if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		//cek apakah antrian kosong 
		if (front == -1) {
			front = 0;
			rear = 0;
		}
		else {
			//jika rear berada di posisi terakhir array, kembali ke awal array
			if (rear == max - 1)
				rear = 0;
			else
				rear = rear + 1;
		}
		queue_array[rear] = num;
	}
	void remove() {
		//cek apakah antrian kosong 
		if (front == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\nThe element delete from the queue is : " << queue_array[front] << "\n";

		//cek jika antrian memiliki satu element 
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			//jika element yang dihapus berada di posisi terakhir array, kembali ke awal array
			if (front == max - 1)
				front = 0;
			else
				front = front + 1;
		}
	}
	void display() {
		int front_position = front;
		int rear_position = rear;

		//cek apakah antrian kosong
		if (front == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElement in the Queue are...\n";

		//jika front-position <= rear_position, iterasi dari front hingga rear
		if (front_position <= rear_position) {
			while (front_position <= rear_position) {
				cout << queue_array[front_position] << "  ";
				front_position++;
			}
			cout << endl;

		}
		else {
			//jika front-position <= rear_position, iterasi dari front hingga akhir array
			while (front_position <= max - 1) {
				cout << queue_array[front_position] << "  ";
				front_position++;
			}

			front_position = 0;

			//iterasi dari awal array hingga rear
			while (front_position <= rear_position) {
				cout << queue_array[front_position] << "  ";
				front_position++;
			}
			cout << endl;

		}
	}
};

int main() {
	Queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout <<"1. Implement insert operation" << endl;
			cout <<"2. Implement delete operation" << endl;
			cout <<"3. Display values" << endl;
			cout <<"4. Exit" << endl;
			cout << "Enter your choice (1-4)" << endl;
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {
				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;
			}
			case '3': {
				q.display();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "invalid option!!" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << "Check for the velues entered" << endl;
		}
	}
	return 0;
}