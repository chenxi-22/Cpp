#pragma once

#include <iostream>

using namespace std;

class Date {
public:
  Date(int year = 1900, int month = 1, int day = 1); // 构造函数
  Date(const Date& d); // 拷贝构造

  void DatePrint(); // 打印函数
  int GetMonthDay(int year, int month); // 获取某年某个月的总天数

  Date& operator=(Date d); // 核心

  Date& operator+=(int day); // 核心
  Date operator+(int day);
  Date& operator-=(int day); // 核心
  Date operator-(int day);

  int operator-(const Date& d);

  bool operator>(const Date& d); // 核心
  bool operator==(const Date& d); // 核心
  bool operator<(const Date& d);

  bool operator>=(const Date& d);
  bool operator<=(const Date& d);
  bool operator!=(const Date& d);

  Date& operator++(int); // 后置++
  Date operator++(); // 前置++
  Date& operator--(int); // 后置--
  Date operator--(); // 前置--
  
  ~Date(); // 析构函数

private:
  int _year;
  int _month;
  int _day;
};


