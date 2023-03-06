#include <iostream>
#include <string>
using namespace std;


void print_array (string title, int (&arr) [10]) {
    cout << title << " array: [";
    for (int y = 0; y < 10; y++) {
        if (y != 9) {
            cout << arr[y] << ", ";
        } else {
            cout << arr[y];
        }
    }
    cout << "]" << endl;
}

int main () {
    int arr [10] =  {10, 5, 1, 4, 2, 7, 8, 9, 3, 6};
    int lowest_index;

    print_array("Initial", arr);

    int arr_length = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < arr_length; i++) {
        lowest_index = i;

        for (int j = i + 1; j < arr_length; j++) {
            if (arr[j] < arr[lowest_index]) {
                lowest_index = j;
            }
        }

        int aux = arr[i];
        arr[i] = arr[lowest_index];
        arr[lowest_index] = aux;
    }

    print_array("Sorted", arr);

    return 0;
}
