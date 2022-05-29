// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

public final int HigherCase = 1;
public final int LowerCase = 0;
public final int NotLetter = 2;

int lowerOrHigherCase(char symb) {
  int SymbAscII = symb;
  if (symb > 64 && symb < 91)
    return HigherCase;
  if (symb > 96 && symb < 123)
    return LowerCase;
  return NotLetter;
}

BST<std::string> makeTree(const char* filename) {
  BST<std::string> stringTree;
  std::ifstream file(filename);
  if (!file) {
        std::cout << "File error!" << std::endl;
        return;
    }
  
  std::string TextToAdd = "";
  while(!file.eof()) {
    char SymbToAdd = file.get();
    
    switch (lowerOrHigherCase(SymbToAdd)) {
      case HigherCase : {
        TextToAdd += tolower(SymbToAdd);
      } break;
      case LowerCase : {
        TextToAdd += SymbToAdd;
      } break;
      case NotLetter : {
        stringTree.add(TextToAdd);
      } break;
    }
  }
file.close();
return stringTree;
}
