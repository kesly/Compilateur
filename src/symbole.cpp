#include "../includes/symbole.h"
#include <iostream>

bool Symbole::isTerminal() { return false; }
bool ParentheseOuvrante::isTerminal() { return true; }
bool ParentheseFermante::isTerminal() { return true; }
bool Plus::isTerminal() { return true; }
bool Mult::isTerminal() { return true; }
bool Fin::isTerminal() { return true; }
bool Entier::isTerminal() { return true; }

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}
