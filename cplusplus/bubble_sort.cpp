#include <iostream>
using namespace std;


void print_array (string title, int arr [], int arr_length) {
    cout << title << " array: [";
    for (int y = 0; y < arr_length; y++) {
        if (y != arr_length - 1) {
            cout << arr[y] << ", ";
        } else {
            cout << arr[y];
        }
    }
    cout << "]" << endl;
}

int main () {
    int aux;
    int arr [] = {31,41,59,26,41,58};
    int arr_length = sizeof(arr)/sizeof(arr[0]);

    print_array("Initial", arr, arr_length);

    for (int i = 0; i < arr_length; i++) {
        for (int j = 0; j < arr_length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }

    print_array("Sorted", arr, arr_length);

    return 0;
}
