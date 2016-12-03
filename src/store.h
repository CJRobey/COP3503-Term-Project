
#include "inventory.h" 
#include "item.h"
#include <iostream>
#include <string>


class Store 
{
  private:
	   Weapon wepinventory[];
     Potion potinventory[];
     string currentResponse;
     void getWepInventory();
     void getPotInventory();
     void getCharInventory();
     void buy(string itemnumber, int itemtype);
     int sell(Item i);
     string addwepdesc();
     string addpotdesc();
     
  public:
    void openStore();
    
};

void openStore(Character charactername, Inventory inventoryname)
{
  
  cout << "The shopkeeper asks you,\nWould you like to buy or sell today?\nOr if you've got no business here, I'll need to ask you to leave.\n(Please enter buy, sell, or leave)"
  cin >> currentResponse;
  if(currentResponse=="buy")
  {
    cout << "Would you like to buy weapons or potions?\n(Please enter weapons or potions.)\n"
    cin >> currentResponse;
    if(currentResponse=="weapons")
    {
      getWepInventory();
    }
    else if(currentResponse=="potions")
    {
      getPotInventory();
    }
    else
    {
      cout << "Not a valid input."
    }
  }
  else if(currentResponse=="sell")
  {
    getCharInventory();
  }
  else if(currentResponse=="leave")
  {
    "You leave the store."
  }
  else
  {
    cout << "Not a valid input."
  }
  
}

void getWepInventory()
{
  cout << "For sale:\n"
	for(int i=0;i<sizeOf(wepinventory);i++)
	{
		cout << i+1 << ". " << addwepdesc() << getName(wepinventory[i]) <<", capable of dealing "<< getdamage(wepinventory[i])<<" damage.\n";
	}
   cout << i+2 <<". Back to menu.\n(Please enter a number to choose)";
   cin >> currentResponse;
   if(currentResponse >= 1 && currentResponse <= sizeOf(wepinventory)+1)
   {
     buy(currentResponse, 1);
   }
   else if(currentResponse == sizeOf(wepinventory)+2)
   {
     openStore(charactername);
   }
   else
   {
     cout << "Not a valid input."
     getWepInventory();
   }

}

void getPotInventory()
{
	for(int i=0;i< sizeOf(wepinventory);i++)
	{
    cout << i+1 << ". " << addpotdesc() << getName(potinventory[i]) <<", capable of healing "<< getdamage(potinventory[i])<<" damage.\n";
	}
  cout << i+2 <<". Back to menu.\n(Please enter a number to choose)"
  cin >> currentResponse;
  if(currentResponse >= 1 && currentResponse <= sizeOf(potinventory)+1)
  {
    buy(currentResponse, 2);
  }
  else if(currentResponse == sizeOf(potinventory)+2)
  {
    openStore(charactername);
  }
  else
  {
    cout << "Not a valid input."
    getPotInventory();
  }
  
}

void getCharInventory()
{
  cout << "What would you like to sell? (Please enter the name of the item)\n";
  charactername.disInventory();
  cin >> currentResponse;
  sell(currentResponse);
}

void buy(string itemnumber, int itemtype)
{
  switch(itemtype)
  {
    case 1 :
    {
      if(charactername.getGold() >= wepinventory[itemnumber].getCost())
      {
        charactername.decGold(wepinventory[itemnumber].getCost());
        inventoryname.add(wepinventory[itemnumber]);
        cout << "That'll be "<<(wepinventory[itemnumber].getCost())<<" gold."
      }
    }
    case 2 :
    {
      if(charactername.getGold() >= potinventory[itemnumber].getCost())
      {
        charactername.decGold(potinventory[itemnumber].getCost());
        inventoryname.add(potinventory[itemnumber]);
        cout << "That'll be "<<(potinventory[itemnumber].getCost())<<" gold."
      }
    }
  }
  
}

void sell(itemname)
{
        int sellprice = charactername.incGold(inventoryname.drop(itemname));
        cout << "I can give you "<<sellprice<<" gold for that."
}

string addwepdesc()
{
  String wepdescriptors[] = {"A deadly ","A magnificient ","A highly economical ","A flawless ", "An impressive ","An exceptional ", "An incredible value on this ","A ridiculously undervalued"};
  return wepdescriptors[rand() % sizeOf(wepdescriptors)];
}
string addpotdesc()
{
  String potdescriptors[] = {"A value-size ","A great-tasting ","A value-added ","A rock-bottom-priced ", "A great deal on this ","A refresing "};
  return wepdescriptors[rand() % sizeOf(potdescriptors)];
}
