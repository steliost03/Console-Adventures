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



#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;


void character_creation_msg(string);
void select_difficulty();
void main_menu();
void message_for_statlimit(string stat);
void errormessage_bosses();


struct item {

	bool multiple_stats = false;
	string related_stat;
	string name;
	string description;
	int value;
	std::vector<string> stat_names; //multiple stats.
	//std::vector<int> stat_values
};

//Class,member functions,data members//
class unit {

    private:

    ///CLASS///

    string playerclass;
    string name;
    bool ismob;
	bool isboss = false;
	short zone_id;
	bool is_final_boss = false;
	string str = "";
	string weak = "";

    ///LEVEL RELATED///

    int level;
    int current_exp;
    int levelup_exp;

    short gearlevel;
    short helmetlevel;
    short armorlevel;
    short bootslevel;
	short trmlevel;
    short jewelslevel;
    short weaponlevel;
    short shieldlevel;


    ///MISC///

    unsigned long gold;
    short victories;
	
	//BOSSES//
	bool zone6defeated = false;
	bool zone7defeated = false;
	bool zone8defeated = false;
	bool zone9defeated = false;
	bool zone10defeated = false;
	
    ///METERS///

    long double maxhp;
    long double hp;
    long double mp;
    long double maxmp;
    unsigned int cp;

    ///STATS///

    //PHYSICAL//
    int attackpower;
    int crit_rate;
    int accuracy;


    int pdef;
    int block;
    int parry;
    int evasion;

    //MAGIC//

   int m_resist;

   //OTHER//

   int luck;
   bool protective_barrier = false;

   //ITEMS//
   std::vector<item> items_owned;


    public:

    void charactercreation();
    void create_warrior();
    void create_mage();
    void create_scout();

    void create_mob(short);

    void levelup(bool fromitem = false);

	void attack(unit&);

    bool damagecalculate(unit&,const string&,const long,const short,const short);

    void endbattle(unit&);

    void gameover();

    void gearupgrade();

	short gearupgrade_dialog(const string,const string,short,short,short,short);

    void showmeters(unit&);

    void zoneselection();

    short zoneselection_errormessage(int);

    void mob_attacks(unit&);

    void showstats();

	void itemdrop_check();

	void show_inventory();

	void use_item(item&);

	int save_load(char,string file = "");


};



#endif
