/*
Copyright (C) 2017 Stylianos Tsiakalos


This file is part of Console Adventures.

Console Adventures is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Console Adventures is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Console Adventures.  If not, see <http://www.gnu.org/licenses/>.
*/



#include "header.h"
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>


void main_menu() {

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n----MENU----" << endl;
	cout << "(Input the correspoding number of the option you want to select)" << endl;
	cout << "1.Start a new game" << endl;
	cout << "2.Load game" << endl;
	cout << "3.Game Help (recommended for first time players!)" << endl;
	cout << "4.About" << endl;
	cout << "5.Exit" << endl;



	string menu;

	getline(cin, menu);

	

	if (menu[0] == '5')
		exit(0);

	else if (menu[0] == '4'){

		cout <<endl<<endl<< "CREDITS! :" << endl;
		cout << "Game Code & Design : Stelios Tsiakalos" << endl;
		cout << "Game Testing : Vasilis Vasilas" << endl;
		cout << "Contributors : [Your name here!]" << endl;

		cout << endl<<"Enter -> License info" << endl;
		cin.get();
		cout << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << "Console Adventures is free software: \nyou can redistribute it and/or modify it under the terms of the \nGNU General Public License as published by the Free Software Foundation, \neither version 3 of the License, or (at your option) any later version." << endl;
		cout << endl<<"Console Adventures is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY \nor FITNESS FOR A PARTICULAR PURPOSE.See the GNU General Public License for more details." << endl;
		
		cout << endl << "Press Enter to return to the main menu" << endl;
		cin.get();
		main_menu();
		return;
		


	}

	else if (menu[0] == '2'){
		cout << endl;
		cout << "( Save files are automatically stored in the game folder.\nIf you have moved it you must input the full path.)" << endl;
		cout << "\nInput the name of the save file : " << endl;
		string filename;
		getline(cin, filename);
		unit player;
		short errorcode = player.save_load('l', filename);
		if (errorcode == 0)
			player.zoneselection();
		else{
			main_menu();
			return;
		}
	}

	else if (menu[0] == '1') {

		unit player;
		player.charactercreation();
		player.zoneselection();


	}


	else if (menu[0] == '3') {

		string helptopic;
		do{
			cout << "\nSelect a help topic:" << endl;

			cout << "1.General game information" << endl;
			cout << "2.Stat explanations" << endl;
			cout << "3.CP (Combat Points)" << endl;
			cout << "4.Gear upgrades and prices." << endl;
			cout << "5.Return to main menu " << endl;
			getline(cin, helptopic);

			if (helptopic[0] == '1'){
				cout << "---------------------------------------------------------------" << endl;
				cout << "\nWelcome to Console Adventuress!\n\nThis is a game where you control a noble hero in their quest to rid the realm\nof all evil monsters";
				cout << " (or mercilessly slaughter innocent creatures, depending on your point of view)." << endl;
				cout << "\nYou can choose from 3 different classes, each with its own unique strengths and weaknesses. " << endl;
				cout << "\nYou visit different zones,fighting increasingly challenging enemies." << endl;
				cout << "Defeating enemies grants you gold and experience, which make your character\nstronger in customizable ways.";
			
				


			}

			if (helptopic[0] == '2'){
				cout << "---------------------------------------------------------------" << endl;
				cout << endl << "---STATS---" << endl;
				cout << "HITPOINTS (HP) : Represents the amount of damage you can take.\nIf this falls to zero, YOU DED." << endl;
				cout << "\nMANA POINTS (MP) : For any attack that deals bonus damage,\nMana points need to be spent." << endl;
				cout << "\nPHYSICAL DEFENCE (PDEF) : Reduces all physical damage.\nPhysical damage is dealt by Scouts and Warriors." << endl;
				cout << "\nMAGIC RESISTANCE (MRESIST) : Reduces all magic damage.\nMagic damage is dealt by Mages." << endl;
				cout << "\nATTACKPOWER : Determines the damage you deal with each attack.\nScouts and Warriors deal physical type damage \nwhile Mages deal magic type damage." << endl;
				cout << "\n*CRITICAL RATE* : All attacks have a chance of dealing 100% extra damage.\nThis stat determines this chance." << endl;
				cout << "\nEVASION : All attacks have a chance to be dodged, cancelling their damage.\nThis stat, along with accuracy (see below) , determine this chance." << endl;
				cout << "\nACCURACY : Decreases the chance that your attacks are dodged. " << endl;
				cout << "\n*PARRY* : All attacks have a chance to be parried, negating 1/3 of their damage.\nThis stat determines this chance.\nThe chance to parry an attack is not changed by the enemy's accuracy or\nany other stat." << endl;
				cout << "\nBLOCK : If you are a Warrior, you have a chance of reducing enemy damage by 50%.\nThis stat determines this chance.\nThe chance to block an attack is not changed by the enemy's accuracy or\nany other stat." << endl;
				cout << "\n*LUCK* : After each victory, you have a chance of discovering an item.\nThis stat determines this chance." << endl;

				cout << endl << endl << "Stats that have asterisks in their names,are not normally increased when you    level up." << endl;
			}

			if (helptopic[0] == '3'){
				cout << "---------------------------------------------------------------" << endl;
				cout << "CP (Combat Points) are awarded every time you defeat an enemy.\nThe amount of CP you gain from a victory is determined by the level\nof the defeated enemy,";
				cout << " as well as what percentage of your maximum HP you lost   during the fight (you gain more CP if you lost less).";
				cout << "\nCP can be spent during battle in order to enable higher-power attacks.\nBut those attacks are costly, so use your CP wisely!";
				cout << "\nThere is no limit to how much CP you can collect. ";

			}

			if (helptopic[0] == '4'){
				cout << "---------------------------------------------------------------" << endl;
				cout << "During the game, you can upgrade various stats, with a price in gold." << endl;
				cout << "Each time you buy an upgrade, all subsequent upgrades of the same stat\nwill cost more gold." << endl;
				cout << "At the same time, there is also a small global cost increase to all upgrades,\neach time you buy any upgrade." << endl;
				cout << "For that reason, it is wise to first upgrade the stats you need most!" << endl;
				cout << "An exception to this, is the upgrade of the 'luck' stat." << endl;
				cout << "This upgrade has a fixed cost at ALL times." << endl;

			}
			if (helptopic[0] != '5'){
				cout << endl << endl << "Press Enter to return to the help menu" << endl;
				cin.get();
			}
		} while (helptopic[0] != '5');

		main_menu();


	}



}

void errormessage_bosses() {

	cout << endl << "You must first defeat the bosses of the previous zones!" << endl;
	cout << endl << "Press Enter to continue." << endl;
	cin.get();
}

void message_for_statlimit(string stat,int limitval){

	cout << stat << " cannot be higher than " << limitval << "!"<< endl;
	cout << "Press Enter to continue." << endl;
	cin.get();
}

string game_difficulty;

void character_creation_msg(string classname){

  cout << "You have successfully created a "<<classname<<"!" << endl;
  cout<<" Press Enter to continue"<<endl;
  cin.get();

  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;


}

void select_difficulty(){
  string selection;
  do{
  cout<<endl<<"Select game difficulty :"<<endl;
  cout<<"---------------------------------"<<endl;
  cout<<"0.EASY : Enemies will only use their weakest attack."<<endl;
  cout<<"1.NORMAL : Enemies will choose their attacks randomly."<<endl;
  cout<<"2.HARD : Enemies will always choose the best possible attack (given their MP)."<<endl;
  cin>>selection;
}while(selection != "1" && selection != "2" && selection != "0");

if(selection == "1")
  game_difficulty = "Normal";
else if(selection == "0")
  game_difficulty = "Easy";
else
  game_difficulty = "Hard";

  cout<<endl<<"You have chosen the "<<game_difficulty<<" difficulty."<<endl;
  cout << "Press Enter to continue" << endl;
  cin.get();
  cin.get();
}



