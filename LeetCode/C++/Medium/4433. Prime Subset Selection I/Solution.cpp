class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool>isPrime(n+1,true);
        vector<int>res;
        long long sum=0;
        for(int i=2;i<=n;i++){
            if(!isPrime[i])continue;
            for(long long j=(long long)i*i;j<=n;j+=i){isPrime[j]=false;}
            if(sum+i>s)break;
            sum+=i;
            res.push_back(i);
        }
        return res;
    }
};