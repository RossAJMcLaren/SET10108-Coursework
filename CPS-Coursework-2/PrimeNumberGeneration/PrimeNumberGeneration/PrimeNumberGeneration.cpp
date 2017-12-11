// PrimeNumberGeneration.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include <fstream>

using namespace std;

void FindingPrimesByDivisionRevised(ofstream& fileName)
{
	bool flag = true;
	for (int i = 1; i <= sqrt(1000000000); i++)
	{
		for (int k = 2; k <= sqrt(1000000000); k++)
		{
			if (i % 2 == 0)
			{
				flag = false;
				break;
			}
			if (i == k)
			{
				continue;
			}
			else if (i % k == 0)
			{
				flag = false;
				break;
			}
			else
			{
				flag = true;
				break;
			}
		}

		if (flag == true)
		{
			fileName << i << endl;
		}
	}
}

void FindingPrimesByDivision(ofstream& fileName)
{
	bool flag = true;
	for (int i = 2; i <= 1000000000; i ++)
	{
		for (int k = 2; k <= 1000000000; k ++)
		{
			if (i == k)
			{
				continue;
			}
			else if (i % k == 0)
			{
				flag = false;
				break;
			}
			else
			{
				flag = true;
				break;
			}
		}

		if (flag == true)
		{
			fileName<< i << endl;
		}
	}
}

int main()
{
	ofstream myfile;
	ofstream primeNumbers;
	myfile.open("TimeTakenForPrimeFinding.csv");
	clock_t t;
	primeNumbers.open("PrimeNumbers.csv");
	t = clock();
	FindingPrimesByDivisionRevised(primeNumbers);
	t = clock() - t;
	myfile << "Time Taken in MS for FindingPrimesByDivisionRevised" << endl << t << endl;
	myfile.close();
	primeNumbers.close();
    return 0;
}