void unit::create_warrior() {


    do {
    cout<<"\n\nInput the name of your character : ";
    getline(cin,name);
    if (name.size() > 20)
    cout<<"\a\n\n #The character limit for the name is 20 characters.#"<<endl;
    }
    while(name.size()>20);


    ismob=false;

    playerclass="Warrior";

	gold=0;
	//gold = 9999;
    victories=0;


    maxhp=3000;
    hp=3000;
    mp=1000;
	maxmp = 1000;
    cp=0;


    attackpower=600;
    crit_rate=5;
    accuracy=18;

    pdef=600;
    block=15;
    parry=20;
    evasion=10;

    m_resist=600;

	   luck = 5;

    helmetlevel=1;
    weaponlevel=1;
    bootslevel=1;
	trmlevel = 1;
    jewelslevel=1;
    armorlevel=1;
    shieldlevel=1;


    level=1;
    gearlevel=1;
    current_exp=0;
    levelup_exp=15;

}



void unit::create_mage() {

    do {
    cout<<"\n\nInput the name of your character : ";
    getline(cin,name);
    if (name.size() > 20)
    cout<<"\a\n\n #The character limit for the name is 20 characters.#"<<endl;
    }
    while(name.size()>20);

    ismob=false;

    playerclass="Mage";

    gold=0;
	//gold = 9999;
    victories=0;

    maxhp=500;
    hp=500;
    mp=1000;
	maxmp = 1000;
    cp=0;

    attackpower=2000;
    crit_rate=2;
    accuracy=40;

    pdef=150;
    block=0;
    parry=2;
    evasion=5;

    m_resist=550;

	luck = 5;

    helmetlevel=1;
    weaponlevel=1;
    bootslevel=1;
	trmlevel = 1;
    jewelslevel=1;
    armorlevel=1;
    shieldlevel=1;

    level=1;
    gearlevel=1;
    current_exp=0;
    levelup_exp=15;

	protective_barrier = true;

}



void unit::create_scout() {

     do {
    cout<<"\n\nInput the name of your character : ";
    getline(cin,name);
    if (name.size() > 20)
    cout<<"\a\n\n #The character limit for the name is 20 characters.#"<<endl;
    }
    while(name.size()>20);

    ismob=false;

    playerclass="Scout";

    gold=0;
    victories=0;

    maxhp=1000;
    hp=1000;
    mp=1000;
	maxmp = 1000;
    cp=0;

    attackpower=1000;
    crit_rate=15;
    accuracy=10;

    pdef=450;
    block=0;
    parry=12;
    evasion=40;

    m_resist=450;

	luck = 10;

    helmetlevel=1;
    weaponlevel=1;
    bootslevel=1;
	trmlevel = 1;
    jewelslevel=1;
    armorlevel=1;
    shieldlevel=1;

    level=1;
    gearlevel=1;
    current_exp=0;
    levelup_exp=15;

}


