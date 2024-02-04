#include <iostream>

using namespace std;

const int arr_size = 100; // Peak array size
int N; // N variable should be global

int max(int arr[], int N)
{
	int maximum = arr[0];
	for (int i = 1; i < N; i++) {
		if (maximum < arr[i]) maximum = arr[i];
	}
	return maximum;
}

void fill(int arr[], int N)
{
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 101;
	}
}

void print_l(int arr[], int K, int N)
{
	for (int i = K; i != K - 1; i++) {
		if (i == N)
			i = 0;
		cout << "arr[" << i << "]: " << arr[i] << ", ";
	}
	cout << "arr[" << K - 1 << "]: " << arr[K - 1] << "." << endl;
}

void print_r(int arr[], int K, int N)
{
	for (int i = K; i != K + 1; i--) {
		if (i == -1)
			i = N - 1;
		cout << "arr[" << i << "]: " << arr[i] << ", ";
	}
	cout << "arr[" << K + 1 << "]: " << arr[K - 1] << "." << endl;
}

void clear_max(int arr[], int N)
{
	int maximum = max(arr, N), tmp;
	for (int i = 0; i < N; i++) {
		if (arr[i] == maximum) {
			for (int j = i; j < N - 1; j++) {
				arr[j] = arr[j + 1];
			}
			::N--; // Decreases array's border
		}
	}
}

int main()
{
	int arr[arr_size], K;
	cout << "Enter the N value: ";
	cin >> N;
	cout << "Enter the K value: ";
	cin >> K;
	cout << endl;

	srand(time(0));

	fill(arr, N);

	cout << "Current array state:" << endl;
	print_l(arr, K, N);

	clear_max(arr, N);
	if (N < K) K = N; // IndexError protection 

	cout << endl << "Array state after max values removal:" << endl;
	print_r(arr, K, N);

	return 0;
}
