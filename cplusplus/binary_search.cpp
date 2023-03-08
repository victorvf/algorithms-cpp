#include <iostream>
using namespace std;

int binary_search (int arr [], int min, int max, int num) {
    int average;

    while (min <= max) {
        average = (min + max) / 2;

        cout << "average: " << average << endl;

        if (arr[average] == num) {
            return num;
        } else if (arr[average] < num) {
            min = average + 1;
        } else {
            max = average - 1;
        }
    }

    return -1;
}

int main () {
    int num = 19;

    int arr [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    int arr_length = sizeof(arr)/sizeof(arr[0]);

    int min = 0;
    int max = arr_length - 1;

    int result = binary_search(arr, min, max, num);

    if (result != -1) {
        cout << "Achou " << result << endl;
    } else {
        cout << "Só nada" << endl;
    }

    return 0;
}
