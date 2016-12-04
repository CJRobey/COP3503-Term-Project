#include <iostream>
#include <string>
#include "item.cpp"
#include <map>
#include <sstream>

using namespace std;

class Inventory {

  private:
    map<string, Weapon> Weapons;
    Potion P;
    int potCount;
    int weaponCount;

  public:
    Inventory();
    void disInventory();
    int drop(string itemName);
    void addPotion();
    void addWeapon(Weapon W);
    int usePotion();
    int getWeapon();
    void setPotionAmount(int amount);
    void setPotionHealing(int healing);
    void setPotionCost(int cost);
    void setPotionWorth(int worth);
    int getPotionCost();
    int getPotionHealing();
    bool isElemOfWeap(string s);
    map<string, Weapon> getWeaponMap();
    int getPotCount();
    Potion getPotion();
    int sellPotion();

};

Inventory::Inventory() {
  /*instantiate a level one character Inventory, which contains nothing.*/
  this->potCount = 0;
  this->weaponCount = 0;

}


int Inventory::sellPotion() {
  if(potCount > 0) {
  this->potCount--;
  cout << "You sold a potion" << endl;
  }
  else {
    cout << "You don't have any potions to sell" << endl;
  }
  return P.getCost();

}

Potion Inventory::getPotion() {
  return P;
}

int Inventory::getPotCount() {
  return potCount;
}

map<string, Weapon> Inventory::getWeaponMap() {
  return this->Weapons;
}


    void Inventory::disInventory(){
        Weapon iteratedWeapon;
        string name, damage, worth, spaces, cost, healing, amount= "";
        int length,attribute;
        stringstream ss;
        spaces = "                    ";
        cout << endl << "\t|~|~|~|~|~|~|~|~|~|~| INVENTORY |~|~|~|~|~|~|~|~|~|~|" << endl << endl;
        cout << "\tWeapon         Damage    Price     Worth" << endl;
        for(map<string, Weapon>::iterator iter = Weapons.begin(); iter != Weapons.end(); ++iter) {
            iteratedWeapon = Weapons[iter->first];
            name = iteratedWeapon.getName();
            length = name.length();
            cout << "\t" << name << spaces.substr(0,15-length);
            attribute = iteratedWeapon.getDamage();
            ss << attribute;
            damage = ss.str();
            ss.str("");
            length = damage.length();
            cout << damage << spaces.substr(0,10-length);
            attribute = iteratedWeapon.getCost();
            ss << attribute;
            cost = ss.str();
            ss.str("");
            length = cost.length();
            cout << cost << spaces.substr(0,10-length);
            attribute = iteratedWeapon.getWorth();
            ss << attribute;
            worth = ss.str();
            ss.str("");
            cout << worth << endl;
        }
        cout << endl;
        cout << "\tName         Healing   Price     Worth     Amount" << endl;
            name = P.getName();
            //cout << "Name is " << name << endl;
            length = name.length();
            //cout << "Length of name is " << length << endl;
            cout << "\t" << name << spaces.substr(0,15-length);
            attribute = P.getHealing();
            ss << attribute;
            healing = ss.str();
            ss.str("");
            length = healing.length();
            cout << healing << spaces.substr(0,10-length);
            attribute = P.getCost();
            ss << attribute;
            cost = ss.str();
            ss.str("");
            length = cost.length();
            cout << cost << spaces.substr(0,10-length);
            attribute = P.getWorth();
            ss << attribute;
            worth = ss.str();
            ss.str("");
            length = worth.length();
            cout << worth << spaces.substr(0,10-length);
            attribute = potCount;
            ss << attribute;
            amount = ss.str();
            ss.str("");
            cout << amount << endl;
        cout << endl;
        cout << "\t|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|" << endl << endl;
    }

    int Inventory::drop(string itemName) {
        int worth;
        if (Weapons.count(itemName)) {
            worth = Weapons[itemName].getWorth();
            Weapons.erase(itemName);
            cout << itemName << " has been removed." << endl;
        }

        else if (!itemName.compare(P.getName())) {
            if (potCount > 1) {
                potCount--;
                worth = P.getWorth();
            }
            else {
                cout << "You do not own enough potion!" << endl;
                worth = 0;
            }
        }
        else {
            cout << "You don't own that item!" << endl;
            worth = 0;
        }
        return worth;
    }

    void Inventory::addPotion() {
        this->potCount++;
    }

    void Inventory::addWeapon(Weapon W) {
        string weaponName = W.getName();
        if (Weapons.count(weaponName))
            cout << "You already own that weapon!" << endl;
        else {
            Weapons[weaponName] = W;
            cout << weaponName << " has been added!" << endl;
        }
    }

    int Inventory::usePotion() {
        int healing;
        if(potCount > 0) {
            this->potCount--;
            healing = P.getHealing();
        }
        else {
            healing = 0;
            cout << "You do not own enough potion!" << endl;
        }
        return healing;
    }

    int Inventory::getWeapon() {
        Weapon currentWeapon;
        Weapon strongestWeapon;
        int maxDamage = 0;
        for(map<string, Weapon>::iterator iter = Weapons.begin(); iter != Weapons.end(); ++iter) {
            currentWeapon = Weapons[iter->first];
            if (currentWeapon.getDamage() > maxDamage) {
                maxDamage = currentWeapon.getDamage();
            }
        }
      return maxDamage;
    }

    bool Inventory::isElemOfWeap(string s) {
      if (Weapons.count(s)) {
        return true;
      }
      else return false;
    }


    void Inventory::setPotionHealing(int healing) {P.setHealing(healing);} //set healing value

    void Inventory::setPotionCost(int cost) {P.setCost(cost);}

    int Inventory::getPotionHealing(){return P.getHealing();} //return healing value

    void Inventory::setPotionWorth(int i) {
      P.setWorth(i);
    }