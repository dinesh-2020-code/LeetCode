//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> generatePrimes(int N) {
        
        vector<int> ds(N + 1, 1 ); 
        ds[0] = ds[1] = 0; 
        for (int i = 2; i*i <= N; i++) {
            if (ds[i] == 1) {
                for(int j = i * i ; j <= N; j += i) {
                    ds[j] = 0;  
                }
            }
        }
        return ds;
    }
    void printVec(vector<int> v) {
        for (auto it : v ) {
            cout << it << " " ;
        }
        cout << endl; 
    }
    long long primeProduct(long long L, long long R){
        long long int product = 1; 
        
        vector<int> prime = generatePrimes(sqrt(R)); 
        // printVec(prime);
        
        vector<int> primes; 
        for( int i = 2; i < prime.size(); i++) {
            if (prime[i])
                primes.push_back(i); 
        }
        // printVec(primes); 
        int segment[R - L + 1];
        memset(segment, -1, sizeof(segment)); 
        int firstMultiple;
        //marking all multiples of primes array as 0 
        for (int i = 0; i < primes.size(); i++) {
           
            firstMultiple = (L / primes[i]) * primes[i]; 
            
            if (firstMultiple < L)
                firstMultiple += primes[i]; 
                
            for (int j = max(firstMultiple, primes[i] * primes[i]); j <= R; j += primes[i]) {
                segment[j - L] = 0; 
            }     
        }
        for (int i = L; i<= R; i++){
            if (segment[i - L] == -1) {
                // cout << i << " "; 
                product = (product * i) % 1000000007; 
            }
        }
        
        
        return product % 1000000007;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
// } Driver Code Ends