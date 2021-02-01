#pragma once

#include "automate.h"
#include "symbole.h"
#include <string>

using namespace std;

enum Etats { ETAT0, ETAT1, ETAT2, ETAT3, ETAT4, ETAT5, ETAT6, ETAT7, ETAT8, ETAT9 };

const string Labels[] = { "État 0", "État 1", "État 2", "État 3", "État 4", "État 5", "État 6", "État 7", "État 8", "État 9" };

class Etat {

    public:
        Etat(int i);
        virtual ~Etat() {};
        operator int() const { return ident; }
        void print() const;
        virtual bool transition(Automate & automate, Symbole * s) = 0;

    protected:
        int ident;

};

class E0 : public Etat {

    public:
        E0();
        ~E0() {};
        bool transition(Automate & automate, Symbole * s);

};

class E1 : public Etat {

    public:
        E1();
        ~E1() {};
        bool transition(Automate & automate, Symbole * s);

};

class E2 : public Etat {

    public:
        E2();
        ~E2() {};
        bool transition(Automate & automate, Symbole * s);

};

class E3 : public Etat {

    public:
        E3();
        ~E3() {};
        bool transition(Automate & automate, Symbole * s);

};

class E4 : public Etat {

    public:
        E4();
        ~E4() {};
        bool transition(Automate & automate, Symbole * s);

};

class E5 : public Etat {

    public:
        E5();
        ~E5() {};
        bool transition(Automate & automate, Symbole * s);

};

class E6 : public Etat {

    public:
        E6();
        ~E6() {};
        bool transition(Automate & automate, Symbole * s);

};

class E7 : public Etat {

    public:
        E7();
        ~E7() {};
        bool transition(Automate & automate, Symbole * s);

};

class E8 : public Etat {

    public:
        E8();
        ~E8() {};
        bool transition(Automate & automate, Symbole * s);

};

class E9 : public Etat {

    public:
        E9();
        ~E9() {};
        bool transition(Automate & automate, Symbole * s);

};
