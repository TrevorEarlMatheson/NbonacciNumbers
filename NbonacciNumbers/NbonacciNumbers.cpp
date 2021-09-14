// NbonacciNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <cmath>

long nbonacci(unsigned int series, unsigned int n)
{
    long value = 0;
    if (n <= series)
    {
        value = 1;
        return value;
    }
    else
    {
        for (int i = 1; i <= series; i++)
        {
            value += nbonacci(series, n - i);
        }
        return value;
    }
}

void computeNbonacciRatio(std::string title, unsigned int series)
{
    int i = 2;
    while (true)
    {
        double n = nbonacci(series, i);
        double n1 = nbonacci(series, i - 1);
        double n2 = nbonacci(series, i - 2);
        double currentRatio = n / n1;
        double previousRatio = n1 / n2;
        double ratioDifference = abs(currentRatio - previousRatio);
        if (ratioDifference == 0)
        {
            i++;
        }
        else if(ratioDifference < 0.000001)
        {
            std::cout << title << " ratio approaches " << currentRatio << " after " << i - 1 << " iterations\n";
            break;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    std::map<int, std::string> seriesType = { {2, "Fibonacci"},{3, "Tribonacci"},{4, "Fourbonacci"},{5, "Fivebonacci"}};
    const int n = 20;

    for (int series = 2; series < 6; series++)
    {
        std::cout << " --- " << seriesType[series] << " Sequence ---\n";
        for (int i = 1; i <= n; i++)
        {
            std::cout << " " << nbonacci(series, i);
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for (int series = 2; series < 6; series++)
    {
        computeNbonacciRatio(seriesType[series], series);
    }
}
