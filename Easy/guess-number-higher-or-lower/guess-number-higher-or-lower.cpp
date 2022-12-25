/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
  int guessNumber(int n) {
    int64_t left = 0;
    int64_t right = n;
    int64_t mid;
    int x = 1;
    while (x != 0) {
      mid = (left + right) >> 1;
      x = guess(mid);
      if (x == -1) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return mid;
  }
};