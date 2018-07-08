#include "date.h"

// Date
Date::Date(int year, int month, int day)
{
  if (year >= 1900 && 
      month > 1 && month < 13 && 
      day > 0 && day <= GetMonthDay(year, month)) {
    this->_year = year;
    this->_month = month;
    this->_day = day;
  }
}

// Date
Date::Date(const Date& d) // 拷贝构造
{
  _year = d._year;
  _month = d._month;
  _day = d._day;
}

// DatePrint
void Date::DatePrint() // 打印函数
{
  cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
}

// GetMonthDay
int Date::GetMonthDay(int year, int month)
{
  static int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 这里将这个天数设置成 static 类型的，这样只创建一次
  int day = month_days[month];

  if (month == 2 &&  
      ((year % 4 == 0 && year % 100 != 100) || year % 400 == 0)) {
    day += 1;
  }

  return day;
}

// operator=
Date& Date::operator=(Date d)
{
  _year = d._year;
  _month = d._month;
  _day = d._day;

  return *this;
}

// operator-=
Date& Date::operator-=(int day)
{
  while (_day <= day) {
    if (--_month == 0) {
      --_year;
      _month = 12;
    }
    _day += GetMonthDay(_year, _month);
  }
  _day -= day;

  return *this;
}

// operator-
Date Date::operator-(int day)
{
  Date tmp(*this);
  tmp -= day;

  return tmp;
}

// operator+=
Date& Date::operator+=(int day)
{
  _day += day;

  while (_day > GetMonthDay(_year, _month)) {
    _day -= GetMonthDay(_year, _month);
    _month++;
    if (_month == 13) {
      _year++;
      _month = 1;
    }
  }

  return *this;
}

// operator+
Date Date::operator+(int day)
{
  Date tmp(*this);
  tmp += day;
  
  return tmp;
}

// operator-
int Date::operator-(const Date& d)
{
  Date min(*this);
  Date max(d);

  if (*this > d) {
    min = d;
    max = *this;
  }

  int day = 0;
  while (min != max) {
    ++day;
    min += 1;
  }

  return day;
}

Date& Date::operator++(int) // 后置++
{
  *this += 1;

  return *this;
}

Date Date::operator++() // 前置++
{
  Date tmp(*this);
  *this += 1;

  return tmp;
}

Date& Date::operator--(int) // 后置--
{
  *this -= 1;
  
  return *this;
}

Date Date::operator--() // 前置--
{
  Date tmp(*this);
  *this -= 1;

  return tmp;
}

// operator>
bool Date::operator>(const Date& d)
{
  if (_year == d._year) {
    if (_month == d._month) {
      if (_day > d._day) {
        return true;
      }
    } else if (_month > d._month) {
      return true;
    }
  } else if (_year > d._year) {
    return true;
  }
  return false;
}

// operator== 
bool Date::operator==(const Date& d)
{
  if (_year == d._year) {
    if (_month == d._month) {
      if (_day == d._day) {
        return true;
      }
    } // end (_month == d._month)
  }
  return false;
}

// operator<
bool Date::operator<(const Date& d)
{
  return !(*this > d) && !(*this == d);
}

// operator>=
bool Date::operator>=(const Date& d)
{
  return !(*this < d);
}

// operator<=
bool Date::operator<=(const Date& d)
{
  return !(*this > d);
}

bool Date::operator!=(const Date& d)
{
  return !(*this == d);
}

// ~Date
Date::~Date() // 析构函数
{
  _year = 1900;
  _month = 1;
  _day = 1;
}

