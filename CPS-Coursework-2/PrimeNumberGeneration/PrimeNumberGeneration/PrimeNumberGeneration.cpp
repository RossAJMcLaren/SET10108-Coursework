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
	fileName << 1 << endl;
	fileName << 2 << endl;
	for (int i = 3; i <= 1000000000; i+=2)
	{
		for (int k = 3; k * k <= 1000000000; k+=2)
		{
			if (i % k == 0)
			{
				flag = false;
				break;
			}
			else
			{
				flag = true;
				fileName << i << endl;
				break;
			}
		}
	}
}

void FindingPrimesUsingSundaramSieve(int upperBound, ofstream& fileName)
{
	int newUpperBound = (int)sqrt((double)upperBound);
	bool *marked = new bool[upperBound + 1];
	fileName << 2 << endl;
	memset(marked, 0, sizeof(bool) * (upperBound + 1));

	for (int i = 1; i <= newUpperBound; i++)
	{
		for (int j = i; (i + j + 2 * i*j) <= newUpperBound; j++)
		{
			marked[i + j + 2 * i*j] = true;
		}
	}

	for (int i = 1; i <= newUpperBound; i++)
	{
		if (marked[i] == false)
		{
			fileName << 2 * i + 1 << endl;
		}
	}
	delete[] marked;
}

void FindingPrimesUsingEratosthenesSieve(int upperBound, ofstream& fileName) 
{
	int upperBoundSquareRoot = (int)sqrt((double)upperBound);
	bool *isComposite = new bool[upperBound + 1];
	memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
	for (int m = 2; m <= upperBoundSquareRoot; m++) 
	{
		if (!isComposite[m]) 
		{
			fileName << m << " ";
			for (int k = m * m; k <= upperBound; k += m)
				isComposite[k] = true;
		}
	}
	for (int m = upperBoundSquareRoot; m <= upperBound; m++)
	{
		if (!isComposite[m])
		{
			fileName << m << " ";
		}
	}
	delete[] isComposite;
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
	ofstream primeNumbers1;
	ofstream primeNumbers2;
	ofstream primeNumbers3;
	ofstream primeNumbers4;
	myfile.open("TimeTakenForPrimeFinding.csv");
	clock_t t;
	primeNumbers1.open("PrimeNumbersByDivision.csv");
	primeNumbers2.open("PrimeNumbersRevised.csv");
	primeNumbers3.open("PrimeNumbersBySundaramSieve.csv");
	primeNumbers4.open("PrimeNumbersByEratosthenesSieve.csv");
	t = clock();
	FindingPrimesByDivision(primeNumbers1);
	FindingPrimesByDivisionRevised(primeNumbers2);
	FindingPrimesUsingSundaramSieve(1000000000, primeNumbers3);
	FindingPrimesUsingEratosthenesSieve(1000000000, primeNumbers4);
	t = clock() - t;
	myfile << "Time Taken in MS for FindingPrimesByDivisionRevised" << endl << t << endl;
	myfile.close();
	primeNumbers1.close();
	primeNumbers2.close();
	primeNumbers3.close();
	primeNumbers4.close();
    return 0;
}


