class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int total = nums.size(),
            t = total / 3,
            wc = 0;
        for (int i = 0, mask = 0; i < 32 && t < total; i++) {
            wc |= 1 << i;
            mask |= 1 << i;
            int count = 0;
            for (int num: nums)
                if ((num & mask) == wc)
                    count++;
            if (count <= t)
                wc ^= 1 << i, total -= count;
            else if (total - count <= t)
                total = count;
            else {
                int prev = ~wc,
                    maj = 0,
                    cnt = 0;
                for (int num: nums)
                    if ((num & mask) == wc)
                        if (prev == ~wc)
                            prev = num;
                        else {
                            if (prev == num)
                                if (maj == num)
                                    cnt++;
                                else if (--cnt <= 0)
                                    maj = num, cnt = 1;
                            prev = ~wc;
                        }
                if (!cnt)
                    maj = prev;
                cnt = 0;
                for (int num: nums)
                    if (num == maj)
                        cnt++;
                if (t < cnt)
                    result.push_back(maj);
                wc ^= 1 << i, total -= count;
            }
        }
        if (t < total)
            result.push_back(wc);
        return result;
    }
};