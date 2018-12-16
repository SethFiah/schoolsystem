#include<iostream>
using namespace std;
int main()
{  int item;
    cout<<"Enter the number to search\n";
	cin>>item;
int list[10]={2,3,4,5,6,7,8,9,10,11};	
int first = 0;
int last = 10 - 1;
int mid;
bool found = false;
while (first <= last && !found)
{
mid = (first + last) / 2;
if (list[mid] == item)
found = true;
else if (list[mid] > item)
last = mid - 1;
else
first = mid + 1;
}
if (found)
cout<<item<<" found at position "<<mid+1;
else
return -1;
}
