#include "date.h"

void Test()
{
  Date d1(2018, 7, 6);
  Date d3(2018, 9, 10);

  Date d2(d1);
  d2.DatePrint();

  d3 = d2;
  d3.DatePrint();

  d1 += 100;
  d1.DatePrint();

  d1 += 0;
  d1.DatePrint();

  d1 += 10;
  d1.DatePrint();
}

int main()
{
  Test();
  
  return 0;
}
