#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    unordered_set<string> myset;
    bool isPresent=false;
    
    for(int i=0; i<wordList.size(); i++)
    {
        string curr = wordList[i];
        if(curr.compare(endWord)==0)
            isPresent=true;
        myset.insert(curr);
    }
    
    if(isPresent==false)
        return 0;
    
    queue<string> q;
    q.push(beginWord);
    int depth=0;
    while(!q.empty())
    {
        depth++;
        int squeue = q.size();
        while(squeue--)
        {
            string cur = q.front();
            q.pop();
            for(int i=0; i<cur.length(); i++)
            {
                string temp = cur;
                for(char c='a'; c<='z'; c++)
                {
                    temp[i]=c;
                    if(temp.compare(cur)==0)
                        continue;
                    if(temp.compare(endWord)==0)
                        return depth+1;
                    if(myset.find(temp)!=myset.end())
                    {
                        q.push(temp);
                        myset.erase(temp);
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    string startWord,endWord;
    vector<string> dict;
    cout<<"Enter the start word: ";
    cin>>startWord;
    cout<<"Enter the end word: ";
    cin>>endWord;
    int n;
    cout<<"Enter number of words in word dictionary: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string x;
        cin>>x;
        dict.push_back(x);
    }
    cout<<ladderLength(startWord,endWord,dict)<<endl;
}