void unit::create_mob(short placeidentifier) {

	//1->5000
	//2->9000
	//3->13000
	//4->17000
	//5->21000

	//6->35000
	//7->40000
	//8->45000
	//9->50000
	//10->60000

    ismob=true;

    const short MIN=1;
    const short MAX=3;

    srand(time(0));

    short classchoice = ((rand() % (MAX - MIN +1))+MIN);


    switch (classchoice) {

        case 1:
        playerclass="Warrior";
        break;

        case 2:
        playerclass="Mage";
        break;

        case 3:
        playerclass="Scout";
        break;

    }





      if(placeidentifier==1) {          ///1=PLAINS   2=FOREST   3=Cave  4=Graveyard 5=Dark Dimension 6=Plains Raid Boss 7=Forest Raid Boss 8=Cave Raid Boss 9=Graveyard Raid Boss 10=Dark Dimension Raid Boss

        if(playerclass=="Warrior")

        name="Incompetent Orc Warrior";

        else if(playerclass=="Mage")

        name="Mute Orc Shaman";

        else if(playerclass=="Scout")

        name="Blind Orc Scout";

    }


    else if(placeidentifier==2) {

        if(playerclass=="Warrior")

        name ="Walking AND Talking Tree";

        else if(playerclass=="Mage")

        name ="Spooky Forest Spirit";

        else if(playerclass=="Scout")

        name ="Goblin Thief";

    }





   else if(placeidentifier==3) {

       if(playerclass=="Warrior")

       name="Cave Giant";

       else if(playerclass=="Mage")

       name="Cave Orc Mage";

       else if(playerclass=="Scout")

       name="Cave Orc Scout";

   }



    else if(placeidentifier==4)  {

      if(playerclass=="Warrior")

       name="A Zombie";


      else if(playerclass=="Mage")

      name="Haunting Spirit";


      else if(playerclass=="Scout")

      name="Wandering Skeleton";


    }





   else if(placeidentifier==5) {

       if(playerclass=="Warrior")

       name="Abyss Guardian";

       else if(playerclass=="Scout")

       name="Abyss Assassin";

       else if(playerclass=="Mage")

       name="Abyss Sorcerer";

   }



   else if(placeidentifier==6) {

       name="Orc CEO";
	   isboss = true;
	   playerclass = "Warrior";

       level=25;
       maxhp=6500;
       hp=6500;
       mp=3000;
       maxmp = 3000;

       pdef=3000;
       m_resist=3000;

       crit_rate=10;
       evasion=50;
       accuracy=60;
       block=55;
       parry=60;

       attackpower=3000;
   }


   else if(placeidentifier==7) {

       name="Needlessly Evil Wizard";
	   isboss = true;
	   playerclass = "Mage";

       level=30;
       maxhp=7000;
       hp=7000;
       mp=3000;
      maxmp = 3000;

       pdef=3250;
       m_resist=3250;

       crit_rate=15;
       evasion=80;
       accuracy=75;
       block=0;
       parry=65;

       attackpower=3500;

   }


   else if(placeidentifier==8) {

    name="Swagosaurus";
	isboss = true;
	playerclass = "Warrior";

    level=35;
    maxhp=8000;
    hp=8000;
    mp=3000;
    maxmp = 3000;

    pdef=3750;
    m_resist=3750;

    crit_rate=20;
    evasion=65;
    accuracy=60;
    block=60;
    parry=50;


    attackpower=4000;

   }


   else if(placeidentifier==9) {

    name="Deathbringah";
	isboss = true;
	playerclass = "Mage";

    level=40;
    maxhp=9500;
    hp=9500;
    mp=3000;
    maxmp = 3000;

    pdef=3750;
    m_resist=3750;

    crit_rate=25;
    evasion=85;
    accuracy=85;
    block=0;
    parry=80;

    attackpower=4750;

   }


   else if(placeidentifier==10) {

    name="The Void Itself";
	isboss = true;
	is_final_boss = true;
	playerclass = "Mage";

    level=50;
    maxhp=10000;
    hp=10000;
    mp=5000;
    maxmp = 5000;

    pdef=5000;
    m_resist=5000;

    crit_rate=30;
    evasion=90;
    accuracy=90;
    block=80;
    parry=90;

    attackpower=5000;

   }


if (name=="Incompetent Orc Warrior") {

    level=1;
    maxhp=1650;
    hp=1650;
    mp=1000;
     maxmp = 1000;

    pdef=450;
    m_resist=300;

    crit_rate=1;
    evasion=0;
    accuracy=5;
    block=5;
    parry=5;

    attackpower=1000;

	str = "Health, Physical Defence";
	weak = "Evasion";


}


else if(name=="Mute Orc Shaman") {

    level=1;
    maxhp=650;
    hp=650;
    mp=1000;
    maxmp = 1000;

    pdef=250;
    m_resist=1000;

    crit_rate=0;
    evasion=5;
    accuracy=10;
    block=0;
    parry=0;

    attackpower=1500;

	str = "Attackpower, Magic Resist";
	weak = "Health";


}


else if(name=="Blind Orc Scout") {

    level=1;
    maxhp=900;
    hp=900;
    mp=1000;
      maxmp = 1000;

    pdef=300;
    m_resist=400;

    crit_rate=5;
    evasion=22;
    block=0;
    parry=35;
    accuracy=8;

    attackpower=1150;

	str = "Evasion , Parry";
	weak = "Health";

}



else if(name=="Walking AND Talking Tree") {

    level=5;
    maxhp=1800;
    hp=1800;
    mp=1000;
      maxmp = 1000;

    pdef=700;
    m_resist=1400;

    crit_rate=0;
    evasion=0;
    block=0;
    parry=40;
    accuracy=0;

    attackpower=1100;

	str = "Health , Physical Defence , Magic Resistance";
	weak = "Accuracy , Evasion , Critical Rate , Block";
}


else if(name=="Spooky Forest Spirit") {

    level=5;
    maxhp=850;
    hp=850;
    mp=2000;
      maxmp = 2000;

    pdef=50;
    m_resist=1500;

    crit_rate=5;
    evasion=10;
    block=0;
    parry=0;
    accuracy=50;

    attackpower=1700;

	str = "Attackpower , Magic Resistance , Extra Mana";
	weak = "Health , Physical Defence";

}


else if(name=="Goblin Thief") {

    level=5;
    maxhp=800;
    hp=800;
    mp=1000;
      maxmp = 1000;

    pdef=200;
    m_resist=350;

    crit_rate=65;
    evasion=65;
    block=0;
    parry=35;
    accuracy=35;

    attackpower=850;

	str = "Critical Rate , Evasion";
	weak = "Health , Attackpower";
}


else if(name=="Cave Giant") {

    level=10;
    maxhp=5000;
    hp=5000;
    mp=2000;
      maxmp = 2000;

    pdef=1500;
    m_resist=50;

    crit_rate=3;
    evasion=0;
    block=25;
    parry=30;
    accuracy=3;

    attackpower=1800;

	str = "Health , Physical Defence , Attackpower";
	weak = "Magic Resistance , Evasion , Accuracy";

}


else if(name=="Cave Orc Mage") {

    level=10;
    maxhp=1800;
    hp=1800;
    mp=2000;
      maxmp = 2000;

    pdef=350;
    m_resist=1500;

    crit_rate=15;
    evasion=10;
    block=0;
    parry=15;
    accuracy=25;

    attackpower=2200;

	str = "Attackpower , Magic Resistance";
	weak = "Physical Defence";

}


else if(name=="Cave Orc Scout") {

    level=10;
    maxhp=2500;
    hp=2500;
    mp=2000;
      maxmp = 2000;

    pdef=600;
    m_resist=650;

    crit_rate=20;
    evasion=30;
    block=0;
    parry=30;
    accuracy=18;

    attackpower=1400;

	str = "Parry , Evasion";
	weak = "Accuracy";

}


else if(name=="A Zombie") {

    level=15;
    maxhp=2000;
    hp=2000;
    mp=2000;
      maxmp = 2000;

    pdef=2500;
    m_resist=2000;

    crit_rate=70;
    evasion=0;
    block=0;
    parry=0;
    accuracy=0;

    attackpower=3000;

	str = "Attackpower , Critical Rate, Physical Defence, Magic Resist";
	weak = "Health , Evasion , Block , Parry , Accuracy";

}


else if(name=="Haunting Spirit") {

    level=15;
    maxhp=1800;
    hp=1800;
    mp=2000;
      maxmp = 2000;

    pdef=700;
    m_resist=2500;

    crit_rate=15;
    evasion=20;
    block=0;
    parry=0;
    accuracy=60;

    attackpower=2500;

	str = "Attackpower , Accuracy , Magic Resistance";
	weak = "Health , Physical Defence";

}



else if(name=="Wandering Skeleton") {

    level=15;
    maxhp=2000;
    hp=2000;
    mp=2000;
      maxmp = 2000;

    pdef=450;
    m_resist=2500;

    crit_rate=65;
    evasion=55;
    block=0;
    parry=30;
    accuracy=65;

    attackpower=1500;

	str = "Critical Rate, Evasion , Parry";
	weak = "Health , Physical Defence";

}


else if(name=="Abyss Guardian") {

    level=20;
    maxhp=5500;
    hp=5500;
    mp=2500;
      maxmp = 2500;

    pdef=2500;
    m_resist=2500;

    crit_rate=10;
    evasion=25;
    block=45;
    parry=40;
    accuracy=55;

    attackpower=1650;

	str = "Health , Physical Defence , Magic Resistance , Block , Parry , Accuracy";
	weak = "Attackpower";

}


else if(name=="Abyss Assassin") {

    level=20;
    maxhp=4000;
    hp=4000;
    mp=2500;
      maxmp = 2500;

    pdef=1500;
    m_resist=2000;

    crit_rate=65;
    evasion=55;
    block=0;
    parry=55;
    accuracy=50;

    attackpower=1700;

	str = "Critical Rate, Parry , Magic Resistance";
	weak = "Physical Defence, Attackpower";

}


else if(name=="Abyss Sorcerer") {

    level=20;
    maxhp=3000;
    hp=3000;
    mp=2500;
      maxmp = 2500;

    pdef=900;
    m_resist=3000;

    crit_rate=10;
    evasion=25;
    block=0;
    parry=0;
    accuracy=70;

    attackpower=3000;

	str = "Attackpower , Accuracy , Magic Resistance";
	weak = "Health, Physical Defence";

}


}


///
void unit::levelup(bool fromitem) {
		if(fromitem == false)
    	current_exp-=levelup_exp;
    levelup_exp+=5;
    level++;
    maxhp +=50;
    attackpower+=50;
    accuracy+=1;
    pdef+=50;
    evasion+=1;
    m_resist+=50;

	if (playerclass == "Warrior"){
		if (block <100)
			block += 1;
	}
	if (playerclass == "Scout"){
		if ( luck < 100)
			luck += 1;
	}


   cout<<"\nYou leveled up!You are now level "<<level<<endl;


}



///
void unit::gameover() {

    cout<<"\n\nYou got rekt!"<<endl;
    cout<<"You managed to achieve "<<victories<<" victories";
    cout<<"\nYou reached level "<<level<<endl;

    cout<<"Press Enter to exit"<<endl;

    cin.get();

    exit(0);
}



///

void unit::endbattle(unit& defeated_unit) {

    if(ismob)

    defeated_unit.gameover();

    else

    victories++;

	if (defeated_unit.zone_id == 6)
		zone6defeated = true;
	else if (defeated_unit.zone_id == 7)
		zone7defeated = true;
	else if (defeated_unit.zone_id == 8)
		zone8defeated = true;
	else if (defeated_unit.zone_id == 9)
		zone9defeated = true;
	else if (defeated_unit.zone_id == 10)
		zone10defeated = true;

    cout<<"\n\n"<<defeated_unit.name<<" has been defeated!"<<endl;

    const short expMAX =10;
    const short expMIN =5;

    short expgain = ((rand() % (expMAX -expMIN +1))+expMIN) + defeated_unit.level ;

    cout<<"\nYou gained "<<expgain<<" EXP"<<endl;
	if (defeated_unit.isboss){
		int extra_exp = int(defeated_unit.level / 2.0);
		expgain += extra_exp;
		cout << "You gained " << extra_exp << " extra EXP for defeating a boss!" << endl;
	}


    current_exp += expgain;


    cout<<"\nEXP :"<<current_exp<<"\\"<<levelup_exp<<endl;

    if (current_exp >= levelup_exp)
    levelup();

    const short goldMAX=100;
    const short goldMIN=1;

    short goldgain = ((rand() % (goldMAX - goldMIN +1))+goldMIN) + (defeated_unit.level*10);

    gold += goldgain;

    long cpgain = ( (hp * 2) + (defeated_unit.level*100) ) / maxhp;
    cpgain = cpgain + 1;
		cpgain = cpgain + int(defeated_unit.level/5.0);

    cp+=cpgain;
    hp=maxhp;
    mp=maxmp;
	if (playerclass == "Mage")
		protective_barrier = true;

    cout<<"The loot was "<<goldgain<<" gold"<<endl;

    cout<<"You now have "<<gold<<" gold"<<endl;

    cout<<"You gained "<<cpgain<<" CP"<<endl;

    cout<<"You now have "<<cp<<" CP"<<endl;

		cout<<"Your level : "<<level;

    cout<<"\n Press Enter twice to continue."<<endl;

    cin.get();
	cin.get();
    

	itemdrop_check();
}

