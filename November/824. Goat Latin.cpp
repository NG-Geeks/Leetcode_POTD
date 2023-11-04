Ques::  824. Goat Latin



You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
For example, the word "apple" becomes "applema".
If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
Return the final sentence representing the conversion from sentence to Goat Latin.
Solution::


class Solution {
    bool c(char c){
        return c=='a' or c=='e' or c=='i' or c=='o' || c=='u';
        return 0;
    }
    void add(string &s , int k){
        if(k==0)return ;
        s +="a";
        add(s , k-1);
    }
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string s;
        string t;
        int k=1;
        while(ss>>t){
            if(c(tolower(t[0]))){
                s = s + t +"ma";
                add(s , k);
                k++;
            }
            else {
                s = s + t.substr(1) + t[0] + "ma";
                add(s , k);
                k++;
            }
            s+=" ";
        }
       s = s.substr(0 , s.size()-1);
        return s;
    }
};