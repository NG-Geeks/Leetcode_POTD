Ques::
2785. Sort Vowels in a String
Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

 
 solution::
class Solution {
    bool isvowel(char c){
        return (c=='A' or c=='E' or c=='I' or c=='O' or c=='U' or c=='a' or c=='e' or c=='i' or c=='o' or c=='u');
    }
public:
    string sortVowels(string s) {
        string t = "";
        for(int i=0;i<s.length();i++){
            if(isvowel(s[i]))t+=s[i];
        }
        sort(begin(t) , end(t));
        int k=0;
        for(int i=0;i<s.length();i++){
            if(isvowel(s[i]))s[i]=t[k++];
        }
        return s;
    }
};