void unit::showmeters(unit& enemy) {


    cout<<"\n\n--"<<name<<"--";
    cout<<"\t\t--"<<enemy.name<<"--"<<endl;
    cout<<"HP :"<<hp<<" \\ "<<maxhp;
    cout<<"\t\t\tHP : "<<enemy.hp<<" \\ "<<enemy.maxhp<<endl;
    cout<<"MP : "<<mp<<" \\ "<<maxmp;
    cout<<"\t\tMP : "<<enemy.mp<<" \\ "<<enemy.maxmp<<endl;

    cout<<"\n\nPress Enter";
    cin.get();
	



}






///returns true if battle is over as a result of the damage dealt.
bool unit::damagecalculate(unit& enemy,const string& skillname,const long extradmg,const short mploss,const short cploss)  {

    srand(time(0));

    long  totaldamage;


    const short divergenceMAX=int(0.05 * attackpower);
    const short divergenceMIN=0;

    short divergence = ((rand() % (divergenceMAX - divergenceMIN +1))+divergenceMIN);

		const short sign_id = rand() % 2;

		if(sign_id == 1)
			divergence = -divergence;


    cout<<"\n\n\n"<<endl;
    cout<<name<<" attacks with "<<skillname<<"!"<<endl;

    mp -=mploss;
    cp -=cploss;


    clock_t begin = clock();
    clock_t delay = 1.5 * CLOCKS_PER_SEC;

    while ((clock() - begin) < delay);   //wait 2 seconds.

   if( (playerclass == "Warrior") ||  (playerclass=="Scout") ) {
    totaldamage =( ( (attackpower +divergence - enemy.pdef)) +extradmg);

   if( totaldamage <= 0 ) {
    totaldamage=1;
    cout<<"Attack failed!"<<endl;
   }
   }
   else {
    totaldamage =( ((attackpower - enemy.m_resist) - divergence) +extradmg);

    if( (enemy.m_resist + divergence) > (attackpower + extradmg) ) {
     totaldamage=0;
     cout<<"Attack failed!"<<endl;
    }
   }

    const short MAX=100;
    const short MIN=1;

//
   short evasionpossibility = ((rand() % (MAX - MIN +1))+MIN);
   if (evasionpossibility <= (int(1.25*enemy.evasion) - accuracy)) {

		   totaldamage = 0;
		   cout << "\n" << (enemy.name) << " dodged the attack!" << endl;
		  
		   begin = clock();
		   while ((clock() - begin) < delay);
		   showmeters(enemy);
		   return false;

	   }


//

   short criticalpropability =((rand() % (MAX - MIN +1))+MIN);

   if(criticalpropability<= crit_rate) {

   totaldamage *= 2;
   cout<<"\nCritical Hit!"<<endl;

   }
//
    short blockpossibility = ((rand() % (MAX - MIN +1))+MIN);

    if (blockpossibility<=(enemy.block) ) {

        totaldamage /= 2;


        cout<<(enemy.name)<<" blocked the attack!"<<endl;
        cout<<(name)<<" inflicted "<<totaldamage<<" to "<<(enemy.name)<<endl;
        enemy.hp -= totaldamage;

        begin = clock();

        while((clock() - begin) < delay);

        if(enemy.hp <= 0) {
        endbattle(enemy);
        return true;
        }
        showmeters(enemy);
        return false;


    }
//





//
    short parrypossibility = ((rand() % (MAX - MIN +1))+MIN);

    if(parrypossibility<=(enemy.parry) ) {


        totaldamage /= 1.5;
        enemy.hp -= totaldamage;

        cout<<(enemy.name)<<" parried the attack!"<<endl;
        cout<<(name)<<" inflicted "<<totaldamage<<" to "<<(enemy.name)<<endl;


        begin = clock();

        while((clock() - begin) < delay);

        if(enemy.hp <=0) {
        endbattle(enemy);
        return true;
        }
        showmeters(enemy);
        return false;


    }
//

   cout<<(name)<<" inflicted "<<totaldamage<<" to "<<(enemy.name)<<endl;

        begin = clock();

        while((clock() - begin) < delay);

   enemy.hp -= totaldamage;
     if(enemy.hp <= 0) {
		 if (!enemy.ismob && enemy.protective_barrier){
			 enemy.protective_barrier = false;
			 cout << endl << endl << enemy.name << " used protective barrier and survived with 1 HP!" << endl;
			 cout << "Press Enter" << endl;
			 enemy.hp = 1;
			 cin.get();
			 return false;
		 }
		endbattle(enemy);
		return true;
     }
     showmeters(enemy);
     return false;
}





///
void unit::attack(unit& enemy) {

    bool isover;
    short mobskillselection;



    if(ismob==true) {

        srand(time(0));
        short skillMAX=4;
        short skillMIN=1;

        if(mp < 400)
        skillMAX=3;

        if(mp < 200)
        skillMAX=2;

        if(mp < 100)
        skillMAX=1;



        if(game_difficulty == "Normal")
          mobskillselection = (rand() % skillMAX) + 1;
        else if(game_difficulty == "Hard")
          mobskillselection = skillMAX;
        else
          mobskillselection = skillMIN;

if(mobskillselection==1)

    isover = damagecalculate(enemy,"Normal Attack",0,0,0);

    else if(mobskillselection==2)

    isover = damagecalculate(enemy,"Strike",100,100,0);

    else if(mobskillselection==3)

    isover = damagecalculate(enemy,"Medium Strike",180,200,0);

    else if(mobskillselection==4)

    isover = damagecalculate(enemy,"Deadly Strike",320,400,0);


    if(isover==false)

    enemy.attack(*this);
    }

 else if(ismob==false) {


 
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n*  *  *  *  *\nYour HP : "<<hp<<"\nYour MP : "<<mp<<endl;
    cout<<"Your	CP : "<<cp<<endl;
    cout<<"*  *  *  *  *"<<endl;
    cout<<"\n\n--Choose your attack--"<<endl;

    cout<<"\n\n[1] Normal Attack"<<endl;
    cout<<"[2] Strike   (MP:100) (Power:100)"<<endl;
    cout<<"[3] Medium Strike   (MP:200) (Power:180)"<<endl;
    cout<<"[4] Deadly Strike   (MP:400) (Power:320)"<<endl;
	cout << "-----------------------------------------------" << endl;
    cout<<"[5] Overpowered Deadly Strike  (MP:400) (CP:100) (Power:1500)"<<endl;
    cout<<"[6] Lethal Strike   (MP:800) (CP:150) (Power: 2000)"<<endl;
    cout<<"[7] Overpowered Lethal Strike (MP:1000) (CP:200) (Power:2500)"<<endl;
    cout<<"[8] SUPER MEGA ATTACK   (MP:1000) (CP:300) (Power:4000)"<<endl;

    char skillselection;
    cin>>skillselection;
	cin.get();


    if(skillselection=='1')

    isover = damagecalculate(enemy,"Normal Attack",0,0,0);



    else if(skillselection=='2') {

    if(mp<100) {
        cout<<"\n\n-\aYou dont have enough MP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
        attack(enemy);
		return;
    }


    isover = damagecalculate(enemy,"Strike",100,100,0);

    }




    else if(skillselection=='3') {

    if(mp<200) {
        cout<<"\n\n-\aYou dont have enough MP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
        attack(enemy);
		return;
    }



    isover = damagecalculate(enemy,"Medium Strike",180,200,0);
    }




    else if(skillselection=='4') {

    if(mp<400) {
        cout<<"\n\n-\aYou dont have enough MP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
        attack(enemy);
		return;
    }


    isover = damagecalculate(enemy,"Deadly Strike",320,400,0);

    }



    else if(skillselection=='5') {

    if(cp<100) {
        cout<<"\n\n-\aYou dont have enough CP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
        attack(enemy);
		return;
    }

   else if(mp<400) {
       cout<<"\n\n-\aYou dont have enough MP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
       attack(enemy);
	   return;
   }



    isover = damagecalculate(enemy,"Overpowered Deadly Strike",1500,400,100);

    }





    else if(skillselection=='6') {


    if(cp<150) {
        cout<<"\n\n-\aYou dont have enough CP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
        attack(enemy);
		return;
    }

    else if(mp<800) {
        cout<<"\n\n-\aYou dont have enough MP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
        attack(enemy);
		return;
    }



    isover = damagecalculate(enemy,"Lethal Strike",2000,800,150);

    }



    else if(skillselection=='7') {

   if(cp<200) {
       cout<<"\n\n-\aYou dont have enough CP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
       attack(enemy);
	   return;
   }

   else if(mp<1000) {
       cout<<"\n\n-\aYou dont have enough MP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
       attack(enemy);
	   return;
   }


    isover = damagecalculate(enemy,"Overpowered Lethal Strike",2500,1000,200);

    }




    else if(skillselection=='8') {

    if(cp<300) {
        cout<<"\n\n-\aYou dont have enough CP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
        attack(enemy);
		return;
    }

    else if(mp<1000) {
        cout<<"\n\n-\aYou dont have enough MP for this skill!"<<endl;
clock_t begin = clock();
clock_t delay = 1 * CLOCKS_PER_SEC;
while ((clock() - begin) < delay);
        attack(enemy);
		return;
    }

    isover = damagecalculate(enemy,"SUPER MEGA ATTACK",4000,1000,300);

    }

    else {
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
    attack(enemy);
	return;
    }

    if(isover==false)


        enemy.attack(*this);



}
}


