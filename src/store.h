
#include "inventory.h" 
#include "item.h"
#include <iostream>
#include <string>


class Store 
{
  private:
	   Weapon wepinventory[];
     Potion potinventory[];
     
  public:
    void openStore();
    void getWepInventory();
    void getPotInventory();
    void getCharInventory();
    bool buy(int i);
    int sell(Item i);
    string currentResponse;
};

void openStore(Character charactername)
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
		cout << i+1 << ". " << getName(wepinventory[i]) <<"\n";
	}
   cout << i+2 <<". Back to menu.\n(Please enter a number to choose)";
   cin >> currentResponse;
   if(currentResponse >= 1 && currentResponse <= sizeOf(wepinventory)+1)
   {
     buy(currentResponse, "weapon")
   }
   else if(currentResponse == sizeOf(wepinventory)+2)
   {
     openStore(charactername)
   }
   else
   {
     cout << "Not a valid input."
   }

}

void getPotInventory()
{
	for(int i=0;i< sizeOf(wepinventory);i++)
	{
    cout << i+1 << ". " << getName(potinventory[i])<<"\n";
	}
  cout << i+2 <<". Back to menu.\n(Please enter a number to choose)"
  cin >> currentResponse;
  if(currentResponse >= 1 && currentResponse <= sizeOf(potinventory)+1)
  {
    buy(currentResponse, "potion")
  }
  else if(currentResponse == sizeOf(potinventory)+2)
  {
    openStore(charactername)
  }
  else
  {
    cout << "Not a valid input."
  }
  
}

void getCharInventory()
{
  cout << "What would you like to sell?";
}

//Character can call only if they have enough money.
//Inventory item should check if item is in the store

bool buy(string& itemnumber, string& itemtype)
{
  if(charactername.getGold()>=)
  {
    
  }

  
  {
    return false;
  }
}

int sell(int i)
{
  return i.getCost();
}
