#include <iostream>
#include "fstream" //to be able to read and write frm files
#include "istream"
#include "sstream"
#include "map"
#include "vector"
#include "utility"
#include "algorithm"
using namespace std;

int main() {
    map<string,int>Words;
    fstream TextFile("C:\\Users\\49157\\Downloads\\slim\\k.txt");
    string line,word = " ";
    istringstream iss;
    while (!TextFile.eof()) {
        getline(TextFile, line);
        iss.clear();
        iss.str(line);
        while (iss >> word) {
            if(word.back() == '.' or word.back() == ','){
                word.pop_back();
            }
            auto FoundWord = Words.find(word);
            if(FoundWord == Words.end()){
                Words.insert({word,1});
            } else {
                Words[word]++;
            }
        }
    } // remember that maps are sorted by keys meaning that the only way is to swap between key and values in a newly created map which will cause problems in our case as many elements have the same occurance
    vector<pair<string,int>>SortedWords;
    for(auto i:Words) {
        SortedWords.push_back({i.first, i.second});
    }
    sort(SortedWords.begin(),SortedWords.end(),[](const pair<string,int>&S,const pair<string,int>&S1){return S.second > S1.second;});
    for(auto i:SortedWords) {
        cout << i.second << " " << i.first << endl;
    }
}







