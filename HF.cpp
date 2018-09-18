#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <string>
#include <algorithm>

struct hero
{
	std::vector<std::string> name =
								{
									"Hawk-eye",
									"Iron man",
									"Captain America",
									"Thor",
									"Gamora",
									"Groot",
									"Black widow",
									"Hulk",
									"Spider-man"
								};
};

struct action
{
	std::vector<std::string> discription = 
								{
									"throw shield to",//0
									"throw hammer to",//1
									"fight all day with",//2
									"finds out all secrets of",//3
									"fly's out from",//4
									"boxing with",//5
									"grab",//6
									"throw arrow in",//7
									"shock by electricity",//8
									"shot by gun",//9
									"run from",//10
									"run to",//11
									"throw web",//12
									"cross legs on shoulder of",//13
									"smash",//14
									"simply throw",//15
									"knock out",//16
									"cry because of",//17
									"fist punch",//18
									"send missiles to",//19
									"cut with blade",//20
									"kill",//21
									"talk to",
									"said <<I'm Groot>>",//23
									"punch by wood stick"
								};

	std::vector< std::vector<int> > exceptions
								{
									{5,6,7,9,10,11,17,18,20,21},
									{4,5,6,8,10,11,16,17,18,19,21},
									{0,2,5,6,9,10,11,16,17,18,21},
									{1,3,4,5,6,8,10,11,15,16,17,18,20,21},
									{3,4,5,8,9,10,11,13,17,18,20,21,22},
									{23,24,11,14,15,16,21},
									{3,5,9,10,11,13,16,17,18,21},
									{5,6,11,14,15,16,17,18,21},
									{3,4,5,8,10,11,12,17,18,21}
								};
};

struct villian
{
	std::vector<std::string> name = 
								{
									"Loki",
									"Cross bones",
									"Thanos",
									"Whiplach",
									"Altron",
									"Hella",
									"Silestial",
									"green Goblin",
									"Red Skull",
									"Mandarin"
								};
};

int main(){

	srand ( time(NULL) );

	int N = 9;
	int i, j, k;

	hero protagonist;
	action activity;
	villian antogonist;

	for (int x = 0; x < N; x++){

		std::cout << "\nFight #"<< x+1 <<".\n";

		i = rand() % protagonist.name.size();

		j = rand() % activity.exceptions[i].size();

		j = activity.exceptions[i][j];
		
		/*
		std::cout << "\nList heroes size = " << protagonist.name.size()
		<< ". List exceptions size = " << activity.exceptions.size()
		<< ". List villians size = " << antogonist.name.size() << ".\n";

		std::cout << "\nChoosed action: " << j << " in the list: " << i << ".\n";
		*/

		k = rand() % antogonist.name.size();

		std::cout << protagonist.name[i]
					<< ' ' << activity.discription[j]
					<< ' ' << antogonist.name[k]
					<< ".\n";

		if (j == 21){
			antogonist.name.erase( std::remove( antogonist.name.begin(),
			                                    antogonist.name.end(),
			                                    antogonist.name[k] ),
									antogonist.name.end() );				
		}

		protagonist.name.erase( std::remove( protagonist.name.begin(),
		                                    protagonist.name.end(),
		                                    protagonist.name[i] ),
								protagonist.name.end() );	
		activity.exceptions.erase( std::remove( activity.exceptions.begin(),
		                                    activity.exceptions.end(),
		                                    activity.exceptions[i] ),
								activity.exceptions.end() );

	}

	return 0;
}
