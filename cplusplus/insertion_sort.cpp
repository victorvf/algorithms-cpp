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
// best case -> array was already sorted: O(n)
// worst case -> array was reverse sorted: O(n2)
int main () {
    int i;
    int key;
    int arr [6] = {31,41,59,26,41,58};

    print_array("Initial", arr);

    int arr_length = sizeof(arr)/sizeof(arr[0]);

    // starts with the second
    for (int j = 1; j < arr_length; j++) {
        key = arr[j]; // second
        i = j - 1; // previous index

        // decreasing order -> while (i >= 0 && arr[i] < key)
        // increasing order
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
        }

        arr[i+1] = key;
    }

    print_array("Sorted", arr);

    return 0;
}

/*
Loop Invariant:

- Initialization: It is true prior to the first iteration of the loop.

- Maintenance: If it is true before an iteration of the loop, it remains true
before the next iteration.

- Termination: When the loop terminates, the invariant gives us a useful
property that helps show that the algorithm is correct.

E.g: Insertion sort
- Initialization: We start by showing that the loop invariant holds before the
first loop iteration, when j=1. The subarray A[0..j-1], therefore, consists
of just the single elemente A[0], which is in fact the original element in A[0].
Moreover, this subarray is sorted(trivially, of course), which shows that the 
loop invariant holds prior to the first iteration of the loop.

- Maintenance: Next, we tackle the second property: showing that each iteration
maintains the loop invariant. Informally, the body of the for loop works by
moving A[j-1], A[j-2], A[j-3], and so on by one position to the right until it 
finds the proper position for A[j], at which point it inserts the value of A[j].
The subarray A[1..j] then consists of the elements originally in A[1..j], but in
sorted order. Incrementing j for the next iteration of the for loop then
preserves the loop invariant. A more formal treatment of the second property
would require us to state and show a loop invariant for the while loop. At this
point, however, we prefer not to get bogged down in such formalism, and so we
rely on our informal analysis to show that the second property holds for the
outer loop.

- Termination: Finally, we examine what happens when the loop terminates. The
condition causing the for loop to terminate is that j > A.length = n. Because
each loop iteration increases j by 1, we must have j = n + 1 at that time.
Substituing n + 1 for j in the wording of loop invariant, we have that subarray
A[1..n] consists of the elements originally in A[1..n], but in sorted order. 
Observing that the subarray A[1..n] is the entire array, we conclude that the
entire array is sorted. Hence, the algorithm is correct.
*/
