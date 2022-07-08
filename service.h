#pragma once
#include "repository.h"
#include <algorithm>

class Service {
private:
	Repository repo;
public:

	Service(Repository repo) : repo{ repo } {}

	//modifica titlu si/sau rank-ul unei melodii preluata dupa id 
	void modifica(int id, string titlu, int rank);

	//sterge o melodie dupa id-ul ei
	void stergere(int id);

	//vectorul ce contine toate melodiile
	vector<Melodie> getAll();

	int filtrareRank(int rank);
};