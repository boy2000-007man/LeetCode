// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int loc;
        for (int &l = loc = 1, r = n; l < r; )
            if (isBadVersion(l / 2.0 + r / 2.0))
                r = l / 2.0 + r / 2.0;
            else
                l = l / 2.0 + r / 2.0 + 1;
        return loc;
    }
};