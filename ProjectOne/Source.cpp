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

	void Print() const {
		cout << "Company (manufacture): " << company << endl;
		cout << "Model: " << model << endl;
		cout << "Year of manufacturing: " << year << endl;
		cout << "Engine volume: " << volume << endl;
		cout << "Price of the vehicle: " << price << endl;
	}

	void operator() () {
		string tmpstr = {};
		int tmpint = 0;
		cout << "Enter company: ";
		cin >> tmpstr;
		SetCompany(tmpstr);
		cout << "Enter model: ";
		cin >> tmpstr;
		SetModel(tmpstr);
		cout << "Enter manufacture year: ";
		cin >> tmpint;
		SetYear(tmpint);
		cout << "Enter volume of engine: ";
		cin >> tmpint;
		SetVolume(tmpint);
		cout << "Enter price of the car: ";
		cin >> tmpint;
		SetPrice(tmpint);
	}
};

bool cmpYear(const Car left, const Car right) {
	return left.GetYear() < right.GetYear();
}

bool cmpVolume(const Car left, const Car right) {
	return left.GetVolume() < right.GetVolume();
}

bool cmpPrice(const Car left, const Car right) {
	return left.GetPrice() < right.GetPrice();
}

int main() {
	vector<Car> avtosalon;
	int ch = 0;
	do
	{
		cout << "Avtosalon programm" << endl;
		cout << "1 - Add\n2 - Delete\n3 - Print\n4 - Sort\n5 - Find\n0 - Quit" << endl;
		cin >> ch;
		system("cls");
		Car tmpcar;
		int tmpint = 0;
		string tmpstr = "";
		switch (ch)
		{
		case 0:
			cout << "Bye";
			break;
		case 1:
			tmpcar();
			avtosalon.push_back(tmpcar);
			break;
		case 2:
			for (int i = 0; i < avtosalon.size(); i++)
			{
				cout << i + 1 << endl;
				avtosalon[i].Print();
				cout << endl;
			}
			cout << "Select for delete: ";
			cin >> tmpint;
			tmpint--;
			if (tmpint < 0 || tmpint >= avtosalon.size()) {
				cout << "Invalid data" << endl;
				break;
			}
			if (true) {
				auto tmpit = avtosalon.begin();
				advance(tmpit, tmpint);
				avtosalon.erase(tmpit);
			}
			break;
		case 3:
			for (Car elem : avtosalon) {
				elem.Print();
				cout << endl;
			}
			break;
		case 4:
			cout << "\n1)Manufacture year\n2)Volume of engine\n3)Price of the car\n4)Reverse" << endl;
			cin >> tmpint;
			if (tmpint < 1 || tmpint > 4) {
				cout << "Invalid data" << endl;
				break;
			}
			if (tmpint == 1) {
				sort(avtosalon.begin(), avtosalon.end(), cmpYear);
			}
			else if (tmpint == 2) {
				sort(avtosalon.begin(), avtosalon.end(), cmpVolume);
			}
			else if (tmpint == 3) {
				sort(avtosalon.begin(), avtosalon.end(), cmpPrice);
			}
			else if (tmpint == 4) {
				reverse(avtosalon.begin(), avtosalon.end());
			}
			break;
		case 5:
			cout << "\n1)Company\n2)Model\n3)Year\n4)Volume of engine\n5)Price of the car" << endl;
			cin >> tmpint;
			if (tmpint < 1 || tmpint > 5) {
				cout << "Invalid data" << endl;
				break;
			}
			if (tmpint == 1) {
				int results = 0;
				cout << "Enter company name: ";
				cin >> tmpstr;
				for (int i = 0; i < avtosalon.size(); i++)
				{
					if (avtosalon[i].GetCompany() == tmpstr) {
						avtosalon[i].Print();
						cout << endl;
						results++;
					}
				}
				if (results == 0) {
					cout << "No results found" << endl;
				}
				else {
					cout << results << " results found" << endl;
				}
			}
			else if (tmpint == 2) {
				int results = 0;
				cout << "Enter model: ";
				cin >> tmpstr;
				for (int i = 0; i < avtosalon.size(); i++)
				{
					if (avtosalon[i].GetModel() == tmpstr) {
						avtosalon[i].Print();
						cout << endl;
						results++;
					}
				}
				if (results == 0) {
					cout << "No results found" << endl;
				}
				else {
					cout << results << " results found" << endl;
				}
			}
			else if (tmpint == 3) {
				int results = 0, tmp = 0;
				cout << "Enter company name: ";
				cin >> tmp;
				for (int i = 0; i < avtosalon.size(); i++)
				{
					if (avtosalon[i].GetYear() == tmp) {
						avtosalon[i].Print();
						cout << endl;
						results++;
					}
				}
				if (results == 0) {
					cout << "No results found" << endl;
				}
				else {
					cout << results << " results found" << endl;
				}
			}
			else if (tmpint == 4) {
				int results = 0, tmp = 0;
				cout << "Enter volume of the engine: ";
				cin >> tmp;
				for (int i = 0; i < avtosalon.size(); i++)
				{
					if (avtosalon[i].GetVolume() == tmp) {
						avtosalon[i].Print();
						cout << endl;
						results++;
					}
				}
				if (results == 0) {
					cout << "No results found" << endl;
				}
				else {
					cout << results << " results found" << endl;
				}
			}
			else if (tmpint == 5) {
				int results = 0, tmp = 0;
				cout << "Enter price of the car: ";
				cin >> tmp;
				for (int i = 0; i < avtosalon.size(); i++)
				{
					if (avtosalon[i].GetPrice() == tmp) {
						avtosalon[i].Print();
						cout << endl;
						results++;
					}
				}
				if (results == 0) {
					cout << "No results found" << endl;
				}
				else {
					cout << results << " results found" << endl;
				}
			}
			break;
		default:
			cout << "Not available";
			break;
		}
	} while (ch!=0);
	return 0;
}