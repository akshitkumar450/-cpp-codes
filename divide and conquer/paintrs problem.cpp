bool isPossible(int board[], int n, int painters, int deadline) {

    // first painter 
	int countPainters = 1;
    // time for first painter
	int painterTime = 0;

	for (int i = 0; i < n; i++) {
        // add till the first painter time does not exceed the deadline
		painterTime += board[i];

        // if at any point time exceeds the deadline and new painter should assigned
		if (painterTime > deadline) {
			countPainters++;
            // new painter will start from ith index
			painterTime = board[i];

            // if the total painter exceed the total no of painters then we can not paint the board with given no of painters
			if (countPainters > painters) {
				return false;
			}
		}
	}

	return true;
}

int painterProblem(int board[], int n, int painters, int perUnitTime) {

    // min time is max element in the given array
	int minTime = INT_MIN;
    // maxtime is sum of all the element in array
	int maxTime = 0;

	for (int i = 0; i < n; i++) {
		maxTime += board[i];
		minTime = max(board[i], minTime);
	}

    // the search space
	int start = minTime;
	int end = maxTime;

    // at max the time will be equal to maxtime
	int ans = maxTime;

	while (start <= end) {

		int mid = (start + end) / 2;
		int deadline = mid;

		if (isPossible(board, n, painters, deadline)) {
            // similar to lower bound or first occurence
			ans = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}

	}

	return ans;
}