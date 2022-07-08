#include "service.h"

//modifica titlul/rank-ul unei melodii
void Service::modifica(int id, string titlu, int rank)
{
	Melodie melodie(id, titlu, "", rank);
	repo.modificaMelodie(melodie);
}

//sterge o melodie dupa id
void Service::stergere(int id)
{
	Melodie m(id, "", "", 0);
	repo.stergeMelodie(m);
}

//sorteaza melodiile dupa rank
vector<Melodie> Service::getAll()
{
	vector<Melodie> all = repo.getAll();
	sort(all.begin(), all.end(), [&](Melodie m1, Melodie m2) {
		return m1.getRank() < m2.getRank();
		});
	return all;
}

//returneaza numarul de melodii cu acelasi rank
int Service::filtrareRank(int rank)
{
	int nr = 0;
	vector<Melodie> all = repo.getAll();
	for (auto m : all)
		if (m.getRank() == rank)
			nr++;
	return nr;
}
