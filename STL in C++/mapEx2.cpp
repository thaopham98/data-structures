#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include <iomanip>

using namespace std;

int main(){

  ifstream inFile;
  inFile.open("textData.txt");

  vector<string> allWords;

  string word;
  while(inFile >> word){
    allWords.push_back(word);
  }

  map<string, int> wordFreq;
  for(auto w:allWords){
    auto it = wordFreq.find(w);
    if(it == wordFreq.end()){
      wordFreq[w] = 1;
    }
    else{
      wordFreq[w]++;
    }
  }

  int max = 0;
  string maxword;
  for(auto iter = wordFreq.begin(); iter != wordFreq.end(); iter++){
    if(iter->second > max){
      max = iter->second;
      maxword = iter->first;
    }

    cout << left << setw(15) << iter->first << " appears " << setw(5) << iter->second << " time." << endl;
  }

  cout << "Word " << maxword << " appears " << max << " times" << endl;



  return 0;
}