///

short unit::gearupgrade_dialog(const string itemname,const string statname, short statlevel, short gearlevel,short increase_amount,short action){
	//action : 1-> purchase
	//		   2-> upgrade

	unsigned long cost = 98 * statlevel + ( gearlevel * 2);

	if (action == 1)
		cout << "\n\nThe cost for upgrading your " << itemname << " is " << cost << " gold." << endl;
	else
		cout << "\n\nThe cost for purchasing a " << itemname << " is " << cost << " gold." << endl;
	cout << "GOLD : " << gold << endl;
	if (gold<cost) {
		cout << "\n--You dont have enough gold--" << endl;
		cout << "Press Enter to proceed" << endl;
		cin.get();
		return 0;
	}
	cout << "Proceed with the upgrade? <y/n>" << endl;
	string proceed;
	getline(cin, proceed);

	if (proceed[0] == 'y') {

		gold -= cost;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYour " << statname << " has increased by " << increase_amount << endl;
		cout << "Press Enter to continue" << endl;
		cin.get();

		return 1;
	}

	else{
		return 0;
	}


}
void unit::gearupgrade() {


    cout<<"\n\n\n\n\n\n\n\n\n\n\nWelcome to the equipment store!"<<endl;
	cout<<" \n---Your Gold--- : "<<gold<<endl<<endl;
	cout << "\n1.Helmet  (increases hp by 50) : Current cost : " << (98 * helmetlevel + (gearlevel * 2))<<endl;
	cout << "\n2.Body Armor  (increases pdef by 50) : Current cost : " << (98 * armorlevel + (gearlevel * 2) )<< endl;
	cout << "\n3.Boots  (increase evasion by 1) : Current cost : " << (98 * bootslevel + (gearlevel * 2)) << endl;
	cout << "\n4.Training Manual (increase accuracy by 1) : Current cost : " << (98 * trmlevel + (gearlevel * 2)) << endl;
	cout << "\n5.Jewelry  (increase m.resist by 50) : Current cost : " << (98 * jewelslevel + (gearlevel * 2)) << endl;
	cout << "\n6.Weapon  (increases attackpower by 50) : Current cost : " << (98 * weaponlevel + (gearlevel * 2)) << endl;
	cout << "\n7.Shield  (increases block by 1,only for warriors) : Current cost : " << (98 * shieldlevel + (gearlevel * 2)) << endl;
	cout << "\n8.Lucky Token (increases luck by 1) : Current cost : "  <<"300 (fixed)"<< endl;
    cout<<"\n9.Exit"<<endl;


    string selection;
    getline(cin,selection);
//

    if(selection[0]=='9')
    return;

    else if(selection[0]=='1') {

		if (gearupgrade_dialog("helmet","maximum hp", helmetlevel, gearlevel,50,1)){
			maxhp += 50;
			hp = maxhp;
			helmetlevel++;
			gearlevel++;
			gearupgrade();
			return;
		}
		else{
			gearupgrade();
			return;
		}


    }

//
    else if(selection[0]=='2') {

		if (gearupgrade_dialog("armor", "pdef", armorlevel, gearlevel, 50,1)){
			pdef += 50;
			armorlevel++;
			gearlevel++;
			gearupgrade();
			return;
		}
		else{
			gearupgrade();
			return;
		}
		
}

//
   else if(selection[0]=='3') {

	   if (gearupgrade_dialog("boots", "evasion", bootslevel, gearlevel, 1,1)){
		   evasion += 1;
		   bootslevel++;
		   gearlevel++;
		   gearupgrade();
		   return;
	   }
	   else{
		   gearupgrade();
		   return;
	   }

   }

//
   else if (selection[0] == '4') {

	   if (gearupgrade_dialog("training manual", "accuracy", trmlevel, gearlevel, 1, 2)){
		   accuracy += 1;
		   trmlevel++;
		   gearlevel++;
		   gearupgrade();
		   return;
	   }

	   else{
		   gearupgrade();
		   return;
		}
	   
   }

//
   else if(selection[0]=='5') {

	   if (gearupgrade_dialog("jewels", "mresist", jewelslevel, gearlevel, 50, 1)){
		   m_resist += 50;
		   jewelslevel++;
		   gearlevel++;
		   gearupgrade();
		   return;
	   }

	   else{
		   gearupgrade();
		   return;
	   }

   }


   else if(selection[0]=='6') {

	   if (gearupgrade_dialog("weapon", "attackpower", weaponlevel, gearlevel, 50, 1)){
		   attackpower += 50;
		   weaponlevel++;
		   gearlevel++;
		   gearupgrade();
		   return;
	   }

	   else{
		   gearupgrade();
		   return;
	   }
		

   }

   else if (selection[0] == '8'){

	   cout << "The cost is 300 gold (fixed)" << endl;
	   if (gold<300) {
		   cout << "\n--You dont have enough gold--" << endl;
		   cout << "Press Enter to proceed" << endl;
		   cin.get();
		   gearupgrade();
		   return;
	   }
	   cout << "Proceed with the upgrade? <y/n>" << endl;
	   string tokenproceed;
	   getline(cin, tokenproceed);
	   if (tokenproceed[0] == 'y'){
		   if (luck < 100){
			   luck++;
			   gold = gold - 300;
			   cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYour Luck has increased by 1" << endl;
		   }
		   else
			   message_for_statlimit("Luck", 100);
	   }

   }


   else if(selection[0]=='7') {


if(playerclass != "Warrior") {

           cout<<"\n\nYou must be a warrior to make this upgrade!"<<endl;
           cout<<"Press Enter to continue.."<<endl;
           cin.get();
           cout<<"\n\n"<<endl;
		   gearupgrade();
		   return;
       }



       unsigned long shieldcost = 98 * shieldlevel + (gearlevel * 2);

       cout<<"\n\nThe cost for upgrading your shield is "<<shieldcost<<" gold"<<endl;
       cout<<"GOLD : "<<gold<<endl;

       if(gold<shieldcost) {

           cout<<"\n--You dont have enough gold--"<<endl;
           cout<<"Press Enter to proceed"<<endl;
           cin.get();
		   gearupgrade();
		   return;
       }

       cout<<"Proceed with the upgrade? <y/n>"<<endl;
       string shieldproceed;
       getline(cin,shieldproceed);

       if(shieldproceed[0]=='y') {

		   if (block < 100){
			   gold -= shieldcost;

			   shieldlevel++;
			   gearlevel++;
			   cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYour block has increased by 1" << endl;
			   cout << "Press Enter to continue" << endl;

			   cin.get();
			   block++;
		   }
		   else
			   message_for_statlimit("Block", 100);

		   gearupgrade();
		   return;
       }


	   else{
		   gearupgrade();
		   return;
	   }

   }



}
///

