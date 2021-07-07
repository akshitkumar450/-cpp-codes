void quickSort(int arr[], int start, int end) {
	// BASE CASE
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	int left = start;
	int right = end;
    // pivot element is the middle element
	int pivot = arr[mid];
	while (left <= right) {
        //move till we have smaller element from mid on the left part 
        // it will stop when we have greater element from mid on left side
		while (arr[left] < pivot) {
			left++;
		}
        //move till we have greater element from mid on the right part 
        // it will stop when we have smaller element from mid on right side
		while (arr[right] > pivot) {
			right--;
		}
        //swap left and right element
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	quickSort(arr, start, right); // left Subproblem
	quickSort(arr, left, end); // right Subproblem
}