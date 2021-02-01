#include "../includes/state.h"
#include <iostream>

Etat::Etat(int i) : ident(i) {}
E0::E0() : Etat(0) {}
E1::E1() : Etat(1) {}
E2::E2() : Etat(2) {}
E3::E3() : Etat(3) {}
E4::E4() : Etat(4) {}
E5::E5() : Etat(5) {}
E6::E6() : Etat(6) {}
E7::E7() : Etat(7) {}
E8::E8() : Etat(8) {}
E9::E9() : Etat(9) {}

bool E0::transition(Automate & automate, Symbole * s) {

    switch(*s) {

        case INT: automate.decalage(s, new E3); break;
        case OPENPAR: automate.decalage(s, new E2); break;
        case EXPR: automate.decalage(s, new E1); break;

        default: automate.decalage(new Erreur, NULL); return false;

    }

    return true;

}

bool E1::transition(Automate & automate, Symbole * s) {

    switch(*s) {

        case PLUS: automate.decalage(s, new E4); break;
        case MULT: automate.decalage(s, new E5); break;

        default: automate.decalage(new Erreur, NULL); return false;

    }

    return true;

}

bool E2::transition(Automate & automate, Symbole * s) {

    switch(*s) {

        case INT: automate.decalage(s, new E3); break;
        case OPENPAR: automate.decalage(s, new E2); break;
        case EXPR: automate.decalage(s, new E6); break;

        default: automate.decalage(new Erreur, NULL); return false;

    }

    return true;

}

bool E3::transition(Automate & automate, Symbole * s) {

    switch(*s) {

        case PLUS: automate.reduction(1, new Plus); break;
        case MULT: automate.reduction(1, new Mult); break;
        case CLOSEPAR: automate.reduction(1, new ParentheseFermante); break;
        case FIN: automate.reduction(1, new Fin); break;

        default: automate.decalage(new Erreur, NULL); return false;

    }

    return true;

}

bool E4::transition(Automate & automate, Symbole * s) {

    switch(*s) {

        case INT: automate.decalage(s, new E3); break;
        case OPENPAR: automate.decalage(s, new E2); break;
        case EXPR: automate.decalage(s, new E7); break;

        default: automate.decalage(new Erreur, NULL); return false;

    }

    return true;

}

bool E5::transition(Automate & automate, Symbole * s) {

    switch(*s) {

        case INT: automate.decalage(s, new E3); break;
        case OPENPAR: automate.decalage(s, new E2); break;
        case EXPR: automate.decalage(s, new E8); break;

        default: automate.decalage(new Erreur, NULL); return false;

    }

    return true;

}

bool E6::transition(Automate & automate, Symbole * s) {

    switch(*s) {

        case PLUS: automate.decalage(s, new E4); break;
        case MULT: automate.decalage(s, new E5); break;
        case CLOSEPAR: automate.decalage(s, new E9); break;

        default: automate.decalage(new Erreur, NULL); return false;

    }

    return true;

}

bool E7::transition(Automate & automate, Symbole * s) {

    switch(*s) {

        case PLUS: automate.reduction(3, new Plus); break;
        case MULT: automate.decalage(s, new E5); break;
        case CLOSEPAR: automate.reduction(3, new ParentheseFermante); break;
        case FIN: automate.reduction(3, new Fin); break;

        default: automate.decalage(new Erreur, NULL); return false;

    }

    return true;

}

bool E8::transition(Automate & automate, Symbole * s) {

    switch(*s) {

        case PLUS: automate.reduction(3, new Plus); break;
        case MULT: automate.reduction(3, new Mult); break;
        case CLOSEPAR: automate.reduction(3, new ParentheseFermante); break;
        case FIN: automate.reduction(3, new Fin); break;

        default: automate.decalage(new Erreur, NULL); return false;

    }

    return true;

}

bool E9::transition(Automate & automate, Symbole * s) {

    switch(*s) {

        case PLUS: automate.reduction(3, new Plus); break;
        case MULT: automate.reduction(3, new Mult); break;
        case CLOSEPAR: automate.reduction(3, new ParentheseFermante); break;
        case FIN: automate.reduction(3, new Fin); break;

        default: automate.decalage(new Erreur, NULL); return false;

    }

    return true;

}

void Etat::print() const { cout << Labels[ident] << endl; }
