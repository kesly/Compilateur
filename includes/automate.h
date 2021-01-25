#pragma once

#include "lexer.h"
#include <string>
#include <vector>

class Etat;

using namespace std;

class Automate {
  public:
    Automate();
    ~Automate();
    void decalage(Symbole * s, Etat * e);
    void reduction(int n, Symbole * s);
  protected:
    vector<Symbole *> symbolestack;
    vector<Etat *> statestack;
    Lexer * lexer;
};
