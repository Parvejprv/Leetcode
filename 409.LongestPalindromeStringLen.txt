/*  
Question : Find the Logest Palindrome of a given string.
Input : "abba"
Output : 4
Input : "abab"
Output : 4

Input : "ababc"
Output : 5

Input: "abccccdd"
Output: 7

Solution :  even number times then add direct otherwise odd number of time then add odd-1;


*/

#include<iostream>
#include<vector>
using namespace std;

int longestPalindromeString(string &s){
  // create vectors for these upper and lower case frequency count
  vector<int> lower(26,0), upper(26,0);

  // Iterate Over the string to update the frequency
  for(int i=0; i<s.size(); i++){
    if(s[i] >= 'a')
      lower[s[i]-'a']++;
    else
      upper[s[i]-'A']++;
  }

  int count = 0;    // resultant count for longest palidrome string
  bool odd = 0;   // initially false

  for(int i=0; i<26; i++){
    // lower check, if lower[i]%2 == 0 , that means it is even number of times present, else odd number of time present
    if(lower[i] % 2 == 0) {
      count += lower[i];
    } else {
      count += lower[i]-1;
      odd = 1;
    }

    // upper check, if lower[i]%2 == 0 , that means it is even number of times present, else odd number of time present
    if(upper[i] % 2 == 0) {
      count += upper[i];
    } else {
      count += upper[i]-1;
      odd = 1;
    }
  }

  return (count + odd);
}

int main(){
  string s;
  cout << "Enter the string : ";
  cin >> s;

  int result = longestPalindromeString(s);
  cout << "Result = " << result << endl;

  return 0;
}



/*  
Output:-
---------
Enter the string : abccccdd
Result = 7



*/

