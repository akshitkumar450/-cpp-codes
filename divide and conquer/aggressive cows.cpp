bool isValid(int arr[], int n, int cows, int distanceLimit) {

    // first cow can be placed at  index
	int previousCowPosition = arr[0];
    // no of placed cows placed at any point
	int cowsPlacedUptilThisPoint = 1;

	for (int i = 1; i < n; i++) {
		int currentCowPosition = arr[i];
    // distance between 2 cows
		int gapBetweenCows = currentCowPosition - previousCowPosition;
		if (gapBetweenCows >= distanceLimit) {
            // increment the no of cow
			cowsPlacedUptilThisPoint++;
            // new cow will be placed in ith index
			previousCowPosition = arr[i];

            // if we no of cows placed == given cows means we have successfully placed all cows then return true
			if (cowsPlacedUptilThisPoint == cows) {
				return true;
			}
		}
	}

	return false;
}

int aggressiveCows(int arr[], int n, int cows) {

    // sort the given array
	sort(arr, arr + n);

    // minimum distance betweent the cows can be 1
	int minDist = 1;
    // maximum distance
	int maxDist = arr[n - 1] - arr[0];

	int start = minDist;
	int end = maxDist;

    // minimum distance can be 1
	int ans = 1;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (isValid(arr, n, cows, mid)) {
            // upper bound or last occurence
			ans = mid;
			start = mid + 1;
		} else {
			end = mid - 1;
		}

	}

	return ans;
}