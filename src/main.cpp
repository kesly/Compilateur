#include "../includes/automate.h"
#include <iostream>

using namespace std;

int main(void) {

  // string chaine("(1+34)*123");
  string chaine;

  cout << "Expression :" << endl;
  cin >> chaine;

  Automate * automate = new Automate(chaine);
  automate->lancer();

   return 0;

}
