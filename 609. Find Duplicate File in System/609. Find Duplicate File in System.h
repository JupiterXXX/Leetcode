/*
609. Find Duplicate File in System
Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.

A group of duplicate files consists of at least two files that have exactly the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

"directory_path/file_name.txt"

Example 1:
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:  
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]

Note:
No order is required for the final output.
You may assume the directory name, file name and file content only has letters and digits, and the length of file content is in the range of [1,50].
The number of files given is in the range of [1,20000].
You may assume no files or directories share the same name in the same directory.
You may assume each given directory info represents a unique directory. Directory path and file info are separated by a single blank space.

Follow-up beyond contest:
ref:https://leetcode.com/problems/find-duplicate-file-in-system/discuss/104123/C++-clean-solution-answers-to-follow-up
1. Imagine you are given a real file system, how will you search files? DFS or BFS ?
In general, BFS will use more memory then DFS. However BFS can take advantage of the locality of files in inside directories, and therefore will probably be faster

2. If the file content is very large (GB level), how will you modify your solution?
In a real life solution we will not hash the entire file content, since it's not practical. Instead we will first map all the files according to size. Files with different sizes are guaranteed to be different. We will than hash a small part of the files with equal sizes (using MD5 for example). Only if the md5 is the same, we will compare the files byte by byte

3. If you can only read the file by 1kb each time, how will you modify your solution?
This won't change the solution. We can create the hash from the 1kb chunks, and then read the entire file if a full byte by byte comparison is required.

What is the time complexity of your modified solution? What is the most time consuming part and memory consuming part of it? How to optimize?
Time complexity is O(n^2 * k) since in worse case we might need to compare every file to all others. k is the file size

How to make sure the duplicated files you find are not false positive?
We will use several filters to compare: File size, Hash and byte by byte comparisons.

*/
#include <string>
#include <algorithm>
#include <sstream>

using std::string;
using std::find;
using std::stringstream;
//Pay attention to the condition of this problem: find duplicate file!!!.
//Using stringstream will make programming easy.
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> res;
        for(auto path:paths){
            stringstream ss(path);
            string root;
            string s;
            getline(ss, root, ' ');
            while(getline(ss, s, ' ')){
                string fileName = root +'/' + s.substr(0, s.find('('));
                string fileContent = s.substr(s.find('(')+1, s.find(')') - s.find('(') - 1);
                files[fileContent].push_back(fileName);
            }
        }
        
        for(auto file:files){
            if(file.second.size()>1)
                res.push_back(file.second);
        }
        return res;
        
    }
};

//My first edition, not completed.
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        vector<string> idx;
        for(int i = 0; i < paths.size(); ++i){
            int start = 0;
            int end = 0;
            int left = 0;
            int right = 0;
            int j = 0;
            while(j < paths[i].size()){
                if(paths[i][j] == '('){
                    left = j;
                    end = j-1;
                    while(paths[i][j] != ')')
                        ++j;
                    right = j;
                    cout<<"start: "<<start<<" end: "<<end<<endl;
                    cout<<"left: "<<left<<" right: "<<right<<endl;
                    
                    string tmp = paths[i].substr(start, end-start+1);
                    string tmp_idx = paths[i].substr(left+1, right-left-1);
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                    if(find(idx.begin(), idx.end(), tmp_idx) == idx.end()){
                        idx.push_back(paths[i].substr(left+1, right-left-1));
                        res.push_back({paths[i].substr(start, end-start+1)});    
                    }else{
                        res[find(idx.begin(), idx.end(), tmp_idx)-idx.begin()].push_back(paths[i].substr(start, end-start+1));
                    }
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                    start = right + 2;
                }                
                ++j;
            }
        }
        return res;
        
    }
};
