class Solution:
    #User function Template for python3
    
    # arr[]: Input Array
    # N : Size of the Array arr[]
    #Function to count inversions in the array.
    
    #merge() function to merge the sorted array and inversion count
    def merge(self, arr, aux, low, mid, high):
        k = i = low
        j = mid + 1
        inversionCount = 0
    
        while i <= mid and j <= high:
            if arr[i] <= arr[j]:
                aux[k] = arr[i]
                k += 1
                i += 1
            else:
                aux[k] = arr[j]
                j += 1
                k += 1
                inversionCount += (mid - i + 1)
    
        
        while i <= mid: 
            aux[k] = arr[i]
            i += 1
            k += 1
        
        while j <= high:
            aux[k] = arr[j]
            j += 1
            k += 1
            
        for var in range(low, high + 1):
            arr[var] = aux[var]    
            
        return inversionCount
        
    
    def mergeSort(self, arr, aux, low, high):
        inversionCount = 0
        #base case
        if (high <= low):
            return 0
    
        #find midpoint
        mid = low + (high - low)//2
        
    
        inversionCount += self.mergeSort(arr, aux, low, mid)
        inversionCount += self.mergeSort(arr, aux, mid+1, high)
        inversionCount += self.merge(arr, aux, low, mid, high)
    
        return inversionCount

   
    
    def inversionCount(self, arr, n):
        
        aux = arr.copy()
        
        return self.mergeSort(arr, aux, 0, n - 1)
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for tt in range(t):
        n = int(input())
        a = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.inversionCount(a,n))
# } Driver Code Ends