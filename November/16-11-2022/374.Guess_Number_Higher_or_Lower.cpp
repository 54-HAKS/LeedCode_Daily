class Solution {
 public:
  int guessNumber(int n) {
    int l = 1;
    int r = n;

    // Find the first guess num that >= target num
    while (l < r) {
      const int m = l + (r - l) / 2;
      if (guess(m) <= 0)  // -1, 0
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};