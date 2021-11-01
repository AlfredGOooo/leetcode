
/**
 *  given a set of integers:
 *  first line: a number show the list size 
 *  second line: a number of ints, quantity = list size
 *  if some of them is Prime, print out Prime,
 *  if some of them are composite, print out Composite
 * 
 *  input:
 *  5 
 *  334 34 34 34 53 
 *  
 *  output:
 *  Composite Composite Composite.....
 * 
 */

// Sample code to read input and write output:

/*
#include <iostream>

using namespace std;

int main() 
{
	char name[20];
	cin >> name;                     // Read input from STDIN
	cout << "Hello " << name;        // Write output to STDOUT
	return 0;
}
*/

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

bool isPrime(int num) {
    if (num<=1) return false;
    int i = 2;
    while (i*i<=num) {
        if (num%i==0) return false;
        i++;
    }
    return true;
}


int main()
{
	// Write your code here
	int size, num;
	string output;
	cin >> size;
	
	int arr[size];
	for (int i=0; i<size; i++) {
	    cin >> arr[i];
	}
	

	for (int j=0; j<size; j++) {
	    num = arr[j];
	    output = isPrime(num) ? "Prime":"Composite";
	    cout<< output << " " ;
	}
	
	return 0;
}