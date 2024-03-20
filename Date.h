#pragma once
#include <string>
#include <iostream>

using namespace std;

class Date
{
private:
    static int counter;
public:
    class Triad
    {
    private:
        int date[3];
        static int counter;
    public:
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);

        Triad();
        Triad(int day, int month, int year);
        Triad(const Triad& other);
        Triad(const int date);

        void Init(int day, int month, int year);
        void Display() const;
        void Read();

        Triad& operator ++();
        Triad& operator --();

        Triad& operator = (const Triad& other);
        friend ostream& operator << (ostream& out, const Triad& m);
        friend istream& operator >> (istream& in, Triad& m);
        operator string () const;


        ~Triad(void);

        static int getCounter();
    };
    Date();
    Date(int day, int month, int year);
    Date(const Date& other);
    Date(const int date);

    void Init(int day, int month, int year);
    void Display() const;
    void Read();
    operator string() const;

    int getDay() const { return date.getDay(); }
    int getMonth() const { return date.getMonth(); }
    int getYear() const { return date.getYear(); }
    void setDay(int day) { date.setDay(day); }
    void setMonth(int month) { date.setMonth(month); }
    void setYear(int year) { date.setYear(year); }

    Date& operator ++();
    Date& operator --();

    friend ostream& operator << (ostream& out, const Date& m);
    friend istream& operator >> (istream& in, Date& m);

    Date& operator = (const Date& other);
    friend Date operator+(const Date& date, int days);

    static int getCounter();
    ~Date(void);

private:
    Triad date;

};