Ques::
        1930. Unique Length -
    3 Palindromic Subsequences
        Given a string s,
    return the number of unique palindromes of length three that are a subsequence of s.

    Note that even if there are multiple ways to obtain the same subsequence,
    it is still only counted once.A palindrome is a string that reads the same forwards and backwards.A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters.For example, "ace" is a subsequence of "abcde".

                                                                                                                                                                                                                                                                                                          solution::class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int res = 0;
        unordered_set<char> uniq;

        for (char c : s)
        {
            uniq.insert(c);
        }

        for (char c : uniq)
        {
            int start = s.find(c);
            int end = s.rfind(c);

            if (start < end)
            {
                unordered_set<char> charSet;
                for (int i = start + 1; i < end; i++)
                {
                    charSet.insert(s[i]);
                }
                res += charSet.size();
            }
        }

        return res;
    }
};