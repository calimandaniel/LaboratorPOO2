#include <iostream>
using namespace std;

//class Figura
//{
//protected:
//	int aux=5;
//};
//
//class Dreptunghi : public Figura
//{
//private:
//	int var2 = aux;
//};


class Facultate
{
public:
	Facultate()
	{
		cout << "Constructor default";
	}

	Facultate(const string& numeFaculate)
	{
		cout << "Constructor cu parametru" << endl;
		nume = numeFaculate;
	}

	Facultate(const Facultate& altaFacultate)
		//: nume(facultate.nume)
	{
		nume = altaFacultate.nume;
		cout << "Constructor de copiere" << endl;
	}

	Facultate& operator=(const Facultate& altaFacultate)
	{
		cout << "Supraincarcare operator=" << endl;
		nume = altaFacultate.nume;
		return *this;
	}

	void setNume(string numeFaculate)
	{
		nume = numeFaculate;
	}

	string getNume()
	{
		return nume;
	}
public:

	string nume;

};

int main()
{
	Facultate facultate1("FMI");
	Facultate facultate2(facultate1);


	facultate2 = facultate1;
	//cout << facultate2.getNume();
	/*cout << facultate1.getNume();
	facultate1.setNume("Istorie");
	cout << facultate1.getNume();*/

	//cout << facultate1.nume;
	//Figura figura1;
	//figura1.aux;
	//facultate1.var;
	//cout << "Laborator";
	return 0;
}