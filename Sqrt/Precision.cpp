#include <iostream>
#include <cmath>
using namespace std;

double sqrtsearch(double num)
{
 if (num<0) // checking for a non-negative numbers
return 0; // then return zero if there is negative numbers

 else if(num==0 || num==1) //checking for 1 and 0 which can't be use in the iteration
 return num; // return  the num value if there is 0 or 1


 double accuracy = 0.00001;//the accuracy of the squared root, greater the number the more accurate is the sqrt
 double st = 0;
 double en = num; // overwritten the en with num

 if(num<=1) // the true statement
  en = 1; // The start of the iteration
 while(en-st>accuracy){ // the iteration of the program as the values of en
  //and st get closer and closer until the values are less than 0.0001 apart.
  double mid = (st+en)/2; // store the value for mid from each iteration
  double midSqr = mid*mid;// stored the value of mid*mid
  if(midSqr==num) // checking for whether midsqr is equal to the num if not garbage collector
    return mid;// if is true return the mid
  else if(midSqr<num) // if the statement  if(midSqr==num) is false we start here
    st = mid; // if midSqr less than num  we overwrite  st with mid
else en = mid;// if all this statement are false we return
 }

 return (st+en)/2;// if we did not find exact sqrt value, we return the approximated value with the defined of sqrt
}

int main()
{
    for (double i=-10; sqrtsearch(i)<=7;i++)
    //double n;

  //  cout<<"Enter any numbers to find the Sqrt"<<endl; // ask the user to input any number, perfect or no perfect sqrt
   // cin>> n; //input

    cout<<"the sqrt of "<<i<< " is "<<sqrtsearch(i) <<endl; // output of sqrt


return 0;
}
