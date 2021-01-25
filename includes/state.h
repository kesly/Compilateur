#pragma once

#include "automate.h"
#include "symbole.h"
#include <string>

using namespace std;

class Etat {
    public:
        Etat(string name);
        virtual~Etat();
        void print() const;
        virtual bool transition(Automate & automate, Symbole * s) = 0;
    protected:
        string name;
};

class E0 : public Etat {
    public:
        E0(string name) : Etat(name) {}
        virtual ~E0();
        bool transition(Automate & automate, Symbole * s);
};

class E1 : public Etat {
    public:
        E1(string name) : Etat(name) {}
        virtual ~E1();
        bool transition(Automate & automate, Symbole * s);
};

class E2 : public Etat {
    public:
        E2(string name) : Etat(name) {}
        virtual ~E2();
        bool transition(Automate & automate, Symbole * s);
};

class E3 : public Etat {
    public:
        E3(string name) : Etat(name) {}
        virtual ~E3();
        bool transition(Automate & automate, Symbole * s);
};

class E4 : public Etat {
    public:
        E4(string name) : Etat(name) {}
        virtual ~E4();
        bool transition(Automate & automate, Symbole * s);
};

class E5 : public Etat {
    public:
        E5(string name) : Etat(name) {}
        virtual ~E5();
        bool transition(Automate & automate, Symbole * s);
};

class E6 : public Etat {
    public:
        E6(string name) : Etat(name) {}
        virtual ~E6();
        bool transition(Automate & automate, Symbole * s);
};

class E7 : public Etat {
    public:
        E7(string name) : Etat(name) {}
        virtual ~E7();
        bool transition(Automate & automate, Symbole * s);
};

class E8 : public Etat {
    public:
        E8(string name) : Etat(name) {}
        virtual ~E8();
        bool transition(Automate & automate, Symbole * s);
};

class E9 : public Etat {
    public:
        E9(string name) : Etat(name) {}
        virtual ~E9();
        bool transition(Automate & automate, Symbole * s);
};
