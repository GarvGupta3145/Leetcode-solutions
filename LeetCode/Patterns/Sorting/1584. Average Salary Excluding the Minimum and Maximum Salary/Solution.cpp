class Solution {
public:
    double average(vector<int>& salary) {
        double aum=accumulate(salary.begin(),salary.end(),0);
        int mn=*min_element(salary.begin(),salary.end());
        int mx=*max_element(salary.begin(),salary.end());
        aum=aum-mn-mx;
        return aum/((int)salary.size()-2);
    }
};