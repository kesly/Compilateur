#include "../includes/state.h"

E0::E0() : Etat("État 0") {}
E1::E1() : Etat("État 1") {}
E2::E2() : Etat("État 2") {}
E3::E3() : Etat("État 3") {}
E4::E4() : Etat("État 4") {}
E5::E5() : Etat("État 5") {}
E6::E6() : Etat("État 6") {}
E7::E7() : Etat("État 7") {}
E8::E8() : Etat("État 8") {}
E9::E9() : Etat("État 9") {}

bool E0::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.decalage(s, new E1);
            break;
        default:
            automate.decalage(new Erreur, NULL);
            break;
    }
    return false;
}

bool E1::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        default:
            automate.decalage(new Erreur, NULL);
            break;
    }
    return false;
}

bool E2::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.decalage(s, new E6);
            break;
        default:
            automate.decalage(new Erreur, NULL);
            break;
    }
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.reduction(1, new Plus);
            break;
        case MULT:
            automate.reduction(1, new Mult);
            break;
        case CLOSEPAR:
            automate.reduction(1, new ParentheseFermante);
            break;
        case FIN:
            automate.reduction(1, new Fin);
            break;
        default:
            automate.decalage(new Erreur, NULL);
            break;
    }
    return false;
}

bool E4::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.decalage(s, new E7);
            break;
        default:
            automate.decalage(new Erreur, NULL);
            break;
    }
    return false;
}

bool E5::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.decalage(s, new E8);
            break;
        default:
            automate.decalage(new Erreur, NULL);
            break;
    }
    return false;
}

bool E6::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new E9);
            break;
        default:
            automate.decalage(new Erreur, NULL);
            break;
    }
    return false;
}

bool E7::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.reduction(3, new Plus);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.reduction(3, new ParentheseFermante);
            break;
        case FIN:
            automate.reduction(3, new Fin);
            break;
        default:
            automate.decalage(new Erreur, NULL);
            break;
    }
    return false;
}

bool E8::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.reduction(3, new Plus);
            break;
        case MULT:
            automate.reduction(3, new Mult);
            break;
        case CLOSEPAR:
            automate.reduction(3, new ParentheseFermante);
            break;
        case FIN:
            automate.reduction(3, new Fin);
            break;
        default:
            automate.decalage(new Erreur, NULL);
            break;
    }
    return false;
}

bool E9::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.reduction(3, new Plus);
            break;
        case MULT:
            automate.reduction(3, new Mult);
            break;
        case CLOSEPAR:
            automate.reduction(3, new ParentheseFermante);
            break;
        case FIN:
            automate.reduction(3, new Fin);
            break;
        default:
            automate.decalage(new Erreur, NULL);
            break;
    }
    return false;
}
