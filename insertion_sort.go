package main

import "fmt"

func main() {
	var i, key int
	arr := [6]int{31, 41, 59, 26, 41, 58}

	fmt.Println(arr)

	for j := 1; j < len(arr); j++ {
		key = arr[j]
		i = j - 1

		// while do GOLang - Muito estranho para mim
		for i >= 0 && arr[i] > key {
			arr[i+1] = arr[i]
			i--
		}

		arr[i+1] = key
	}

	fmt.Println(arr)
}
