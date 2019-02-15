//Tia Silivelio
//p5.cpp
//Palindrome Evaluator

#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

const string filename = "/home/fac/sreeder/class/cs1430/p5.dat";

int main()
{

ifstream infile;

  while(tolower(ans) != 'n'){
    cout << "Please input a file name: ";
    cin >> filename;
    cout << endl;
  
  infile.open(filename.c_str());
  if(infile.fail()){
    cout << "file error...press enter..." << endl;
  }

  while(infile >> word){
    if(lowerLetter(word)){
      cout << word << " is a palindrome." << endl;
      palCount++;
    }else{
      cout << word << " isn't a palindrome." << endl;
    }

    totalWords++;
  }

  cout << endl << endl;
  cout << "Total number of words: " << totalWords << endl;
  cout << "Total number of palindromes: " << palCount << endl;

  infile.close();

  cout << endl << endl;
  cout << "Would you like to input another file? (y/n): ";
  cin >> ans;
  cout << endl << endl;

  //resets variables if another file is inputted
  totalWords = 0;
  palCount = 0;

  }

  //goodbye message
  cout << "Goodbye!" << endl;

  return 0;
}

bool lowerLetter(string str) //makes all letters in word lowercase
{
  string result;
  char letter = ' ';

  result = str;

  for(unsigned int i = 0; i < result.length(); i++){
    letter = tolower(result[i]);
    result[i] = letter;
  }

  return isPalindrome(result);

}

bool isPalindrome(string str)
{
  bool pal = true;
    Stack s;
    Queue q;

  for(unsigned int i = 0; i < str.length; i++){
    s.push(str[i]);
    q.enqueue(str[i]);
  }
  for(unsigned int i = 0; i < str.length; i++){
    if(s.pop() != q.dequeue()){
      pal = false;
  }

  return pal;
}	
