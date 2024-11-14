#include <iostream>
#include <vector>

class Account {
private:
	int _money = 0;
public:
	void AddMoney(int money) {
		_money += money;
	}
	void TakeMoney(int money) {
		_money -= money;

	}
	void ShowMoney() {
		std::cout << _money;
	}
};

class Client {
private:
	Account* _account = nullptr;
	std::string _name{};

public:
	Client(std::string name, int balance) {
		_account = new Account;
		_name = name;
		_account->AddMoney(balance);
	}

public:
	void ShowBalance() {
		_account->ShowMoney();
	}
	void Deposit(int money) {
		_account->AddMoney(money);
	}
	void WithDraw(int money) {
		_account->TakeMoney(money);
	}

public:
	void ShowName() {
		std::cout << _name;
	}
	void ChangeName(std::string name) {
		_name = name;
	}
};

class Bank {
private:
	std::vector<Client*> _clientBase{};

public:
	void addClient(Client* client) {
		_clientBase.push_back(client);
	}

	void removeClient(Client* client) {

		if (ClientSearch(client)) {
			std::erase(_clientBase, client);
		}

	}

	void TakeClientMoney(Client* client, int money) {

		if (ClientSearch(client)) {
			client->WithDraw(money);
		}
	}

	void AddClientMoney(Client* client, int money) {

		if (ClientSearch(client)) {
			client->Deposit(money);
		}
	}

	void ShowClientInfo(Client* client) {
		if (ClientSearch(client)) {
			client->ShowName();
			std::cout << ' ';
			client->ShowBalance();
			std::cout << '\n';
		}
	}

public:
	Client* ClientSearch(Client* client) {
		for (auto& t : _clientBase) {
			if (t == client) {
				return t;
			}
		}
		std::cout << "Can`t find client";
		return nullptr;

	}
};


int main() {

	Client* client = new Client{ "Tom",2000 };
	Client* client1 = new Client{ "Kate",100 };

	Bank* sber = new Bank;
	sber->addClient(client);

	sber->ShowClientInfo(client);
	sber->TakeClientMoney(client, 200);
	sber->ShowClientInfo(client);
	client->Deposit(1000);
	sber->ShowClientInfo(client);

	sber->ShowClientInfo(client1);


}