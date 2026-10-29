class Solution {
public:
    int bulbSwitch(int n) {
        int on = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int r = 1; r <= i; r++)
                if (i % r == 0) cnt++;
            if (cnt % 2) on++;
        }
        return on;
    }
};