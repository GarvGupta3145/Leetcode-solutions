class Solution {
private:
    int getnext(int n){
        int totalSum = 0;
        while(n>0){
            int d = n%10;
            totalSum+=d*d;
            n/=10;
        }
        return totalSum;
    }
public:
    bool isHappy(int n) {
        // unordered_set<int>seen;
        int slow = n;
        int fast = getnext(n);
        // using tortoise hare algorithm
        while(fast!=1 && slow!=fast){
            slow = getnext(slow);
            fast = getnext(getnext(fast));
        }
        return fast==1;
    }
};