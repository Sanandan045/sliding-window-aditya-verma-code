#include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std;

//problem -> longest substring without reapting charcters 
//Approach -> Sliding Window 
// note->  uniqe charactor store krne ke liye map ka use  kiya gya hai


int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        
        int maxi=INT_MIN;
        map<char,int>mp;
        if(s.size()==0){
            return 0;
        }
        while(j<s.size()){
            mp[s[j]]++;          // store string in map for  calculation 
           
           
             if(mp.size()==j-i+1){           // jitni  window ki size  hogi unti me map me uniqe charctor honge
                maxi=max(maxi,j-i+1);        //  ye ek possible answer ho skta hai islye  store kr lete hai
                j++;
            }
            else if(mp.size()< j-i+1){
                while(mp.size()< j-i+1){
                    mp[s[i]]--;            //  here we remove count in map
                    if(mp[s[i]]==0){       // map  me kisi  charctor ka count zero hoga to use map se 
                        mp.erase(s[i]);     // remove kr dete hai
                        
                        
                    }
                    i++;
                    
                    
                }
                j++;      // j  increment for slide the window

            }

        }
        return maxi;