void unit::mob_attacks(unit& player) {

    cout<<"\n\n\n\n\n\n\n\n\n\nYou are under attack!"<<endl;
    cout<<"\n\nAttacker info : "<<endl;
    cout<<"\n\n";
	if (is_final_boss)
		cout << "*** F I N A L   B O S S ***" << endl << endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Level : "<<level<<endl;
    cout<<"HP   : "<<maxhp<<endl;
    cout<<"MP   : "<<mp<<endl;
	cout << "Class : " << playerclass << endl;
	if (!isboss){
		cout << "Strengths : " << str << endl;
		cout << "Weaknesses : " << weak << endl;
	}


    cout<<"\n\nWhat do you want to do?"<<endl;
    cout<<"1.Fight"<<endl;
	if (!isboss)
		cout << "2.Escape (25% CP loss) -> You have " <<player.cp<<" CP" <<endl;
	else
		cout << "2.Escape (No penalty)" << endl;

    string fightescape;

    getline(cin,fightescape);


    if(fightescape[0]=='2') {
		if (!isboss){
			double cploss = player.cp / 4.0;
			cploss = int(cploss);
			player.cp = player.cp - cploss;
			cout << endl << "You lost " << cploss << " CP" << endl;
			cout<<"You now have "<<player.cp<<" CP"<<endl;
			cout << "Press Enter to continue" << endl;
			cin.get();

		}
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
        return;
    }
    else {

        cout<<"\n\n\n"<<endl;
        player.attack(*this);

    }


}

///
short unit::zoneselection_errormessage(int x) {

    if(level<x) {
    cout<<"\n\n\n\n\n\n"<<endl;
    cout<<"\a\n\n---Your level is not high enough to enter this zone!---"<<endl<<endl;
    cout<<"\nPress Enter to continue"<<endl;
    cin.get();
    return 1;
    }

return 0;

}
void unit::zoneselection() {


	cout << "\n\n\n\n\n\n\n\n\n" << endl;
    cout<<"\n\n--PLAYER INTERFACE--";
    cout<<"  (Input 'x' to exit)"<<endl;
    cout<<"\n-Input 'c' to view your character's statistics and info"<<endl;
    cout<<"\n-Input 'u' or 'b' to upgrade your equipment"<<endl;
	cout << "\n-Input 'i' to view your inventory" << endl;
    cout<<"\n-Input 's' to save your character data"<<endl;
    cout<<"\n** Difficulty level : "<<game_difficulty<<" **"<<endl;
    cout<<"\n------------------------------------------------------------------------"<<endl;
    cout<<"*Your level : "<<level<<"     *Name : "<<name<<"     *Class : "<<playerclass<<"     GOLD : "<<gold<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"\n-ZONE SELECTION-"<<endl;
    cout<<"1.Plains"<<endl;
    cout<<"2.Forest                    (Minimum required level : 5)"<<endl;
    cout<<"3.Cave                      (Minimum required level : 10)"<<endl;
    cout<<"4.Graveyard                 (Minimum required level : 15)"<<endl;
    cout<<"5.Dark Dimension            (Minimum required level : 20)"<<endl;
	if (!zone6defeated)
		cout<<"6.Plains : BOSS             (Minimum required level : 25)"<<endl;
	else
		cout << "6.Plains : BOSS [DEFEATED]   (Minimum required level : 25)" << endl;
	if (!zone7defeated)
		cout<<"7.Forest : BOSS             (Minimum required level : 30)"<<endl;
	else
		cout << "7.Forest : BOSS [DEFEATED]  (Minimum required level : 30)" << endl;
	if (!zone8defeated)
		cout<<"8.Cave   : BOSS             (Minimum required level : 35)"<<endl;
	else
		cout << "8.Cave   : BOSS [DEFEATED]   (Minimum required level : 35)" << endl;
	if (!zone9defeated)
		 cout<<"9.Graveyard : BOSS          (Minimum required level : 40)"<<endl;
	else
		cout << "9.Graveyard : BOSS [DEFEATED]   (Minimum required level : 40)" << endl;
	if (!zone10defeated)
	  cout<<"10.Dark Dimension : BOSS    (Minimum required level : 50)"<<endl;
	else
		cout << "10.Dark Dimension : BOSS [DEFEATED]    (Minimum required level : 50)" << endl;

string zoneselect;

getline(cin,zoneselect);

 if(zoneselect=="10") {

    short error=zoneselection_errormessage(50);
	if (error == 1){
		zoneselection();
		return;
	}


	bool zone_10_condition = zone6defeated && zone7defeated && zone8defeated && zone9defeated;
	if (!zone_10_condition){
		errormessage_bosses();
		zoneselection();
		return;
	}

    unit mob;
    cout<<"\nProceeding to Dark Dimension Raid Boss..."<<endl;
    clock_t begin = clock();
    clock_t delay = 1 * CLOCKS_PER_SEC;
    while(clock() - begin < delay);
    cout<<"\n\n\n"<<endl;
    mob.create_mob(10);
    mob.mob_attacks(*this);
	zoneselection();
	return;
}




else if(zoneselect[0] == '1' ) {

    unit mob;
    cout<<"\nProceeding to Plains..."<<endl;
    clock_t begin = clock();
    clock_t delay = 0.5 * CLOCKS_PER_SEC;
    while(clock() - begin < delay);
    cout<<"\n\n\n"<<endl;
    mob.create_mob(1);
    mob.mob_attacks(*this);
	zoneselection();
	return;
}

else if(zoneselect[0]=='2') {

    short error = zoneselection_errormessage(5);
    if(error==1){
      zoneselection();
      return;
    }


    unit mob;
    cout<<"\nProceeding to Forest..."<<endl;
    clock_t begin = clock();
    clock_t delay = 0.5 * CLOCKS_PER_SEC;
    while(clock() - begin < delay);
    mob.create_mob(2);;
    mob.mob_attacks(*this);
   zoneselection();
   return;

}

else if(zoneselect[0]=='3') {

    short error =zoneselection_errormessage(10);
    if(error==1){
      zoneselection();
      return;
  }

    unit mob;
    cout<<"\nProceeding to Cave..."<<endl;
    clock_t begin = clock();
    clock_t delay = 0.5 * CLOCKS_PER_SEC;
    while(clock() - begin < delay);
    mob.create_mob(3);
    mob.mob_attacks(*this);
    zoneselection();
    return;

}

else if(zoneselect[0]=='4') {

    short error=zoneselection_errormessage(15);
    if(error==1){
     zoneselection();
     return;
  }

    unit mob;
    cout<<"\nProceeding to Graveyard..."<<endl;
    clock_t begin = clock();
    clock_t delay = 0.5 * CLOCKS_PER_SEC;
    while(clock() - begin < delay);
    mob.create_mob(4);
    mob.mob_attacks(*this);
    zoneselection();
    return;

}

else if(zoneselect[0]=='5') {

    short error=zoneselection_errormessage(20);
    if(error==1){
      zoneselection();
      return;
  }

    unit mob;
    cout<<"\nProceeding to Dark Dimension..."<<endl;
    clock_t begin = clock();
    clock_t delay = 0.5 * CLOCKS_PER_SEC;
    while(clock() - begin < delay);
    mob.create_mob(5);
    mob.mob_attacks(*this);
    zoneselection();
    return;
}

else if(zoneselect[0]=='6') {

    short error=zoneselection_errormessage(25);
    if(error==1){
    zoneselection();
    return;
  }

    unit mob;
    cout<<"\nProceeding to Plains Raid Boss..."<<endl;
    clock_t begin = clock();
    clock_t delay = 0.5 * CLOCKS_PER_SEC;
    while(clock() - begin < delay);
    mob.create_mob(6);
    mob.mob_attacks(*this);
    zoneselection();
    return;
}



else if(zoneselect[0]=='7') {

    short error=zoneselection_errormessage(30);
    if(error==1){
      zoneselection();
      return;
  }

	bool zone7condition = zone6defeated;
	if (!zone7condition){
		errormessage_bosses();
		zoneselection();
		return;
	}

    unit mob;
    cout<<"\nProceeding to Forest Raid Boss..."<<endl;
    clock_t begin = clock();
    clock_t delay = 0.5 * CLOCKS_PER_SEC;
    while(clock() - begin < delay);
    mob.create_mob(7);
    mob.mob_attacks(*this);
    zoneselection();
    return;
}

else if(zoneselect[0]=='8') {

    short error=zoneselection_errormessage(35);
    if(error==1){
      zoneselection();
      return;
  }

	bool zone8condition = zone6defeated && zone7defeated;
	if (!zone8condition){
		errormessage_bosses();
		zoneselection();
		return;
	}
    unit mob;
    cout<<"\nProceeding to Cave Raid Boss..."<<endl;
    clock_t begin = clock();
    clock_t delay = 0.5 * CLOCKS_PER_SEC;
    while(clock() - begin < delay);
    mob.create_mob(8);
    mob.mob_attacks(*this);
    zoneselection();
    return;
}

else if(zoneselect[0]=='9') {

    short error=zoneselection_errormessage(40);
    if(error==1){
      zoneselection();
      return;
  }

	bool zone9condition = zone6defeated && zone7defeated && zone8defeated;
	if (!zone9condition){
		errormessage_bosses();
		zoneselection();
		return;
	}
    unit mob;
    cout<<"\nProceeding to Graveyard Raid Boss..."<<endl;
    clock_t begin = clock();
    clock_t delay = 0.5 * CLOCKS_PER_SEC;
    while(clock() - begin < delay);
    mob.create_mob(9);
    mob.mob_attacks(*this);
    zoneselection();
    return;
}

else if(zoneselect[0]=='s'){
	save_load('s');
	zoneselection();
}

else if(zoneselect[0]=='x')
    return;


else if(zoneselect[0]=='c') {
showstats();
zoneselection();
return;
}


else if(zoneselect[0]=='u' || zoneselect[0]=='b') {

gearupgrade();
zoneselection();
return;

}

else if (zoneselect[0] == 'i'){
	show_inventory();
	zoneselection();
	return;
}

else {

    cout<<"\n\n\n\n\n"<<endl;
    zoneselection();
    return;
}

}





