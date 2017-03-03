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
#include <ctime>
#include <cstdlib>
using namespace std;



int main() {


    cout<<"---Console Adventures---"<<endl;


	string firstinput;
    do {
    cout<<"Input 5 to start the game."<<endl;
	cout << "(Fullscreen recommended)" << endl;

    getline(cin,firstinput);
    }
    while(firstinput!="5");

	main_menu(); 

 

}
