#include<bits/stdc++.h>
using namespace std;

class Animal
{
protected:
	std::string Type;
	std::string Color;
public:
	Animal(const std::string&, const std::string&);
	virtual void Print() = 0;
	virtual ~Animal();
};

class Fish : public Animal
{
private:
	bool Osteichthyes;
public:
	Fish(const std::string&, const std::string&, bool);
	void Print();
	~Fish();
};

class Bird : public Animal
{
private:
	bool daytime;
public:
	Bird(const std::string&, const std::string&, bool);
	void Print();
	~Bird();
};

Animal::Animal(const std::string& type , const std::string& color)
{
	this ->Type = type;
	this ->Color = color;
}

void Animal::Print()
{
	std::cout << "type: " << Type << ", color: " << Color << std::endl;
}

Animal::~Animal()
{
	
}

Fish::Fish(const std::string& type, const std::string& color, bool is) : Animal(type, color)
{
	this ->Osteichthyes = is;
}

void Fish::Print()
{
	std::cout << "type: " << Type << ", color: " << Color << ", Osteichthyes: " << Osteichthyes << std::endl;
}

Fish::~Fish()
{
	
}

Bird::Bird(const std::string& type, const std::string& color, bool is) : Animal(type, color) 
{
	this ->daytime = is;
}

void Bird::Print()
{
	std::cout << "type: " << Type << ", color: " << Color << ", daytime: " << daytime << std::endl;
}

Bird::~Bird()
{
	
}

int main()
{
    Animal *animal;
    string type, color;
    bool Osteichthyes, daytime;
    cin >> type >> color >> Osteichthyes;
    Fish fish(type, color, Osteichthyes);
    fish.Print();
    animal = &fish;
    animal->Print();
    cin >> type >> color >> daytime;
    Bird bird(type, color, daytime);
    bird.Print();
    animal = &bird;
    animal->Print();
    return 0;
}
