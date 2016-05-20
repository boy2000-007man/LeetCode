class Solution {
    int calc(int l, int b, int r, int t) {
        return l < r && b < t ? (r - l) * (t - b) : 0;
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return calc(A, B, C, D) - calc(max(A, E), max(B, F), min(C, G), min(D, H)) + calc(E, F, G, H);
    }
};