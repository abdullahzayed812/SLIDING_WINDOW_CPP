#include <iostream>

using namespace std;

// Try all possible item, Brute force o(nk).
int slidingWindow(int arr[], int size, int k)
{
  int max = 0;

  for (int i = 0; i < size - k + 1; i++)
  {
    int sum = 0;

    for (int win = 0; win < k; win++)
      sum += arr[win + i];

    if (i == 0 || sum > max)
      max = sum;
  }

  return max;
}

// Efficient way to make same function o(size + k) => o(size)
int efficientSlidingWindow(int arr[], int size, int k)
{
  int maxWindow = 0;

  for (int win = 0; win < k; win++)
    maxWindow += arr[win];

  int sum = maxWindow;

  for (int i = 1; i < size - k + 1; i++)
  {
    sum = sum - arr[i - 1] + arr[i + k - 1];

    maxWindow = max(sum, maxWindow);
  }

  return maxWindow;
}

int main()
{
  const int SIZE = 8;
  int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};

  // cout << slidingWindow(arr, SIZE, 3);

  efficientSlidingWindow(arr, SIZE, 3);

  return 0;
}