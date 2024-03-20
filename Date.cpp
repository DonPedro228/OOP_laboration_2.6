#include "Date.h"
#include <sstream>
using namespace std;

int Date::counter = 0;

Date::Date() {}

Date::Date(int day, int month, int year)
{
    date.Init(day, month, year);
    counter++;
}

Date::Date(const Date& other) {
    date = other.date; 
    counter++; 
}

Date::Date(const int date) : date(Triad(date)) {
    counter++;
}

void Date::Init(int day, int month, int year)
{
    date.Init(day, month, year);
}

void Date::Display() const
{
    date.Display();
}

void Date::Read()
{
    date.Read();
}

Date::operator string() const
{
    return string(date);
}


Date& Date::operator++()
{
    ++date;
    return *this;
}

Date& Date::operator--()
{
    --date;
    return *this;
}

Date& Date::operator=(const Date& other)
{
    if (this != &other) {
        date = other.date;
    }
    return *this;
}

Date operator+(const Date& date, int days) {
    int day = date.getDay() + days;
    int month = date.getMonth();
    int year = date.getYear();

    while (day > 31 || (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 29) ||
        (month == 2 && ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) && day > 28) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                day -= 29;
            }
            else {
                day -= 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            day -= 30;
        }
        else {
            day -= 31;
        }
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    Date result(date);
    result.setDay(day);
    result.setMonth(month);
    result.setYear(year);

    return result;
}

ostream& operator << (ostream& out, const Date& m)
{
    out << m.date;
    return out;
}


istream& operator >> (istream& in, Date& m)
{
    in >> m.date;
    return in;
}

int Date::getCounter()
{
    return Date::counter;
}

Date::~Date()
{
    Date::counter--;
}

int Date::Triad::counter = 0;

Date::Triad::Triad() {
    for (int i = 0; i < 3; ++i) {
        date[i] = 0; 
    }
    counter++;
}

Date::Triad::Triad(const Triad& other) {
    for (int i = 0; i < 3; ++i) {
        date[i] = other.date[i]; 
    }
    counter++; 
}

Date::Triad::Triad(const int date)
{
    Date::Triad::counter++;
}

Date::Triad::Triad(int day, int month, int year)
{
    date[0] = day;
    date[1] = month;
    date[2] = year;
    counter++;
}

Date::Triad& Date::Triad::operator = (const Triad& other)
{
    date[0] = other.date[0];
    date[1] = other.date[1];
    date[2] = other.date[2];
    return *this;
}

Date::Triad& Date::Triad::operator ++()
{
    ++date[0];
    ++date[1];
    ++date[2];
    return *this;
}

Date::Triad& Date::Triad::operator --()
{
    --date[0];
    --date[1];
    --date[2];
    return *this;
}

int Date::Triad::getDay() const {
    return date[0];
}

int Date::Triad::getMonth() const {
    return date[1];
}

int Date::Triad::getYear() const {
    return date[2];
}

void Date::Triad::setDay(int day) {
    date[0] = day;
}

void Date::Triad::setMonth(int month) {
    date[1] = month;
}

void Date::Triad::setYear(int year) {
    date[2] = year;
}

void Date::Triad::Init(int day, int month, int year) {
    setDay(day);
    setMonth(month);
    setYear(year);
}

void Date::Triad::Display() const {
    cout << endl;
    cout << "Date: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
}

void Date::Triad::Read() {
    int day, month, year;
    cout << "Input date: ";
    cin >> day >> month >> year;

    Init(day, month, year);
}

Date::Triad::operator string()const
{
    stringstream ss;
    ss << endl;
    ss << "Date: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
    return ss.str();
}

ostream& operator << (ostream& out, const Date::Triad& m)
{
    out << string(m);
    return out;
}

istream& operator >> (istream& in, Date::Triad& m)
{
    int day, month, year;
    cout << endl;
    cout << "Input date: "; 
    in >> m.date[0] >> m.date[1] >> m.date[2];
    return in;
}

Date::Triad::~Triad() {
    counter--;
}

int Date::Triad::getCounter()
{
    return Date::Triad::counter;
}