#include "../includes/symbole.h"
#include <iostream>

void Symbole::Affiche() { cout << Etiquettes[ident] << endl; }
void Entier::Affiche() { cout << Etiquettes[ident] << " (" << valeur << ")"; }

double Symbole::eval() { return -1; }
double Entier::eval() { return valeur; }
double Expr::eval() { return valeur; }
