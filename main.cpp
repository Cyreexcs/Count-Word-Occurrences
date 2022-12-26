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







//TODO: create a program that writes/reads in a text file and outputs the element sorted and the number of elements
//      Go back to sorting with all the different methods and understand Time

/*vector<tuple<string,int>>S = {(tuple<string,int>("Salma",17)),(tuple<string,int>("Ahmed",19)),(tuple<string,int>("Yosr",16))};
sort(S.begin(),S.end(),[](const tuple<string,int>&S0, const tuple<string,int>&S1)->bool { return get<1>(S0) < get<1>(S1);});
for_each(S.begin(),S.end(),[](const tuple<string,int>&S1){ cout << get<0>(S1) << endl;});
int age = 1;    string name ="abdul";   auto X = tie(name,age); */ //TODO:tuple repetition
// TODO the get can take an index or a data type {The data type mode only work when the specific data type was given ONCE}
//  also note that tuples can be return function and they can be assigned as long as the data type matches.
//  Tie() also helps us connect between different elements to create a tuple however what changes here is that we can't use the get<type> anymore but rather the index
//  Tuples and Pairs are also very helpful when it comes to classes. if we want to compare the objects directly without having to go through each an every element we could just
//  tie them Up and create an operator for the comparison

//TODO std::lists lists have their own sort() which will do the sorting according to the < operator but a custom lambda or comparison func may be applied to sort.
// we also have unique() which deletes duplicates according to == operator but can only compare consecutive elements / The remove() function takes values but no indexes and we
// can also use the erase keyword.


// TODO: Set, Multiset, Map and Multimap are all associative containers.
//  Set contains a sorted set of elements that are non repeating too. Now if we are passing a user defined data type such as struct or classes we will be forced to create our
//  own comparison function so that the set can be proper with non repeating elements and sorted.by default sets are descending but we can make change it set<int,less<int>>S={1,7}
//  VERY IMPORTANT:when we use classes we need to create our own operator< but without "const" this won't work !! (insert and erase and .find() to get the iterator are available
//bool operator<(const Person& second)const{return second.age<age
//TODO: we can also use tie to avoid creating 2 operator<
// .end returns pos of last element+1 so if we want to check if an element exists or not we can simply compare its iterator to .end and if they are equal then element isn't available
// TODO: to delete an element from a set we use erase. we either pass the iterator which we find with the .find() or we we pass the actual values.
//  To verify if an element exist there are 2 ways. the first one is to write SetName.count(element) which returns 1 if the element exists and 0 if not or we can simply compare th set.end() to the set.find() if they are
//  equal then we are at the end of the set and the element wasn't found
     //set<Person>Book = {{15,"Slim"},{13,"Alim"},{14,"Alim"}};           Book.insert({14,"xli"}); //inserting a new element             Book.erase({13,"Alim"}); //deleting the element

// TODO: to delete an element from a set we use erase. we either pass the iterator which we find with the .find() or we we pass the actual values
// TODO: To verify if an element exist there are 2 ways. the first one is to write SetName.count(element) which returns 1 if the element exists and 0 if not or we can simply compare th set.end() to the set.find() if they are
     //  equal then we are at the end of the set and the element wasn't found. always remember that with sets and maps elements aren't sorted through an index or a pos and therefore we only have insert rather than pushback ...


// TODO: now similar to sets map have 2 parameters a key and a value for each variable. the keys are different and sorted similar to what we used to have with sets but values can be similar and unordered. access is done through
//  the [] operator similar to the arrays (im contrast to arrays or vectors the keys here can have any type meanwhile by arrays we only have indexes). we can also insert names with the [key] operator or using the insert function
//   similar to sets we can search for the KEYS using either the find() != end() method or the count = 1. keys are immutable meaning they can't be changed however the values belonging to them can be altered.
//   in maps we can also search by values and not by keys using the .second() {try to picture maps as an array of pairs where the first value can't be changed but the rest can}


//TODO: with multi sets and multi maps the .count can now have different values than 0-1 because they allow the use of keys multiple times btw note that the 0-1 are unsigned long of nature but we can apply bool to them in set/map
// Note that the [] operator doesn't exist in multi maps anymore so we are now forced to use insert function or uniform initializer with insert because no unique reference to the value can be given back
// multi sets the comparison will solicetely be done through the values we mentioned.if we only use 2 values in our operator< instead of all 3 what will happen is that we will get the output of all matching elements according to the
//  2 values we compared and the third member won't even matter.


// TODO: let's say we are calculating the number of words given to us. we can use a struct/class and give every item a word and an occurance but instead of using a class with 2 elements we could simply use a pair as it's easier
//  if we are working in a set/multiset/map .. their members have immutable keys meaning that we can't change them so if we want to update smth about them in a vector we need to create a new
//  object of the same data type give it the new values and put it in the set the find is also different in vectors to sets in vectors we would need the vector begin + end but we
//  don't in sets