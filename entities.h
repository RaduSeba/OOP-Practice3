#pragma once
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Melodie {
private:
	int id, rank;
	string titlu, artist;
public:
	/// <summary>
	///		
	/// </summary>
	/// <param name="id">
	///		id-ul melodiei
	/// </param>
	/// <param name="titlu">
	///		titlul melodiei
	/// </param>
	/// <param name="artist">
	///		artistul melodiei
	/// </param>
	/// <param name="rank">
	///		rank-ul melodiei
	/// </param>
	Melodie(int id, string titlu, string artist, int rank) : id{ id }, titlu{ titlu }, artist{ artist }, rank{ rank }{};
	//returneaza id-ul melodiei
	int getId() {
		return id;
	}
	//returneaza titlul melodiei
	string getTitlu() {
		return titlu;
	}
	//returneaza artistul melodiei
	string getArtist() {
		return artist;
	}
	//returneaza rank-ul melodiei
	int getRank() {
		return rank;
	}
	//modifica titlul melodiei
	void setTitlu(string titlu_nou) {
		this->titlu = titlu_nou;
	}
	//modifica rank-ul melodiei
	void setRank(int newRank) {
		this->rank = newRank;
	}

	//functie de test pentru gettere si settere
	void testGS()
	{
		Melodie m1{ 1, "titlu", "artist", 10 };
		assert(m1.getId() == 1);
		assert(m1.getTitlu() == "titlu");
		assert(m1.getArtist() == "artist");
		assert(m1.getRank() == 10);
		m1.setTitlu("titlu nou");
		assert(m1.getTitlu() == "titlu nou");
		m1.setRank(11);
		assert(m1.getRank() == 11);

	}
};