/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

Example:
Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
 

Note:

1 <= paragraph.length <= 1000.
1 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
Different words in paragraph are always separated by a space.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.

More easy solution:
https://leetcode.com/problems/most-common-word/discuss/123854/C++JavaPython-Easy-Solution-with-Explanation
throw paragragh into an istringstream.....

*/

//First filter the punctions
//Second change Uppercase to Lowercase
//Then search and accumulate unbanned words.


#include <unordered_map>
#include <unordered_set>
using std::unordered_map;
using std::unordered_set;



class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int gap = 0;
        unordered_map<string, int> QAQ;
        int max_num = 0;
        string res;
        unordered_set<char> punc = {'!',';',',','?','.','\''};
        
        //I learned this easy erase_punciton way from https://leetcode.com/problems/most-common-word/discuss/123822/C++-Simple-Solution
        auto is_punc = [&punc](char c){return punc.count(c);};
        paragraph.erase (remove_if (paragraph.begin (), paragraph.end (), is_punc), paragraph.end ());
        
        for(auto& c:paragraph) c = tolower(c);
        if(paragraph[paragraph.size()-1] != ' ') 
            paragraph += ' ';

        for(int i = 0; i < paragraph.size(); ++i){
            if(paragraph[i] == ' ' || i == paragraph.size()-1){
                string tmp(paragraph, gap, i-gap);
                if(find(banned.begin(), banned.end(),tmp) == banned.end()){
                    ++QAQ[tmp];
                    if(max_num < QAQ[tmp]){
                        max_num = QAQ[tmp];
                        res = tmp;

                    }
                    
                }
                    
                gap = i + 1;
            }
        }
        return res;
        
    }
};
