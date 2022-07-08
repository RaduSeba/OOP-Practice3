#include "repository.h"
#include <fstream>

//citeste date din fisier
void Repository::loadFromFile()
{
	ifstream fin(filename);
	melodii.clear();
	int id, rank;
	string line, titlu, artist;
	while (getline(fin, line))
	{
		size_t poz = line.find_first_of(",");
		id = stoi(line.substr(0, poz));
		line = line.substr(poz + 1, line.length());

		poz = line.find_first_of(",");
		titlu = line.substr(0, poz);
		line = line.substr(poz + 1, line.length());

		poz = line.find_first_of(",");
		artist = line.substr(0, poz);
		line = line.substr(poz + 1, line.length());

		rank = stoi(line);

		Melodie melodie(id, titlu, artist, rank);
		melodii.push_back(melodie);
	}
	fin.close();
}

//scrie in fisier
void Repository::writeToFile()
{
	ofstream fout(filename);
	for (auto m : melodii)
	{
		fout << m.getId() << "," << m.getTitlu() << "," << m.getArtist() << "," << m.getRank() << "\n";
	}
	fout.close();
}

//modifica titlul/rank-ul unei melodii
void Repository::modificaMelodie(Melodie m)
{
	for (auto& melodie : melodii)
	{
		if (melodie.getId() == m.getId())
		{
			melodie.setTitlu(m.getTitlu());
			melodie.setRank(m.getRank());
			writeToFile();
		}
	}
}

//sterge o melodie
void Repository::stergeMelodie(Melodie m)
{
	int i = 0;
	for (auto& melodie : melodii)
	{
		if (melodie.getId() == m.getId())
			break;
		i++;
	}
	melodii.erase(melodii.begin() + i);
	writeToFile();
}

//returneaza toate melodiile
vector<Melodie> Repository::getAll()
{
	return melodii;;
}
