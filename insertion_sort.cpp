#include <iostream>
#include <string>
using namespace std;


void print_array (string title, int (&arr) [6]) {
    cout << title << " array: [";
    for (int y = 0; y < 6; y++) {
        if (y != 5) {
            cout << arr[y] << ", ";
        } else {
            cout << arr[y];
        }
    }
    cout << "]" << endl;
}

// insertion sort
int main () {
    int i;
    int key;
    int arr [6] = {31,41,59,26,41,58};

    print_array("Initial", arr);

    int arr_length = sizeof(arr)/sizeof(arr[0]);
    for (int j = 1; j < arr_length; j++) {
        key = arr[j];
        i = j - 1;

        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
        }

        arr[i+1] = key;
    }

    print_array("Sorted", arr);

    return 0;
}