void unit::charactercreation() {


	string classselection;

	do{
		cout << endl << endl << endl << endl;
		cout << "\n\n--Character class selection--" << endl << endl;
		cout << endl << "*MAGE*  \n-Magic type attack. \n-High damage output with high accuracy. \n-Protective Barrier : Survives lethal damage (with 1 hp remaining) once per\nbattle." << endl;
		cout << "*WARRIOR*  \n-Physical type attack. \n-High health and defence. \n-Has the 'block' stat enabled. 'Block' can reduce enemy damage." << endl;
		cout << endl << "*SCOUT*  \n-Physical type attack. \n-High critical rate and evasion. \n-Starts with 'luck' stat doubled. Scout's 'luck' stat increases with levelup\n(it normally doesnt)." << endl;
		cout << endl;
		cout << "*Input 'm' for mage" << endl;
		cout << "*Input 'w' for warrior" << endl;
		cout << "*Input 's' for scout" << endl;


		getline(cin, classselection);


		if (classselection[0] == 'w') {

			create_warrior();
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
      character_creation_msg("warrior");
      select_difficulty();
			return;

		}


		else if (classselection[0] == 'm') {

			create_mage();
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
      character_creation_msg("mage");
      select_difficulty();
			return;

		}


		else if (classselection[0] == 's') {

			create_scout();
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
      character_creation_msg("scout");
      select_difficulty();
			return;
		}

		else
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlease input a valid selection..." << endl << endl;
	} while (classselection[0] != 's' && classselection[0] != 'n' && classselection[0] != 'w');


}


void unit::itemdrop_check(){

	bool item_dropped;

	int itemdrop_no = rand() % 100 + 1;

	if (itemdrop_no <= luck)
		item_dropped = true;
	else
		item_dropped = false;

	if (item_dropped){
		//possible items: CP Potion, Lucky Charm, Rare Book (exp) , MAXMP Potion , Skill Potion , Precision Potion

		item dropped_item;
		int item_id_no = rand() % 6;

		if (item_id_no == 0){
			dropped_item.name = "CP Potion";
			dropped_item.related_stat = "cp";
			dropped_item.value = 15;
			dropped_item.description = "Increases CP by 15";
			items_owned.push_back(dropped_item);
		}
		else if (item_id_no == 1){
			dropped_item.name = "Lucky Charm";
			dropped_item.related_stat = "luck";
			dropped_item.value = 2;
			dropped_item.description = "Increases Luck by 2";
			items_owned.push_back(dropped_item);
		}
		else if (item_id_no == 2){
			dropped_item.name = "MAXMP Potion";
			dropped_item.related_stat = "maxmp";
			dropped_item.value = 500;
			dropped_item.description = "Increases Maximum MP by 500";
			items_owned.push_back(dropped_item);
		}
		else if(item_id_no == 3){
			dropped_item.name = "Rare Book";
			dropped_item.related_stat = "level";
			dropped_item.value = 1;
			dropped_item.description = "You level up!";
			items_owned.push_back(dropped_item);
		}
		else if (item_id_no == 4){
			dropped_item.name = "Skill Potion";
			dropped_item.related_stat = "skill";
			dropped_item.multiple_stats = true;
			dropped_item.stat_names.push_back("accuracy");
			dropped_item.stat_names.push_back("evasion");
			dropped_item.stat_names.push_back("critical rate");
			dropped_item.stat_names.push_back("parry");
			dropped_item.value = 1;
			dropped_item.description = "Increases Accuracy,Evasion,Crit rate and Parry by 1";
			items_owned.push_back(dropped_item);
		}
		else if (item_id_no == 5){
			dropped_item.name = "Precision Potion";
			dropped_item.related_stat = "accuracy";
			dropped_item.value = 2;
			dropped_item.description = "Increases Accuracy by 2";
			items_owned.push_back(dropped_item);
		}

		cout << endl << "*You found an item! ::: " << dropped_item.name;
		cout << endl << "Press Enter twice to continue" << endl;
		cin.get();
		cin.get();
		


	}
}
void unit::showstats() {

    cout<<"\n\n\n\n\n\n\n\n\n"<<endl;

    cout<<"\nEXPERIENCE"<<endl;

    cout<<"Level       - "<<level<<endl;
    cout<<"Current EXP - "<<current_exp<<endl;
    cout<<"EXP for next level - "<<levelup_exp<<endl;

    cout<<"\nMETERS    "<<endl;

    cout<<"HP - "<<maxhp<<endl;
    cout<<"MP - "<<mp<<endl;
    cout<<"CP - "<<cp<<endl;

    cout<<"\nOFFENSIVE "<<endl;

    cout<<"Attackpower - "<<attackpower<<endl;
    cout<<"Critical Rate  - "<<crit_rate<<endl;
    cout<<"Accuracy    - "<<accuracy<<endl;

    cout<<"\nDEFENSIVE "<<endl;

    cout<<"Physical Defense - "<<pdef<<endl;
    cout<<"Block       - "<<block<<endl;
    cout<<"Parry       - "<<parry<<endl;
    cout<<"Evasion     - "<<evasion<<endl;
    cout<<"Magic Resist - "<<m_resist<<endl;

    cout<<"\nMISC"<<endl;
    cout<<"Luck        - "<<luck<<endl;
	cout << "Gold        - " << gold << endl;
	cout << "Victories   - " << victories << endl;

    cout<<"\nPress Enter to continue"<<endl;
    cin.get();


}

