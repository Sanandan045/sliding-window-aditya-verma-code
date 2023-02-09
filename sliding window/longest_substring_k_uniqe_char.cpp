#include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std;

// problem -> longest substring with k uniqe  charcter
// Approach -> sliding window
// note -> here we use map for  store uniqe charcter 

int longestKSubstr(string s, int k) {
        
        int i=0;
        int j=0;
        
        int mx=INT_MIN;
       unordered_map<char,int>mp;
       
        
        while(j<s.length()){
            mp[s[j]]++;           // store  uniqe charcter in map
            if(mp.size()<k){       // 
                j++;
                
            }
            else if(mp.size()==k){    // map  size euqal to no  of uniqe character
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mp.size()>k){
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){         // in map any charcter have count zero then erase it from map
                        mp.erase(s[i]);
                        
                    }
                    i++;  
                }
                j++;          //slide  window slide with j increment
                
            }
            
        }
        return mx;
      

