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

void merge (int arr [], int left, int mid, int right) {
    int length_array_one = mid - left + 1;
    int length_array_two = right - mid;

    int *left_arr = new int[length_array_one];
    int *right_arr = new int[length_array_two];

    for (int i = 0; i < length_array_one; i++) {
        left_arr[i] = arr[left + i];
    }

    for (int j = 0; j < length_array_two; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

    int index_sub_arr_one = 0, index_sub_arr_two = 0, aux_index = left;

    while (
        index_sub_arr_one < length_array_one
        && index_sub_arr_two < length_array_two
    ) {
        if (left_arr[index_sub_arr_one] <= right_arr[index_sub_arr_two]) {
            arr[aux_index] = left_arr[index_sub_arr_one];
            index_sub_arr_one++;
        } else {
            arr[aux_index] = right_arr[index_sub_arr_two];
            index_sub_arr_two++;
        }

        aux_index++;
    }

    while (index_sub_arr_one < length_array_one) {
        arr[aux_index] = left_arr[index_sub_arr_one];
        index_sub_arr_one++;
        aux_index++;
    }

    while (index_sub_arr_two < length_array_two) {
        arr[aux_index] = right_arr[index_sub_arr_two];
        index_sub_arr_two++;
        aux_index++;
    }

    delete [] left_arr;
    delete [] right_arr;
}

void merge_sort (int array[], int begin, int end) {
    if (begin >= end) { return; }

    int mid = begin + (end - begin) / 2;

    // Ele faz primeiro a esquerda toda
    merge_sort(array, begin, mid);

    // Depois faz a direita toda
    merge_sort(array, mid + 1, end);

    merge(array, begin, mid, end);
}

int main () {
    int arr [10] =  {10, 5, 1, 4, 2, 7, 8, 9, 3, 6};
    int arr_length = sizeof(arr)/sizeof(arr[0]);

    print_array("Initial", arr, arr_length);

    merge_sort(arr, 0, arr_length - 1);

    print_array("Sorted", arr, arr_length);

    return 0;
}
