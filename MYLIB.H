#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <windows.h>

//const int n = 32;

using namespace std;

void Isort(int intarray[], const int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(intarray[i] > intarray[j])
            {
                int itemp = intarray[i];
                intarray[i] = intarray[j];
                intarray[j] = itemp;
            }
        }
    }
}

void Dsort(double doublearray[], const int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(doublearray[i] > doublearray[j])
            {
                double dtemp = doublearray[i];
                doublearray[i] = doublearray[j];
                doublearray[j] = dtemp;
            }
        }
    }
}

void Csort(char chararray[], const int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(chararray[i] > chararray[j])
            {
                char ctemp = chararray[i];
                chararray[i] = chararray[j];
                chararray[j] = ctemp;
            }
        }
    }
}

template <class Potter>

void Bsort(Potter ary[], const int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(ary[i] > ary[j])
            {
                Potter temp = ary[i];
                ary[i] = ary[j];
                ary[j] = temp;
            }
        }
    }
}

template <class Potter>
//-------------------------------------------------------------------------------
void qSort(Potter arr[], int P, int E )
{
    int S = P + 1, i = S, j = E, arrSizeTemp = E-P+1;
    if (arrSizeTemp > 1)
    {
        if (arrSizeTemp == 2)
        {
            if (arr[P] > arr[E])
            {
                Potter temp = arr[P];
                arr[P] = arr[E];
                arr[E] = temp;
            }
        }
        else
        {
            if (P < E)
            {
                while (i < j)
                {
                    while (arr[i] <= arr[P] && i <= E)
                        i++;
                    if (i == E)
                    {
                        Potter temp = arr[P];
                        arr[P] = arr[E];
                        arr[E] = temp;
                        qSort(arr, P, E-1);
                    }
                    while (arr[j] > arr[P] && j >= P)
                        j--;
                    if (j == S)
                    {
                        qSort(arr, P+1, E);
                    }
                    if (i < j)
                    {
                        Potter temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
                Potter temp = arr[P];
                arr[P] = arr[j];
                arr[j] = temp;
                qSort(arr, P, j-1);
                qSort(arr, j+1, E);
            }
        }
    }
}
//-------------------------------------------------------------------------------

class Roman{
	public:
		Roman();		            // default constructor  rStr = “Blank”, iStr = 0;
		Roman(string);	 	        // constructs a Roman Numeral  given a String. Calls convertToInt() to assign the correct numeric value

		Roman(int);		            // construcs a Roman numeral given a String. Calls convertToStr to assign the correct numeric value
		void setStr(string);	    // Sets the Roman Numeral String
		string getStr();		    // Returns the Roman Numeral
		void setInt(int);		    // Sets the Roman Numeral Value
		int getInt();		        // Returns the Roman Numeral Value
		void displayProp();	        // Displays the String and Integer Values of the Roman Numeral
        void convertToInt(string);	// coverts the string to its integer value
        void convertToStr(int);		// converts the integer to its string vlaue
        string operator+ (Roman);
        int operator- (Roman);
        int operator> (Roman);
	private:
		string romanStr;
		int romanInt;
};


Roman::Roman()
{
    string romanStr = "Blank";
    int romanInt = 0;
}
Roman::Roman(string rStr)
{
    setStr((rStr));
    convertToInt((rStr));
}
Roman::Roman(int rInt)
{
    setInt(rInt);
    convertToStr((rInt));
}
void Roman::setStr(string str)
{
    romanStr = str;
    convertToInt(str);
}
string Roman::getStr()
{
    return romanStr;
}
void Roman::setInt(int num)
{
    romanInt = num;
    convertToStr(num);
}
int Roman::getInt()
{
    return romanInt;
}
void Roman::displayProp()
{
    cout << endl << "Properties: " << endl;
    cout << "Roman Numeral: " << getStr() << endl;
    cout << "Number: " << getInt() << endl << endl;
}
string Roman::operator+ (Roman rStr1)
{
    return(romanStr + rStr1.getStr());
}
int Roman::operator- (Roman rInt1)
{
    return (getInt() - rInt1.getInt());
}
int Roman::operator> (Roman rInt1)
{
    /*if(getInt() > rInt1.getInt())
    {
        return getInt();
    }
    else if(getInt() < rInt1.getInt())
    {
        return rInt1.getInt();
    }*/
    int tf;
    if(getStr().length() == rInt1.getStr().length())
    {
        if(getInt() > rInt1.getInt())
        {
            tf = 1;
        }
        else if(getInt() < rInt1.getInt())
        {
            tf = 0;
        }
    }

    else if(getStr().length() > rInt1.getStr().length())
    {
        tf = 1;
    }
    else if(getStr().length() < rInt1.getStr().length())
    {
        tf = 0;
    }
    return tf;
}

void Roman::convertToInt(string rStr)
{
    romanInt = 0;
    string temp = rStr;
    while(temp != "")
    {
        while(temp.find("CM") != -1)
        {
            romanInt += 900;
            temp.erase(temp.find("CM"),2);
        }
        while(temp.find("M") != -1)
        {
            romanInt += 1000;
            temp.erase(temp.find("M"),1);
        }
        while(temp.find("CD") != -1)
        {
            romanInt += 400;
            temp.erase(temp.find("CD"),2);
        }
        while(temp.find("D") != -1)
        {
            romanInt += 500;
            temp.erase(temp.find("D"),1);
        }
        while(temp.find("XC") != -1)
        {
            romanInt += 90;
            temp.erase(temp.find("XC"),2);
        }
        while(temp.find("C") != -1)
        {
            romanInt += 100;
            temp.erase(temp.find("C"),1);
        }
        while(temp.find("XL") != -1)
        {
            romanInt += 40;
            temp.erase(temp.find("XL"),2);
        }
        while(temp.find("L") != -1)
        {
            romanInt += 50;
            temp.erase(temp.find("L"),1);
        }
        while(temp.find("IX") != -1)
        {
            romanInt += 9;
            temp.erase(temp.find("IX"),2);
        }
        while(temp.find("X") != -1)
        {
            romanInt += 10;
            temp.erase(temp.find("X"),1);
        }
        while(temp.find("IV") != -1)
        {
            romanInt += 4;
            temp.erase(temp.find("IV"),2);
        }
        while(temp.find("V") != -1)
        {
            romanInt += 5;
            temp.erase(temp.find("V"),1);
        }
        while(temp.find("I") != -1)
        {
            romanInt += 1;
            temp.erase(temp.find("I"),1);
        }
    }
}
    void Roman::convertToStr(int rInt)
    {
        romanStr = "";
        int temp = rInt;
        while(temp > 0)
        {
            while((temp - 1000) >= 0)
            {
                romanStr += "M";
                temp -= 1000;
            }
            while((temp - 900) >= 0)
            {
                romanStr += "CM";
                temp -= 900;
            }
            while((temp - 500) >= 0)
            {
                romanStr += "D";
                temp -= 500;
            }
            while((temp - 400) >= 0)
            {
                romanStr += "CD";
                temp -= 400;
            }
            while((temp - 100) >= 0)
            {
                romanStr += "C";
                temp -= 100;
            }
            while((temp - 90) >= 0)
            {
                romanStr += "XC";
                temp -= 90;
            }
            while((temp - 50) >= 0)
            {
                romanStr += "L";
                temp -= 50;
            }
            while((temp - 40) >= 0)
            {
                romanStr += "XL";
                temp -= 40;
            }
            while((temp - 10) >= 0)
            {
                romanStr += "X";
                temp -= 10;
            }
            while((temp - 9) >= 0)
            {
                romanStr += "IX";
                temp -= 9;
            }
            while((temp - 5) >= 0)
            {
                romanStr += "V";
                temp -= 5;
            }
            while((temp - 4) >= 0)
            {
                romanStr += "IV";
                temp -= 4;
            }
            while((temp - 1) >= 0)
            {
                romanStr += "I";
                temp -= 1;
            }
        }
    }
