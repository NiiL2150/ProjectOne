#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Car {
private:
	string company;
	string model;
	int year;
	int volume;
	int price;
public:
	Car(string _company, string _model, int _year, int _volume, int _price) :
		company(_company), model(_model), year(_year), volume(_volume), price(_price) {}
	Car() : Car("Sample company", "Sample model", 2000, 2, 20000) {}

	string GetCompany() const { return company; }
	void SetCompany(string _company) { company = _company; }

	string GetModel() const { return model; }
	void SetModel(string _model) { model = _model; }

	int GetYear() const { return year; }
	void SetYear(int _year) { year = _year; }

	int GetVolume() const { return volume; }
	void SetVolume(int _volume) { volume = _volume; }

	int GetPrice() const { return price; }
	void SetPrice(int _price) { price = _price; }
};

int main() {
	vector<Car> avtosalon;
	int ch = 0;
	do
	{
		cout << "1 - Add\n2 - Delete\n";
		cin >> ch;
	} while (ch!=0);
	return 0;
}