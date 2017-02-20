#include <iostream>
#include <string>

int main(){
  std::string a, b, c;
  int t1=0, t2=0, t3=0, sum;

  //input
  std::cout << "Please enter your choices: " << std::endl;
  std::cin >> a >> b >> c;
  while (a!="e1" && a!="e2" && a!="e3" && a!="s1" && a!="s2" && a!="s3" && a!="b1" && a!="b2"&& a!="b3" && a!="b4" && a!="b5" && a!="b6" && a!="b7" && a!="b8")
   {std::cout << "invalid codes, please enter again: " << '\n';
        std::cin >> a >> b >> c;}
  while( b!="e1" && b!="e2" && b!="e3" && b!="s1" && b!="s2" && b!="s3" && b!="b1" && b!="b2" && b!="b3" && b!="b4" && b!="b5" && b!="b6" && b!="b7" && b!="b8")
     {std::cout << "invalid codes, please enter again: " << '\n';
        std::cin >> a >> b >> c;}
  while(c!="e1" && c!="e2" && c!="e3" && c!="s1" && c!="s2" && c!="s3" && c!="b1" && c!="b2" && c!="b3" && c!="b4" && c!="b5" && c!="b6" && c!="b7" && c!="b8")
     {std::cout << "invalid codes, please enter again: " << '\n';
        std::cin >> a >> b >> c;}
  
  //calculate total
  if (a=="e1"){t1=7;}
  else if (a=="e2"){t1=6;}
  else if (a=="e3"){t1=9;}
  else if (a=="s1"){t1=2;}
  else if (a=="s2"){t1=3;}
  else if (a=="s3"){t1=2;}
  else if (a=="b1"){t1=0;}
  else if (a=="b2"){t1=2;}
  else if (a=="b3"){t1=4;}
  else if (a=="b4"){t1=6;}
  else if (a=="b5"){t1=7;}
  else if (a=="b6"){t1=7;}
  else if (a=="b7"){t1=1;}
  else if (a=="b8"){t1=1;}
  else {}
  
  if (b=="e1"){t2=7;}
  else if (b=="e2"){t2=6;}
  else if (b=="e3"){t2=9;}
  else if (b=="s1"){t2=2;}
  else if (b=="s2"){t2=3;}
  else if (b=="s3"){t2=2;}
  else if (b=="b1"){t2=0;}
  else if (b=="b2"){t2=2;}
  else if (b=="b3"){t2=4;}
  else if (b=="b4"){t2=6;}
  else if (b=="b5"){t2=7;}
  else if (b=="b6"){t2=7;}
  else if (b=="b7"){t2=1;}
  else if (b=="b8"){t2=1;}
  else {}

  if (c=="e1"){t3=7;}
  else if (c=="e2"){t3=6;}
  else if (c=="e3"){t3=9;}
  else if (c=="s1"){t3=2;}
  else if (c=="s2"){t3=3;}
  else if (c=="s3"){t3=2;}
  else if (c=="b1"){t3=0;}
  else if (c=="b2"){t3=2;}
  else if (c=="b3"){t3=4;}
  else if (c=="b4"){t3=6;}
  else if (c=="b5"){t3=7;}
  else if (c=="b6"){t3=7;}
  else if (c=="b7"){t3=1;}
  else if (c=="b8"){t3=1;}
  else {}
  sum=t1+t2+t3;
  
  //special1
  if (a=="e1" && b=="s1")
    { if (c=="b1" || c=="b2" || c=="b7" || c=="b8")
	{sum=8;}
      else {};}
  else {}

  if (b=="e1" && a=="s1")
    { if (c=="b1" || c=="b2" || c=="b7" || c=="b8")
	{sum=8;}
      else {};}
  else {}

  if (a=="e1" && c=="s1")
    { if (b=="b1" || b=="b2" || b=="b7" || b=="b8")
	{sum=8;}
      else {};}
  else {}

  if (c=="e1" && a=="s1")
    { if (b=="b1" || b=="b2" || b=="b7" || b=="b8")
	{sum=8;}
      else {};}
  else {}

  if (c=="e1" && b=="s1")
    { if (a=="b1" || a=="b2" || a=="b7" || a=="b8")
	{sum=8;}
      else {};}
  else {}

  if (b=="e1" && c=="s1")
    { if (a=="b7" || a=="b8")
	{sum=7;}
      else {};}
  else {}

  //special2
  if (a=="e2" && b=="s2")
    { if (c=="b1" || c=="b2" || c=="b7" || c=="b8")
	{sum=7;}
      else {};}
  else {}

  if (b=="e2" && a=="s2")
    { if (c=="b1" || c=="b2" || c=="b7" || c=="b8")
	{sum=7;}
      else {};}
  else {}

  if (a=="e2" && c=="s2")
    { if (b=="b1" || b=="b2" || b=="b7" || b=="b8")
	{sum=7;}
      else {};}
  else {}

  if (c=="e2" && a=="s2")
    { if (b=="b1" || b=="b2" || b=="b7" || b=="b8")
	{sum=7;}
      else {};}
  else {}

  if (b=="e2" && c=="s2")
    { if (a=="b1" || a=="b2" || a=="b7" || a=="b8")
	{sum=7;}
      else {};}
  else {}

  if (c=="e2" && b=="s2")
    { if (a=="b1" || a=="b2" || a=="b7" || a=="b8")
	{sum=7;}
      else {};}
  else {}
  
  //special3
  if (a=="e3")
    { if (c=="b3" || c=="b4" || c=="b5" || c=="b6")
  	{sum=13;}
	   else {};}
   else {}

 if (a=="e3")
    { if (b=="b3" || b=="b4" || b=="b5" || b=="b6")
  	{sum=13;}
	   else {};}
   else {}

  if (b=="e3")
    { if (c=="b3" || c=="b4" || c=="b5" || c=="b6")
  	{sum=13;}
	   else {};}
   else {}

   if (b=="e3")
    { if (a=="b3" || a=="b4" || a=="b5" || a=="b6")
  	{sum=13;}
	   else {};}
   else {}

    if (c=="e3")
    { if (a=="b3" || a=="b4" || a=="b5" || a=="b6")
  	{sum=13;}
	   else {};}
   else {}

    if (c=="e3")
    { if (b=="b3" || b=="b4" || b=="b5" || b=="b6")
  	{sum=13;}
	   else {};}
   else {}
  
  //output
    std:: cout << "Your choices are: " << a << " " << b  << " " << c << std::endl;
  std::cout << "Your total is: " << sum  << std::endl;

  return 0;
}
