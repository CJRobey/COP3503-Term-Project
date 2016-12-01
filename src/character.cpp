#include <string>
#include <iostream>
#include <cstdlib>
#include "AdventureTime.h"

using namespace std;

class Character
{
private:
 string name;
 string type;
 Inventory inv;
 int level;
 int currHealth;
 int maxHealth;

 /*offense is the sum of your level times 5 and the damage
of the weapon equipped */
 int offense;
 int defense;
 int gold;
 void setMaxHealth(int i);

public:
 Character(string name, string type);
 string getName();
 void attack(Character opponent);
<<<<<<< HEAD
 void heal();
 void battle(Character opponent);
=======
 void heal(int potionIndex);
 void run();
 void checkIfDead();
 int getCurrHealth();
>>>>>>> Michael
};



Character::Character(string name, string type)
{
  this->name = name;
  this->type = type;
  this->level = 1;

  /*Other things that we need to do here:
  1. initialize the Inventory
  2. determine health, off, def, etc... which will all likely be a product
  of level*/

}




string Character::getName()
{
    return this->name;
};


void Character::battle(Character opponent)
{
  /*combat algorithms need to be determined
  What kind of effect will defense, offense, and weapon type have on damange?
  Will we have accuracy of hits?
  Will we randomize damage within a certain range?*/
  cout << "You have entered into a battle!" << endl;
  cout << "Input a number regarding how you would like to proceed: " << endl;

  while (true) {

  cout << "1. Attack! \n2. Heal \n3. Run..." << endl;

  int userIn;
  cin >> userIn;

  switch(userIn) {
    case 1:
        attack(opponent);
    break;
    case 2:
      heal();
    break;
    case 3:
<<<<<<< HEAD
    int v1 = rand() % 100;
      if (v1 < 50) {
      cout << "You managed to run away! " << endl;
      return;
    }
      else {
        cout << "Your character failed to run away." << endl;
        break;
      }
  }
=======
      cout << "You ran away! " << endl;
    return;
>>>>>>> Michael
  }
}

int Character::getCurrHealth

void Character::attack(Character opponent)
{
  int attackPower = rand() % (offense + 1);
  if (attackPower == 0){
    cout << "Your attack was ineffective!\nThe monster laughs at your failure."
    << endl;
  }
  else{
    opponent.
  }
}

void Character::decrementHealth(int damage){

}

<<<<<<< HEAD
void Character::heal()
=======
void Character::checkIfDead(){
  if (currHealth < 0){
    cout << "You've died in battle!\n*GAME OVER*" << endl;
  }
}

void Character::heal(Potion potion)
>>>>>>> Michael
{
  Potion potion = inv.getPotion();
  if (potion == NULL) {
    cout << "You don't have a potion you impotent conglomeration of idiocy." << endl;
    return;
  }
  int potionIndex = potion.recovPoints;

  if (currHealth < maxHealth-potionIndex) {
  this->currHealth += potionIndex;
  cout << "You've been healed by " << potionIndex << " health points." << endl;
}
else {
  this->currHealth = maxHealth;
}


}
