class Solution {
public:
    double solve(double x, long long int n) {
        if (n == 0)
            return 1; 
        if (n == 1)
            return x;     
        double res = solve(x, n / 2);
        res = res * res; 
        if ((n % 2) == 1 ){  // if n is odd then x ^ n = x * 2 (x ^ (n/2))
            res = res * x; 
        }
        return res;
    }
    double myPow(double x, int n) {
        
        if (n >= 0)
            return solve(x, n);
        else {
            long long int n1 = n;
            n1 *= -1;
            return double(1.0)/pow(x, n1);
        }
    }
};