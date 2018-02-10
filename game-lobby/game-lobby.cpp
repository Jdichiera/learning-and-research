// Filename     : game-lobby.cpp
// Author       : Jeramy Dichiera
// Created      : 07/24/2017
// Description  : A simple menu game lobby

#include <iostream>
#include <cstdlib>
#include <string>

class Player
{
public:
	Player(const std::string& name = "");
	std::string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);

private:
	std::string m_Name;
	Player* m_pNext;  //Pointer to next player in list
};

Player::Player(const std::string& name) :
	m_Name(name),
	m_pNext(0)
{}

std::string Player::GetName() const
{
	return m_Name;
}

Player* Player::GetNext() const
{
	return m_pNext;
}

void Player::SetNext(Player* next)
{
	m_pNext = next;
}

class Lobby
{
	friend std::ostream& operator<<(std::ostream& os, const Lobby& aLobby);

public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();
	bool CheckEmpty();

private:
	Player* m_pHead;
};

Lobby::Lobby() :
	m_pHead(0)
{}

Lobby::~Lobby()
{
	Clear();
}


std::ostream& operator<<(std::ostream& os, const Lobby& aLobby)
{
	Player* pIter = aLobby.m_pHead;

	os << "\nHere's who's in the game lobby:\n";
	if (pIter == 0)
	{
		os << "The lobby is empty.\n";
	}
	else
	{
		while (pIter != 0)
		{
			os << pIter->GetName() << std::endl;
			pIter = pIter->GetNext();
		}
	}

	return os;
}


void Lobby::AddPlayer()
{
	//create a new player node
	std::cout << "Please enter the name of the new player: ";
	std::string name;
	std::cin >> name;
	Player* pNewPlayer = new Player(name);

	//if list is empty, make head of list this new player
	if (this->CheckEmpty())
	{
		m_pHead = pNewPlayer;
	}
	//otherwise find the end of the list and add the player there
	else
	{
		Player* pIter = m_pHead;
		while (pIter->GetNext() != 0)
		{
			pIter = pIter->GetNext();
		}
		pIter->SetNext(pNewPlayer);
	}
}

 void Lobby::RemovePlayer()
 {
	 // If the lobby is currently empty, we cant kick anyone.
	 if (this->CheckEmpty()) {
		 std::cout << "No one in the lobby to remove ..." << std::endl;
		 return;
	 }
	Player* firstPlayer = this->m_pHead;
	Player* newHead;
	// If the next player object is null, that means we only have one player in the lobby
	// We need to set the head to null before we remove the player.
	if (firstPlayer->GetNext() == NULL) {
		std::cout << "Removing last player ... " << std::endl;
		this->m_pHead = NULL;
		delete firstPlayer;
		return;
	}

	// If the current head is not null, and there are multiple folks in the lobby, then
	// we can set the lobby head to the next player, remove the current player, and return
	// to the lobby.
	this->m_pHead = firstPlayer->GetNext();
	newHead = this->m_pHead;
	std::cout << "---Removing player: " << firstPlayer->GetName() << " from the lobby ... " << std::endl;
	delete firstPlayer;

	// Leaving this commented out because it does not make sense to clear the whole lobby
	// when we are trying to remove just one person.
	//Clear();
 }

 void Lobby::Clear()
 {
	 // If the lobby is currently empty, we cant kick anyone.
	 if (this->CheckEmpty()) {
		 std::cout << "The lobby is already clear ..." << std::endl;
		 return;
	 }

	 Player* player = this->m_pHead;
	 // If the lobby is not clear, then remove all players.
	 while(!this->CheckEmpty()) {
		 this->m_pHead = player->GetNext();
		 delete player;
		 player = this->m_pHead;
	 }
 }

 bool Lobby::CheckEmpty() {
	 return this->m_pHead == 0;
}

void main() {
	Lobby myLobby;
	int choice;

	do
	{
		std::cout << myLobby;

		std::cout << "\n\n\t --== Game Lobby ==--\n";
		std::cout << "0 - Exit the program.\n";
		std::cout << "1 - Add a player to the lobby.\n";
		std::cout << "2 - Remove a player from the lobby.\n";
		std::cout << "3 - Clear the lobby.\n";
		std::cout << std::endl << "Enter choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 0: std::cout << "Good-bye.\n"; break;
		case 1: myLobby.AddPlayer(); break;
		case 2: myLobby.RemovePlayer(); break;
		case 3: myLobby.Clear(); break;
		default: std::cout << "That was not a valid choice.\n";
		}
	} while (choice != 0);
}