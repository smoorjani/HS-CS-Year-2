// Samraj Moorjani
// Period 3A ComSci II
// Mr. Potter
#include <iostream>
#include <windows.h>

using namespace std;
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
            return (data);
        }
        Enode* getLeft()
        {
            return (left);
        }
        Enode* getRight()
        {
            return(right);
        }
        int getP()
        {
            return (p);
        }
        void setData(char x)
        {
            data = x;
        }
        void setLeft(Enode* l)
        {
            left = l;
        }
        void setRight(Enode* r)
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
        void EInsert(Enode* &current, string s, int &i);
        void print(Enode *current);
        double calculate(Enode* current);
        void menu();
};

void Etree::EInsert(Enode* &current, string str, int &i)
{
    if(root == NULL)
    {
          current = new Enode(str[i], 999, NULL, NULL);
    }
    if((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/'))
    {
        current -> setData(str[i]);
        i++;
        Enode* leftVal = new Enode(' ', 999, NULL, NULL);
        Enode* rightVal = new Enode(' ', 999, NULL, NULL);
        current -> setLeft(leftVal);
        current -> setRight(rightVal);
        EInsert(leftVal, str, i);
        EInsert(rightVal, str, i);
    }
    else if(s[i] == '(')
    {
        current -> setData(str[i]);
        i += 2;
        current -> setP((-1) * (str[i] - 48));
        i += 2;
    }
    else
    {
        current -> setData(str[i]);
        current -> setP(str[i] - 48);
        i++;
        return;
    }
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

double Etree::calculate(Enode* current)
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
                return LeftVal + RightVal;
            case '-':
                return LeftVal - RightVal;
            case '*':
                return LeftVal * RightVal;
            case '/':
                return LeftVal / RightVal;
        }
    }
}

void Etree::menu()
{
    int choice, i = 0;
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
                root = NULL;
                i = 0;
                cin.ignore();
                getline(cin,cchoice);
                EInsert(root, cchoice, i);
                system("pause");
                break;
            case 3:
                cout << calculate(root) << endl;
                system("pause");
                break;
            case 4:
                return;
        }
        cout << endl;
    }
}

int main()
{
    Etree mytree;
    mytree.menu();
    return 0;
}