void unit::use_item(item& used_item){

	if (used_item.related_stat == "cp")
		cp += used_item.value;
	else if (used_item.related_stat == "level"){
		levelup(true);

	}
	else if (used_item.related_stat == "luck"){
		if (luck < 100)
		luck += used_item.value;
		else
			message_for_statlimit("Luck", 100);
	}

	else if (used_item.related_stat == "maxmp"){
		maxmp += used_item.value;
		mp = maxmp;
	}

	else if (used_item.related_stat == "skill"){
		accuracy = accuracy + used_item.value;
		evasion = evasion+ used_item.value;
		if (parry < 100)
			parry = parry+ used_item.value;
		else 
			message_for_statlimit("Parry", 100);
		if (crit_rate < 100)
			crit_rate = crit_rate + used_item.value;
		else
			message_for_statlimit("Critical Rate", 100);

	}

	else if (used_item.related_stat == "accuracy"){
		accuracy += used_item.value;
	}

	if (used_item.multiple_stats == false)
		cout << endl << endl << used_item.related_stat << " increased by " << used_item.value <<"!"<< endl;
	else{
		cout << endl << endl;
		for (int x = 0; x < used_item.stat_names.size(); x++)
			cout << used_item.stat_names[x] << " ,";
		cout << " increased by " << used_item.value << "!" << endl;
	}
	cout << endl << "Press Enter to continue" << endl;
	cin.get();
	cin.get();
}

void unit::show_inventory(){

	cout << endl << endl;
	cout << "-----------------------------" << endl;
	cout << endl << name << " 's inventory :::" << endl << endl;
	if (items_owned.size() == 0){
		cout << "--Empty--" << endl;
	}

	else{
		for (int x = 0; x < items_owned.size(); x++){
			cout <<"["<< (x + 1) <<"]"<< " - - - ";
			cout << items_owned[x].name << " - - - " << items_owned[x].description << endl;
		}
	}

	char item_selection_c;
	cout << endl << "Input 0 to continue, or a corresponding number to select an item." << endl;
	do{
		cin >> item_selection_c;
	} while (isalpha(item_selection_c));

	int item_selection = int(item_selection_c) - '0';
	cout << item_selection;
	bool item_selected = false;
	for (int x = 0; x < items_owned.size(); x++){

		if (item_selection == x + 1){
			item_selection = x;
			item_selected = true;
		}
	}

	if (item_selected){
		item selected_item = items_owned[item_selection];
		cout << endl << "What do you want to do with this item?" << endl;
		cout << "1.Use" << endl;
		cout << "2.Sell (+300 gold)" << endl;
		cout << "3.Cancel" << endl;
		char whattodo;
		do{
			cin >> whattodo;
		} while (isalpha(whattodo));
		if (whattodo == '1')
			use_item(selected_item);
		else if (whattodo == '2')
			gold += 300;
		else
		{
			show_inventory();
			return;
		}
		items_owned.erase(items_owned.begin() + item_selection);
	}
	else{
		cin.get();
		return;
	}

}


int unit::save_load(char id,string file){

	ismob = false;

	if(id == 's'){

		cout<<endl;
		cout<<"Choose a name for the save file : (don't forget to include .txt!)"<<endl;
		string filename;
		getline(cin,filename);
		ofstream f;
		f.open(filename);
		f << name;
		f << '\n';
		f << game_difficulty;
		f << '\n';
		f<<level;
		f << '\n';
		f<<playerclass;
		f << '\n';
		f<<current_exp;
		f << '\n';
		f<<levelup_exp;
		f << '\n';
		f<<gearlevel;
		f << '\n';
		f<<helmetlevel;
		f << '\n';
		f<<armorlevel;
		f << '\n';
		f<<bootslevel;
		f << '\n';
		f<<jewelslevel;
		f << '\n';
		f<<weaponlevel;
		f << '\n';
		f<<shieldlevel;
		f << '\n';
		f<<victories;
		f << '\n';
		f<<gold;
		f << '\n';
		f<<maxhp;
		f << '\n';
		f<<hp;
		f << '\n';
		f<<maxmp;
		f << '\n';
		f<<mp;
		f << '\n';
		f<<cp;
		f << '\n';
		f<<attackpower;
		f << '\n';
		f<<crit_rate;
		f << '\n';
		f<<accuracy;
		f << '\n';
		f<<pdef;
		f << '\n';
		f<<block;
		f << '\n';
		f<<parry;
		f << '\n';
		f<<evasion;
		f << '\n';
		f<<m_resist;
		f << '\n';
		f<<luck;
		f << '\n';
		f<<protective_barrier;
		f << '\n';
		f << int(items_owned.size());
		f << '\n';
		for(int w=0;w<items_owned.size();w++){
			f<<items_owned[w].multiple_stats;
			f << '\n';
			f<<items_owned[w].related_stat;
			f << '\n';
			f<<items_owned[w].name;
			f << '\n';
			f<<items_owned[w].description;
			f << '\n';
			f<<items_owned[w].value;
			f << '\n';
			f << int(items_owned[w].stat_names.size());
			for (int z = 0; z < items_owned[w].stat_names.size(); z++){
				f << items_owned[w].stat_names[z];
				f << '\n';
			}
		}

		cout << endl << "Save complete." << endl;
		cout << "Press Enter to continue." << endl;
		cin.get();
		f.close();

	}

	else if (id == 'l'){

		ifstream f;
		f.open(file);
		if (!f){
			cout << "Error reading file! File does not exist,or pathname was wrong." << endl;
			return 1;

		}

		f >> name;
		f >> game_difficulty;
		f >> level;
		f >> playerclass;
		f >> current_exp;
		f >> levelup_exp;
		f >> gearlevel;
		f >> helmetlevel;
		f >> armorlevel;
		f >> bootslevel;
		f >> jewelslevel;
		f >> weaponlevel;
		f >> shieldlevel;
		f >> victories;
		f >> gold;
		f >> maxhp;
		f >> hp;
		f >> maxmp;
		f >> mp;
		f >> cp;
		f >> attackpower;
		f >> crit_rate;
		f >> accuracy;
		f >> pdef;
		f >> block;
		f >> parry;
		f >> evasion;
		f >> m_resist;
		f >> luck;
		f >> protective_barrier;
		int itemsownedsize;
		f >> itemsownedsize;
		for (int w = 0; w<itemsownedsize; w++){
			item new_item;
			f >> new_item.multiple_stats;
			f >> new_item.related_stat;
			f >> new_item.name;
			f >> new_item.description;
			f >> new_item.value;
			items_owned.push_back(new_item);
			int statnamessize;
			f >> statnamessize;
			for (int z = 0; z < statnamessize; z++){
				string new_name;
				f >> new_name;
				items_owned[w].stat_names.push_back(new_name);
			}
		}

		cout << endl << "Load complete." << endl;
		cout << "Press Enter to continue." << endl;
		cin.get();
		f.close();
		return 0;


	}

}
