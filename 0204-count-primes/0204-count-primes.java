class Solution {
    public int countPrimes(int n) {
        if (n == 0 || n == 1)
            return 0; 
        
        boolean[] sieve = new boolean[n+1]; 
        Arrays.fill(sieve, true); 
        sieve[0] = false; sieve[1] = false; 
        
        for (int i = 2; i * i <= n; i++) {
            
            if (sieve[i]) {
                
                for (int j = i * i; j < n; j += i) {
                    sieve[j] = false; 
                }
            }
        }
        
        int answer = 0; 
        for (int i = 0; i < n; i++) 
            if (sieve[i]) 
                answer++; 
        
        return answer; 
    }
}