#include <iostream>
#include <map>
#include <string>
using namespace std;

class Unit abstract {
protected:
	int speed;
	int power;
public:
	virtual void Show(const string& pos)=0;
};
class LightInfantry : public Unit {
public:
	LightInfantry() {
		speed = 20;
		power = 10;
	}
	void Show(const string& pos)override {
		cout << "Light Infantry at pos: " << pos << ", speed: " << speed << ", powerK: " << power << endl;
	}
};
class Transport : public Unit {
public:
	Transport() {
		speed = 70;
		power = 0;
	}
	void Show(const string& pos)override {
		cout << "Transport at pos: " << pos << ", speed: " << speed << ", powerK: " << power << endl;
	}
};
class HeavyTechnic : public Unit {
public:
	HeavyTechnic() {
		speed = 15;
		power = 150;
	}
	void Show(const string& pos)override {
		cout << "Heavy Technic at pos: " << pos << ", speed: " << speed << ", powerK: " << power << endl;
	}
};
class LightTechnic : public Unit {
public:
	LightTechnic() {
		speed = 50;
		power = 30;
	}
	void Show(const string& pos)override {
		cout << "Light Technic at pos: " << pos << ", speed: " << speed << ", powerK: " << power << endl;
	}
};
class AirTechnic : public Unit {
public:
	AirTechnic() {
		speed = 20;
		power = 10;
	}
	void Show(const string& pos)override {
		cout << "Air Technic at pos: " << pos << ", speed: " << speed << ", powerK: " << power << endl;
	}
};
class UnitFactory {
	map<string, Unit*> units;
public:
	UnitFactory() {
		units["LightInfantry"] = new LightInfantry();
		units["Transport"] = new Transport();
		units["HeavyTechnic"] = new HeavyTechnic();
		units["LightTechnic"] = new LightTechnic();
		units["AirTechnic"] = new AirTechnic();
	}
	~UnitFactory()
	{
		delete units["LightInfantry"];
		delete units["Transport"];
		delete units["HeavyTechnic"];
		delete units["LightTechnic"];
		delete units["AirTechnic"];
		units.clear();
	}
	Unit* GetUnit(string key)
	{
		if (units[key] != nullptr)
			return units[key];
		else
			return nullptr;
	}
};

int main()
{
	/*
	 Client - клиент:
		- хранит ссылки на одного или нескольких приспособленцев;
		- вычисляет или хранит внешнее состояние приспособленцев.
	 */

	//double longitude = 37.61;
	//double latitude = 55.74;
	string pos = "145.56.444.3.3.3";
	UnitFactory* unitFactory = new UnitFactory();

	for (int i = 0; i < 5; i++)
	{
		Unit* lightInfantry = unitFactory->GetUnit("LightInfantry");
		if (lightInfantry != nullptr)
			lightInfantry->Show(pos);
	}

	for (int i = 0; i < 5; i++)
	{
		Unit* Transport = unitFactory->GetUnit("Transport");
		if (Transport != nullptr)
			Transport->Show(pos);
	}

	delete unitFactory;
	system("pause");
}
