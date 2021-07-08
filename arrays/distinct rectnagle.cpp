
int distinctRectange(int arr[], int n, int k) {
    // two pointer approach
	int left = 0;
	int right = n - 1;
	int count = 0;
	while (left <= right) {
        // if there product is less than k
		if (arr[left]*arr[right] < k) {
            // 2 3 4 5
            // left=2 ,right=5 
            // 5*2=10 <15(k)
            // so we will include all elements from 2 till 5 as they are in sorted
            // (right-left)
            // *2 bcz 5*2 is pair and 2*5 is also a pair
            // +1 bcz 2*2 can also be pair whick is less than 15(k)

			count = count + (right - left) * 2 + 1;
			left++;

		} else {
			right--;
		}
	}

	return count;
}