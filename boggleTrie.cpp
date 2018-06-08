#include <iostream>
#include "jaiTrie.h"

int dir_x[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dir_y[] = { 0,  1, 1, 1, 0,-1,-1, -1};

void printMatrix(char **matrix, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

void findWordWithPrefix(char **matrix, int maxRow, int maxCol, int curRow, int curCol, Trie &dictionary, Trie &foundWords, string &curWord)
{
    if(dictionary.wordExists(curWord))
        foundWords.addWord(curWord);

    int newRow, newCol;

    for(int i = 0; i < 8; i++)
    {
        newRow = curRow + dir_y[i];
        newCol = curCol + dir_x[i];
        if(newRow >= 0 && newRow < maxRow && newCol >=0 && newCol < maxCol &&
            matrix[newRow][newCol] != '-')
        {
            curWord.push_back(matrix[newRow][newCol]);
            matrix[newRow][newCol] = '-';

            if(dictionary.prefixExists(curWord))
                findWordWithPrefix(matrix, maxRow, maxCol, newRow, newCol, dictionary, foundWords, curWord);

            matrix[newRow][newCol] = curWord.back();
            curWord.pop_back();
        }
    }
}

void findWordsInBoggle(char **matrix, int row, int col, Trie &dictionary, Trie &foundWords)
{
    string curWord;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            curWord.push_back(matrix[i][j]);
            matrix[i][j] = '-';

            if(dictionary.prefixExists(curWord))
                findWordWithPrefix(matrix, row, col, i, j, dictionary, foundWords, curWord);

            matrix[i][j] = curWord.back();
            curWord.pop_back();
        }
    }
}

void printVector(const vector<string> &vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<" ";
}

int main(int argc, char const *argv[])
{
    int testCase = 1, row = 3, col = 3, noWords = 3;
    cin>>testCase;
    while(testCase--)
    {
        cin>>noWords;
        
        vector<string> words(noWords);
        Trie dictionary, foundWords;

        for(int i = 0; i < noWords; i++)
        {
            cin>>words[i];
            dictionary.addWord(words[i]);    
        }    

        cin>>row>>col;
        char ** matrix = new char*[row];
        for(int i = 0; i < row; i++)
            matrix[i] = new char[col];
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                cin>>matrix[i][j];
        
        findWordsInBoggle(matrix, row, col, dictionary, foundWords);

        vector<string> foundWordsVec = foundWords.getTrieWords();
        
        if(foundWordsVec.empty())
            cout<<-1;
        else
            printVector(foundWordsVec);
        cout<<endl;

        for(int i = 0; i < row; i++)
            delete [] matrix[i];
        delete [] matrix;
    }
    return 0;
}
