/***********************
 *Автор: Гончаров Роман*
 *Вариант: 4           *
 ***********************/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main() 

  string filename = "txt";
  ifstream inputFile(filename);
    
  if (!inputFile.is_open()) {
  cout << "Error opening file!" << endl;
  return 1;
  }
    
  string fileContent;
  char currentChar;
  int letterTotalCount = 0;
  int bigramTotalCount = 0;
  map<char, int> letterFrequency;
  map<string, int> bigramFrequency;
    
  while (inputFile.get(currentChar)) {
    if (isalpha(currentChar)) {
      currentChar = tolower(currentChar);
      fileContent += currentChar;
      letterTotalCount++;
    }
  }
  inputFile.close();
    
  for (char letter : fileContent) {
    letterFrequency[letter]++;
  }
    
  for (size_t position = 0; position < fileContent.length() - 1; position++) {
    string bigram = fileContent.substr(position, 2);
    bigramFrequency[bigram]++;
    bigramTotalCount++;
  }
    
  cout << "Letter frequency:\n";
  for (const auto& letterEntry : letterFrequency) {
    double frequencyPercent = (letterEntry.second * 100.0) / letterTotalCount;
    cout << "  " << letterEntry.first << ": " << letterEntry.second 
         << " (" << frequencyPercent << "%)\n";
  }
    
  cout << "\nBigram frequency:\n";
  for (const auto& bigramEntry : bigramFrequency) {
    double frequencyPercent = (bigramEntry.second * 100.0) / bigramTotalCount;
      cout << "  " << bigramEntry.first << ": " << bigramEntry.second 
           << " (" << frequencyPercent << "%)\n";
  }
    
  return 0;
}
