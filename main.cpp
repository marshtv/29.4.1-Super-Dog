#include <iostream>
#include <string>
#include <vector>

class Talent {
public:
	virtual void showTalent() = 0;
};

class Dancing : virtual public Talent {
public:
	virtual void showTalent() {
		std::cout << "\t\tIt can dancing!" << std::endl;
	}
};

class Swimming : virtual public Talent {
public:
	virtual void showTalent() {
		std::cout << "\t\tIt can swimming!" << std::endl;
	}
};

class Counting : virtual public Talent {
public:
	virtual void showTalent() {
		std::cout << "\t\tIt can counting!" << std::endl;
	}
};

class Singing : virtual public Talent {
public:
	virtual void showTalent() {
		std::cout << "\t\tIt can singing!" << std::endl;
	}
};

class Dod {
private:
	std::string name;
	std::vector<Talent*> talents;
public:
	Dod(std::string in_name) {
		this->name = in_name;
	}

	void setName(std::string in_name) {
		this->name = in_name;
	}

	std::string getName() {
		return this->name;
	}

	void addTalent(Talent* in_talent) {
		this->talents.push_back(in_talent);
	}

	int getTalentsNum() {
		return (int)this->talents.size();
	}

	Talent* showTalentAt(int in_count) {
		if (!this->talents.empty())
			this->talents[in_count]->showTalent();
		else
			std::cout << "No talents." << std::endl;
	}
};

int main() {
	Dod superDog("Steve");
	superDog.addTalent(new Dancing());
	superDog.addTalent(new Swimming());
	superDog.addTalent(new Counting());
	superDog.addTalent(new Singing());
	std::cout 	<< "This is " << superDog.getName() << " and it has "
				<< superDog.getTalentsNum() << " talents:" << std::endl;
	for (int i = 0; i < superDog.getTalentsNum(); ++i) {
		superDog.showTalentAt(i);
	}

	return 0;
}
