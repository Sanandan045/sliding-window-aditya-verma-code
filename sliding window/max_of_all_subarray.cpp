#include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std;

//  problem  ->  max of all  subarray of size k   
// here we use sliding window  for sloving a problem 


 vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        int i=0;
        int j=0;
        
        list<int> l;
        vector<int> ans;
        while(j<n){
            
            while(l.size()>0 && l.back()<arr[j]){          // calculation part 
                l.pop_back();
            }
            l.push_back(arr[j]);
            
            if(j-i+1 <k)                                // window is not hit then we increase j
            {
                j++;
            }
           else if(j-i+1   == k){                    // hit the window 
                ans.push_back(l.front());           //  claculation se answer lika gya hai 
                if(l.front()== arr[i]){
                    l.pop_front();                   
                }
                i++;                              // slide window 
                j++;
            }
            
        }
        return ans;
    }