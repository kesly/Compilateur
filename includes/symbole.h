#pragma once

#include <string>
#include <map>

using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {

   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      virtual double eval();

   protected:
      int ident;

};

class ParentheseOuvrante : public Symbole {

   public:
      ParentheseOuvrante() : Symbole(OPENPAR) { }

};

class ParentheseFermante : public Symbole {

   public:
      ParentheseFermante() : Symbole(CLOSEPAR) { }

};

class Plus : public Symbole {

   public:
      Plus() : Symbole(PLUS) { }

};

class Mult : public Symbole {

   public:
      Mult() : Symbole(MULT) { }

};

class Fin : public Symbole {

   public:
      Fin() : Symbole(FIN) { }

};

class Erreur : public Symbole {

   public:
      Erreur() : Symbole(ERREUR) { }

};

class Entier : public Symbole {

   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      void Affiche();
      double eval();

   protected:
      int valeur;

};

class Expr : public Symbole {

   public:
      Expr(int v): Symbole(EXPR), valeur(v) {}
      ~Expr() {}
      double eval();

   protected:
      int valeur;

};
