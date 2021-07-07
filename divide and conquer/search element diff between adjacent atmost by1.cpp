// brute force
//  can be done by simple linear search

// optimal

// The idea is to start comparing from the leftmost element and
//  find the difference between current array element and x.
//   Let this difference be ‘diff’. From the given property of array,
//  we always know that x must be at-least ‘diff’ away, 
// so instead of searching one by one, we jump ‘diff’. 

int search(int arr[], int n, int x)
{
    // Traverse the given array starting from
    // leftmost element
    int i = 0;
    while (i<n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;
 
        // Jump the difference between current
        // array element and x
        i = i + abs(arr[i]-x);
    }
 
    cout << "number is not present!";
    return -1;
}