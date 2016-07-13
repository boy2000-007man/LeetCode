// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        for (unsigned l = 1, h = n, t; ; )
            switch (guess(t = l + h >> 1)) {
                case 0:return t;
                case +1:l = t + 1;break;
                case -1:h = t - 1;break;
            }
    }
};