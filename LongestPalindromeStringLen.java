package Leetcode;

// package CPP-DSA-180-Days.Day 052 Longest Palindrome___ Sorting the Sentences.class practices;

import java.util.Scanner;


public class LongestPalindromeStringLen {
  public static int longestPalindromeString(String s){
    int[] lower = new int[26];
    int[] upper = new int[26];

    // Iterate over the string
    for(int i=0; i<s.length(); i++){
      // If the character is lowercase
      if(s.charAt(i) >= 'a'){
        lower[s.charAt(i)-'a']++;
      } else {
        upper[s.charAt(i)-'A']++;
      }
    }

    // OR

    // for(char c : s.toCharArray()){
    //   if(c >= 'a'){
    //     lower[c - 'a']++;
    //   } else {
    //     upper[c - 'A']++;
    //   }
    // }

    int count = 0;
    boolean odd = false;

    // Iterate over the array
    for(int i=0; i<26; i++){
      // lower check
      if(lower[i] % 2 == 0){
        count += lower[i];
      } else {
        count += lower[i] - 1;
        odd = true;
      }

      // upper check
      if(upper[i] % 2 == 0){
        count += upper[i];
      } else {
        count += upper[i] - 1;
        odd = true;
      }
    }

    return count + (odd ? 1 : 0);
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Enter the string : ");
    String s = sc.nextLine();

    int result =  longestPalindromeString(s);
    System.out.println("Result = " + result);

  }
}


/*  
Output:-
-----------
Enter the string :
abccccdd
Result = 7

*/


