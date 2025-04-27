class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int size = flowerbed.size();

        for (int i = 0; i < size; i += 1) {
            if (flowerbed[i] == 0) {
                bool emptyLeft = (i == 0) || (flowerbed[i-1] == 0);
                bool emptyRight = (i == size-1) || (flowerbed[i+1] == 0);

                if (emptyLeft && emptyRight) {
                    cnt++;
                    flowerbed[i] = 1;
                }
            }
        }
        return cnt >= n;
    }
};
