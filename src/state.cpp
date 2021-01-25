#include "../includes/state.h"

bool E0::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3());
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case '.':
            automate.decalage(s, new E1);
            break;
        case default:
            automate.decalage(s, newE2);
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
        case default:
            automate.decalage(s, newE2);
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
        case '.':
            automate.decalage(s, new E6);
            break;
        case default:
            automate.decalage(s, newE2);
            break;
    }
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.reduction(s, new E5);
            break;
        case MULT:
            automate.reduction(s, new E5);
            break;
        case CLOSEPAR:
            automate.reduction(s, new E5);
            break;
        case FIN:
            automate.reduction(s, new E5);
            break;
        case default:
            automate.decalage(s, newE2);
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
        case '.':
            automate.decalage(s, new E7);
            break;
        case default:
            automate.decalage(s, newE2);
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
        case '.':
            automate.decalage(s, new E8);
            break;
        case default:
            automate.decalage(s, newE2);
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
        case default:
            automate.decalage(s, newE2);
            break;
    }
    return false;
}

bool E7::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.reduction(s, new E2);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new E2);
            break;
        case FIN:
            automate.decalage(s, new E2);
            break;
        case default:
            automate.decalage(s, newE2);
            break;
    }
    return false;
}

bool E8::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.reduction(s, new E3);
            break;
        case MULT:
            automate.reduction(s, new E3);
            break;
        case CLOSEPAR:
            automate.decalage(s, new E3);
            break;
        case FIN:
            automate.decalage(s, new E3);
            break;
        case default:
            automate.decalage(s, newE2);
            break;
    }
    return false;
}

bool E9::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.reduction(s, new E4);
            break;
        case MULT:
            automate.reduction(s, new E4);
            break;
        case CLOSEPAR:
            automate.decalage(s, new E4);
            break;
        case FIN:
            automate.decalage(s, new E4);
            break;
        case default:
            automate.decalage(s, newE2);
            break;
    }
    return false;
}
