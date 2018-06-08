#include <iostream>
#include <list>
#include <vector>
#define ALPHABETS 127 
using namespace std;

vector<int> getMap(const string &pat)
{
    vector<int> curMap(ALPHABETS, 0);
    for(int i = 0; i < pat.length(); i++)
        curMap[pat[i]-'A']++;

    return curMap;
}

list<pair<string, vector<string>>> clubAnagrams(const vector<string> &dataSet)
{
    list<pair<string, vector<string>>> clubbedAnagrams;
    string curString;
    for(int i = 0; i < dataSet.size(); i++)
    {
        curString = dataSet[i];
        vector<int> curMap = getMap(curString);
        auto itr = clubbedAnagrams.begin();
        for(; itr != clubbedAnagrams.end(); itr++)
        {
            if(curMap == getMap(itr->first))
            {
                itr->second.push_back(curString);
                break;
            }
        }
        if(itr == clubbedAnagrams.end())
            clubbedAnagrams.push_back(make_pair(curString, vector<string>({curString})));
    }
    return clubbedAnagrams;
}

vector<vector<string>> getClubbedAnagrams(const vector<string> & dataset)
{
    list<pair<string, vector<string>>> clubbedAnagrams;
    vector<vector<string>> clubbedAnagramsVec;
    
    clubbedAnagrams = clubAnagrams(dataset);


    for(auto itr = clubbedAnagrams.begin(); itr != clubbedAnagrams.end(); itr++)
    {
        clubbedAnagramsVec.push_back(itr->second);
    }

    return clubbedAnagramsVec;
}

void printClubbedAnagrams(const vector<vector<string>> & clubbedAnagramsVec)
{
    cout<<"Groups of anagrams: \n";
    if(clubbedAnagramsVec.empty())
    {
        cout<<"---NO ELEMENTS PRESENT---\n";
        return;
    }

    for(int i = 0; i < clubbedAnagramsVec.size(); i++)
    {
        cout<<"Set "<<i+1<<": ";
        for(int j = 0; j < clubbedAnagramsVec[i].size(); j++)
        {
            cout<<clubbedAnagramsVec[i][j]<<", ";
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<string> dataSet;
    vector<vector<string>> clubbedAnagramsVec;

    dataSet.push_back("cat");
    dataSet.push_back("boy");
    dataSet.push_back("tac");
    dataSet.push_back("ya");
    dataSet.push_back("yob");
    dataSet.push_back("tca");
    dataSet.push_back("ay");

    clubbedAnagramsVec = getClubbedAnagrams(dataSet);
    printClubbedAnagrams(clubbedAnagramsVec);
    return 0;
}
