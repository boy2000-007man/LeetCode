class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0,
            p = 0, h = 1, order = 0;
        for (int i = 1; i < ratings.size(); order = ratings[i] - ratings[i - 1], i++)
            if (ratings[i] == ratings[i - 1]) {
                if (order < 0)
                    sum += (1 + h) * h / 2 + max(0, p - h);
                else
                    sum += (1 + h) * h / 2;
                p = 0;
                h = 1;
            } else if (!order || 0 < order * (ratings[i] - ratings[i - 1]))
                h++;
            else {
                if (order < 0)
                    sum += (1 + h) * h / 2 - 1 + max(0, p - h);
                else
                    sum += (1 + h) * h / 2 - h;
                p = h;
                h = 2;
            }
        if (order < 0)
            sum += (1 + h) * h / 2 + max(0, p - h);
        else
            sum += (1 + h) * h / 2;
        return sum;
    }
};