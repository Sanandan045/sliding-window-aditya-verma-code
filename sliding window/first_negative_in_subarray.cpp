#include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
 long long i=0;
 long long j=0;
 vector<long long> ans;    // final answer  store in this vector 
 list<long long> l;
  while (j<N){
    if (A[j]<0) 
      l.push_back(A[j]);         // store the all negative  number in list 
    if (j-i+1<K) j++;            // window size is not matched so we increse j 
    else if ((j-i+1)==K)         // hit  window size 
    {
      if (l.size()==0)          // list is empty  it means  no negative element in a window
        ans.push_back(0);       
      else
        ans.push_back(l.front());        // note --> list ka front value hi  first negative number hata hai  us window ka .
        if(A[i]==l.front()){
            l.pop_front();       // remove the  first element  of  arry 
        }
     
      i++;       // slide the window  with i and j increment 
      j++;
    }
  }
  return ans;
}