#include <string>
#include <iostream>
#include <cstdlib>
#include "AdventureTime.h"

class Monster {
  private:
	string name;
    int attack;
    int health;
    Item* items = new Item[10];
    
  public:
    int getAttack();
    int getHealth();
    int getName();
    void decHealth(int attackPower);
    int ptak(int currHealth);
};

Monster::Monster(int health, int attack, string Name)
{
	this->health=health;
	this->attack=attack;
	this->name=name;
}

int getAttack(){
  return attack;
}

int getHealth(){
  return health;
}

void decHealth(int attackPower){
	this->health-=attackPower;
}

int ptak(int currHealth){
 cout<<"Your current health is " << currHeath << " but not for long!" << endl;
 int canAttack = rand() % (5);
 if(canAttack==0) {
	cout<< "Oh no! I missed! How is that possible!?"
	return 0;
 }
 else{
	return attack;
 }
}
