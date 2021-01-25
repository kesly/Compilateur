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
      virtual bool isTerminal();
      virtual void Affiche();

   protected:
      int ident;
};

class ParentheseOuvrante : public Symbole {
   public:
      ParentheseOuvrante() : Symbole(OPENPAR) { }
      virtual bool isTerminal();
};

class ParentheseFermante : public Symbole {
   public:
      ParentheseFermante() : Symbole(CLOSEPAR) { }
      virtual bool isTerminal();
};

class Plus : public Symbole {
   public:
      Plus() : Symbole(PLUS) { }
      virtual bool isTerminal();
};

class Mult : public Symbole {
   public:
      Mult() : Symbole(MULT) { }
      virtual bool isTerminal();
};

class Fin : public Symbole {
   public:
      Fin() : Symbole(FIN) { }
      virtual bool isTerminal();
};

class Erreur : public Symbole {
   public:
      Erreur() : Symbole(ERREUR) { }
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      virtual bool isTerminal();
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr(): Symbole(EXPR) {}
      virtual ~Expr() {}
      virtual double eval(const std::map<string,double>& valeurs) = 0;
};

class ExprBin : public Expr {
   public:
      ExprBin(Expr * expr1, Expr * expr2) : Expr() {}
      virtual ~ExprBin() {}
      double eval(const std::map<string,double>& valeurs);
   protected:
      Expr * expr1;
      Expr * expr2;
};

class ExprPlus : public ExprBin {
   public:
      ExprPlus(Expr * expr1, Expr * expr2) : ExprBin(expr1, expr2) {}
      virtual ~ExprPlus() {}
};

class ExprMult : public ExprBin {
   public:
      ExprMult(Expr * expr1, Expr * expr2) : ExprBin(expr1, expr2) {}
      virtual ~ExprMult() {}
};
