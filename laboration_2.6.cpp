#include "Date.h"

using namespace std;

int main() {
	Date date;


	cout << "Date : " << Date::getCounter() << endl;
	cout << "Date::Triad: " << Date::Triad::getCounter() << endl;

	Date::Triad date_1;

	cout << "Date::Triad +1: " << Date::Triad::getCounter() << endl;
	{
		Date date_2(22, 02, 2001);
		cout << "Date local: " << Date::getCounter() << endl;
		cout << "Date::Triad local: " << Date::Triad::getCounter() << endl;

		Date::Triad date_1;
		cout << "Date::Triad local +1: " << Date::Triad::getCounter() << endl;
	}

	cout << "Date : " << Date::getCounter() << endl;
	cout << "Date::Triad: " << Date::Triad::getCounter() << endl;

	return 0;
}