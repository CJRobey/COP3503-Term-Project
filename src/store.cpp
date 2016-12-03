#include <iostream>
#include <string>
#include "AdventureTime.hxx"

//class Store 
//{
  //private:
	   //Weapon wepinventory[];
     //Potion potinventory[];
     
  //public:
    //void openStore();
    //void getWepInventory();
    //void getPotInventory();
    //void getCharInventory();
    //bool buy(int i);
    //int sell(Item i);
    //string currentResponse;
//};

Store::Store(){
	//this-> wepinventory = {Item(Weapon,5,3,Rusty_Fork),Item(Weapon,20,12,Dubious_Dagger),
    //Item(Weapon,50,30,Numchucks_of_Unending_Smiting),Item(Weapon,70,42,Absurdly_Sharp_Lance)
    //Item(Weapon,80,48,Soulstealing_Demonblade),Item(Weapon,100,60,Blade_of_the_Eternal_Gods),
    //Item(Weapon,300,180,Paintbrush_of_the_Devil),Item(Weapon,500,300,Black_Hole_Hammer)};
	//this-> potinventory = {Item(Potion,10,6,Health_Potion)};	

}
void Store::openStore(Character hero)
{
  string currentResponse = "";
  cout << "The shopkeeper asks you,\nWould you like to buy (1) or sell (2) today?\nOr if you've got no business here, I'll need to ask you to leave (3).\n(Please enter a number)";
  cin >> currentResponse;
  if(currentResponse=="1")
  {
    cout << "Would you like to buy weapons (1) or potions (2)?\n(Please enter a number)\n";
    cin >> currentResponse;
    if(currentResponse=="1")
    {
      getWepInventory(inventoryname);
    }
    else if(currentResponse=="2")
    {
      getPotInventory(inventoryname);
    }
    else
    {
      cout << "Not a valid input.";
    }
  }
  else if(currentResponse=="2")
  {
    getCharInventory(inventoryname);
  }
  else if(currentResponse=="3")
  {
    cout << "You leave the store.";
  }
  else
  {
    cout << "Not a valid input.";
  }
  
}

void Store::getWepInventory(Inventory inventoryname)
{
  cout << "For sale:\n";
	for(int i=0;i<wepinventory.size();i++)
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
     cout << "Not a valid input.";
     getWepInventory(inventoryname);
   }

}

void Store::getPotInventory(Inventory inventoryname)
{
	for(int i=0;i< sizeOf(wepinventory);i++)
	{
    cout << i+1 << ". " << addpotdesc() << getName(potinventory[i]) <<", capable of healing "<< getdamage(potinventory[i])<<" damage.\n";
	}
  cout << i+2 <<". Back to menu.\n(Please enter a number to choose)";
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
    cout << "Not a valid input.";
    getPotInventory(inventoryname);
  }
  
}

void Store::getCharInventory(Inventory inventoryname)
{
  cout << "What would you like to sell? (Please enter the name of the item)\n";
  inventoryname.disInventory();
  cin >> currentResponse;
  sell(hero, inventoryname, currentResponse);
}

void Store::buy(string itemnumber, int itemtype)
{
  switch(itemtype)
  {
    case 1 :
    {
      if(hero.getGold() >= wepinventory[itemnumber].getCost())
      {
        hero.decGold(wepinventory[itemnumber].getCost());
        inventoryname.add(wepinventory[itemnumber]);
        cout << "That'll be "<<(wepinventory[itemnumber].getCost())<<" gold.";
      }
    }
    case 2 :
    {
      if(hero.getGold() >= potinventory[itemnumber].getCost())
      {
        hero.decGold(potinventory[itemnumber].getCost());
        inventoryname.add(potinventory[itemnumber]);
        cout << "That'll be "<<(potinventory[itemnumber].getCost())<<" gold.";
      }
    }
  }
  
}

void Store::sell(Character hero, Inventory inventoryname, string itemname)
{
        int sellprice = hero.incGold(inventoryname.drop(itemname));
        cout << "I can give you "<<sellprice<<" gold for that.";
}

string Store::addwepdesc()
{
  String wepdescriptors[] = {"A deadly ","A magnificient ","A highly economical ","A flawless ", "An impressive ","An exceptional ", "An incredible value on this ","A ridiculously undervalued"};
  return wepdescriptors[rand() % sizeOf(wepdescriptors)];
}

string Store::addpotdesc()
{
  String potdescriptors[] = {"A value-size ","A great-tasting ","A value-added ","A rock-bottom-priced ", "A great deal on this ","A refresing "};
  return wepdescriptors[rand() % sizeOf(potdescriptors)];
}
int main () {
	Store s;
	Inventory inv;
	Character* c = new Character("Hero", inv);
	s.openStore(c);

}