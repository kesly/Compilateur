#include "../includes/automate.h"
#include "../includes/state.h"
#include "../includes/symbole.h"
#include <iostream>
#include <vector>

using namespace std;

Automate::Automate(string chaine) {

  lexer = new Lexer(chaine);
  statestack.push_back(new E0);

}

void Automate::lancer() {

  bool valide = true;

  while(valide) {

    Symbole * s = lexer->Consulter();
    lexer->Avancer();
    valide = statestack.back()->transition(* this, s);

  }

  // if(* symbolestack.back() != ERREUR)
  // { cout << " = " << symbolestack.back()->eval() << endl; }
  // else { cout << endl << "L'expression n'est pas reconnue."; }

}

void Automate::decalage(Symbole * s, Etat * e) {

  symbolestack.push_back(s);
  statestack.push_back(e);

}

void Automate::reduction(int n, Symbole * s) {

  vector<Symbole *> expression;
  int valeurExpression;

  for(int i=0 ; i<n ; i++) {

    delete(statestack.back());
    statestack.pop_back();
    expression.push_back(symbolestack.back());
    symbolestack.pop_back();

  }

  switch(n) {

    case 1: valeurExpression = expression.back()->eval(); break;
    case 3:
      if(* expression.back() == OPENPAR) {

        delete(expression.back());
        expression.pop_back();
        valeurExpression = expression.back()->eval();

      } else {

        valeurExpression = expression.back()->eval();
        expression.pop_back();

        if(* expression.back() == PLUS) {
          delete(expression.back());
          expression.pop_back();
          valeurExpression = valeurExpression + expression.back()->eval();
        } else {
          delete(expression.back());
          expression.pop_back();
          valeurExpression = valeurExpression * expression.back()->eval();
        }

      }

      break;

    default: valeurExpression = 0; break;

  }

  cout << endl << "Expression : " << valeurExpression << endl;

  statestack.back()->transition(* this, new Expr(valeurExpression));
  lexer->ajouter(s);

}
