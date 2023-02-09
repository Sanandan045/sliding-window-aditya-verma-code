#include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std;

int maximumSumSubarray(int K,int Arr[] , int N){
  int i=0;
  int j=0;
  int sum=0;
  int maxi=INT_MIN;
  while (j<N){
    sum=sum+Arr[j]; //  calculation  part
    if (j-i+1<K) j++; // increament j upto when the size of the size of window is not equal to required size
    else if ((j-i+1)==K) //  hit   required window size 
    {
      maxi= max(maxi,sum); // select ans from  claculation
      sum=sum-Arr[i]; // start removing from the first
      i++;            // slide the window i and j increment
      j++;
    }
  }
  return maxi;
}



int main()
{
     int arr[7] = { 2,5,1,8,2,9,1 };
    // int t = sizeof(arr) / sizeof(arr[0]);
    int K1 = 3;
    cout<<maximumSumSubarray(K1,arr,7)<<endl;
    cout<<"Hello World";

    return 0;
}