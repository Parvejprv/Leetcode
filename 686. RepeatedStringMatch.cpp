/*
Question:- Repeated string matching 
-------------------------------------
Given two strings s1 and s2, write a function to return true if s2 contains the
pattern in s1 (in other words, s1 is a subsequence of s2).


link:-https://leetcode.com/problems/repeated-string-match/
--------



*/


// CPP

class Solution {

  public:
  // to find the lps of a given string
    void findlps(vector<int> &lps, string s){
      
      int pre = 0, suf = 1;
      
      while(suf < s.size()){
        // Matched
        if(s[pre] == s[suf]){
          lps[suf] = pre + 1;
          pre++, suf++;
        }
        // Not Matched
        else {
          // also there are two condition only
          // pre at 0 index
          if(pre == 0){
            // lps[suf] = 0;
            suf++;
          }
          // pre at not 0 index
          else {
            pre = lps[pre - 1];
          }
        }
      }
      
    }
  
    int KMP_MATCH(string haystack, string needle){
      
      vector<int> lps(needle.size(), 0);    // create a vector
      findlps(lps, needle);
      
      int first  = 0, second = 0;
      
      while(first < haystack.size() && second < needle.size()){
        // Matched
        if(haystack[first] == needle[second]){
          first++, second++;
        }
        // Not Matched
        else {
          // second points at 0 of needle string
          if(second == 0){
            // lps[second] = 0;
            first++;
          }
          // second deos not points at 0 of needle string
          else {
            second = lps[second-1];
          }
        }
      }
      
      // Let's check if 2nd string needle got completely traverse or not
      if(second == needle.size()){
        return 1;
      }
      return 0;
    }
    
    int repeatedStringMatch(string a, string b) {
      if(a == b) return 1;
      
      int repeat = 1;
      string temp = a;
      
      while(temp.size() < b.size()){
        temp += a;
        repeat++;
      }
      
      // KMP Pattern Search
      if(KMP_MATCH(temp, b) == 1)
        return repeat;
      // KMP temp+a, Pattern search for confirmation
      if(KMP_MATCH(temp+a, b) == 1)
        return repeat+1;
      // non of the above is correct
      return -1;
      
    }

}




