// Samraj Moorjani
// Period 3A ComSci II
// Mr. Potter
#include <iostream>
#include <windows.h>

using namespace std;
bool neg = false;

class Enode
{
    private:
        char data;
        int p;
        Enode *left, *right;
    public:
        Enode(char x, int pr, Enode *l, Enode *r)
        {
            data = x;
            p = pr;
            left = l;
            right = r;
        }
        char getData()
        {
            return data;
        }
        Enode* getLeft()
        {
            return left;
        }
        Enode* getRight()
        {
            return right;
        }
        int getP()
        {
            return p;
        }
        void setValue(char x)
        {
            data = x;
        }
        void setLeft(Enode *l)
        {
            left = l;
        }
        void setRight(Enode *r)
        {
            right = r;
        }
        void setP(int pr)
        {
            p = pr;
        }
};

class Etree
{
    private:
        Enode *root;
    public:
        Etree()
        {
            root = NULL;
        }
        void EInsert(char c, Enode* &current);
        void print(Enode *current);
        double calculate(Enode *current);
        void Menu();
};

void Etree::EInsert(char c, Enode* &current)
{
    if (root == NULL)
    {
        root = new Enode(c, 999, NULL, NULL);
    }
    else if ((current -> getData() == '+' || current -> getData() == '-' || current -> getData() == '*' || current -> getData() == '/' ))
    {
        Enode *temp = new Enode(c, 999, NULL, NULL);
        string tempChar = " ";
        tempChar = c;
        if (!(c == '+' || c == '-' || c == '*' || c == '/' ))
            temp -> setP(atoi(tempChar.c_str()));
        if (neg == true)
        {
            temp -> setP((-1)* temp -> getP());
            neg = false;
        }
        if (current -> getLeft() == NULL)
        {
            current -> setLeft(temp);
            if (temp -> getP() == 999)
                current = current -> getLeft();
        }
        else if (current -> getRight() == NULL)
        {
            current -> setRight(temp);
        }
        else
        {
            EInsert(c, current -> getLeft());
            EInsert(c, current -> getRight());
        }

    }
//    print(root);
//    cout << endl;
}

void Etree::print(Enode *current)
{
    if(current == NULL)
        cout << "NOTHING TO PRINT" << endl;
    else
    {
        if (!(current -> getLeft() == NULL))
            print(current -> getLeft());
        if (current -> getP() < 0)
            cout << "(" << current -> getP() << ") ";
        else
            cout << current -> getData() << " ";
        if (!(current -> getRight() == NULL))
            print(current -> getRight());
    }
}

double Etree::calculate(Enode *current)
{
    double LeftVal, RightVal;
    if(root == NULL)
        cout << "NOTHING TO CALCULATE" << endl;
    else if (!(root -> getData() == '+' || root -> getData() == '-' || root -> getData() == '*' || root -> getData() == '/'))
        return root -> getData();
    else
    {
        if (!(current -> getLeft() -> getData() == '+' || current -> getLeft() -> getData() == '-' || current -> getLeft() -> getData() == '*' || current -> getLeft() -> getData() == '/'))
            LeftVal = current -> getLeft() -> getP();
        else
            LeftVal = calculate(current -> getLeft());
        if (!(current -> getRight() -> getData() == '+' || current -> getRight() -> getData() == '-' || current -> getRight() -> getData() == '*' || current -> getRight() -> getData() == '/'))
            RightVal = current -> getRight() -> getP();
        else
            RightVal = calculate(current -> getRight());
        switch(current -> getData())
        {
            case '+':
//                cout << LeftVal << "+" << RightVal << "  " << LeftVal + RightVal << endl;
                return LeftVal + RightVal;
            case '-':
//                cout << LeftVal << "-" << RightVal << "  " << LeftVal - RightVal << endl;
                return LeftVal - RightVal;
            case '*':
//                cout << LeftVal << "*" << RightVal << "  " << LeftVal * RightVal << endl;
                return LeftVal * RightVal;
            case '/':
//                cout << LeftVal << "/" << RightVal << "  " << LeftVal / RightVal << endl;
                return LeftVal / RightVal;
        }
    }
    //    if(current -> getP() != 999)
//    {
//        return current -> getP();
//    }
//    else if(current -> getP() == 999)
//    {
//        if(current -> getData() == '+')
//        {
//            return calculate(current -> getLeft()) + calculate(current -> getRight());
//        }
//        else if(current -> getData() == '-')
//        {
//            return calculate(current -> getLeft()) - calculate(current -> getRight());
//        }
//        else if(current -> getData() == '*')
//        {
//            return calculate(current -> getLeft()) * calculate(current -> getRight());
//        }
//        else if(current -> getData() == '/')
//        {
//            return calculate(current -> getLeft()) / calculate(current -> getRight());
//        }
//    }
}

void Etree::Menu()
{
    int choice;
    string cchoice;
    while(1)
    {
        cout << "MENU" << endl << "(1) PRINT" << endl << "(2) INSERT" << endl << "(3) CALCULATE" << endl << "(4) EXIT" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                print(root);
                system("pause");
                break;
            case 2:
                cout << "ENTER A STRING: ";
                cin >> cchoice;
                root = NULL;
                for (int i = 0; i < cchoice.length(); i++)
                {
                    char temp = cchoice[i];
                    if (temp == '(' || temp == ')')
                        continue;
                    else if (temp == '-' && cchoice[i-1] == '(')
                    {
                        neg = true;
                        continue;
                    }
                    EInsert(temp, root);
                    neg = false;
                }
                system("pause");
                break;
            case 3:
                cout << calculate(root) << endl;
                system("pause");
                break;
            case 4:
                return;
        }
        cout << endl << endl;
    }
}

int main()
{
    Etree myEtree;
    myEtree.Menu();
}
