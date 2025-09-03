#include<istream>
#include<math.h>
class Date{
    int day;
    int month;
    int year;
};

class Person{
    int m_NID;
    int m_fname;
    char m_lname;
    Date m_BD;

    public:

    Person(const char* fname , const char* lname, int id , Date bd)
    :m_BD(bd), m_NID(id)
    {
        int i;
        for (i = 0 ; i< sizeof(m_fname)&& fname[i]!= '\0'; i++)
        {
            m_fname[i] = fname[i];
        }m_fname[i]= '\0';

    }
}