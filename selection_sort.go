package main

import "fmt"

func main() {
	arr := [10]int{10, 5, 1, 4, 2, 7, 8, 9, 3, 6}
	var lowest_index int

	fmt.Println(arr)

	for i := 0; i < len(arr); i++ {
		lowest_index = i

		for j := i + 1; j < len(arr); j++ {
			if arr[j] < arr[lowest_index] {
				lowest_index = j
			}
		}

		aux := arr[i]
		arr[i] = arr[lowest_index]
		arr[lowest_index] = aux
	}

	fmt.Println(arr)
}
