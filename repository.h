#pragma once
#include "entities.h"
#include <vector>

using namespace std;

class Repository {
private:
	vector<Melodie> melodii;
	string filename;
	void loadFromFile();
	void writeToFile();
public:
	//filename-fisierul din care se citesc si in care se scriu date
	Repository(string filename) : filename{ filename } { loadFromFile(); }

	//modifica titlu sau/si rank-ul unei melodii
	void  modificaMelodie(Melodie m);

	//stergerea unei melodii
	void stergeMelodie(Melodie m);

	//lista totala de melodii
	vector<Melodie> getAll();

};