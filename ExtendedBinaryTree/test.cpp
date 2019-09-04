#include <iostream>
#include <windows.h>
#include <cstdlib>

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
        void EInsert(char c, Enode *current);
        void print(Enode *current);
        // PARAMETERS
        void calculate(string c);
        //
        void Menu();
};

Enode *temproot = new Enode(' ', 999, NULL, NULL);

void Etree::EInsert(char c, Enode *current)
{
    //INPUT
    if (root == NULL)
    {
        root = new Enode(c, 999, NULL, NULL);
        temproot = root;
    }
    else
    {
        if(!(c == '+' || c == '-' || c == '*' /*|| c == '\' */))
        {
            current = temproot;
            cout << "Num: " << c << endl;
            // SET 999 TO C'S VALUE
            Enode *temp = new Enode(c, 999, NULL, NULL);
            if (current -> getLeft() == NULL)
                current -> setLeft(temp);
            else if (current -> getRight() == NULL)
            {
                current -> setRight(temp);
                temproot = root;
            }
            else
            {
                if((current -> getLeft() -> getData() == '+' || current -> getLeft() -> getData() == '-' || current -> getLeft() -> getData() == '*' /*|| current -> getLeft() -> getData() == '\' */))
                {
                    EInsert(c, current -> getLeft());
                }
                if((current -> getRight() -> getData() == '+' || current -> getRight() -> getData() == '-' || current -> getRight() -> getData() == '*' /*|| current -> getRight() -> getData() == '\' */))
                {
                    EInsert(c, current -> getRight());
                }
            }
        }
        else
        {
            current = temproot;
            cout << "Char: " << c << endl;
            system("pause");
            Enode *temp = new Enode(c, 999, NULL, NULL);
            if (current -> getLeft() == NULL)
            {
                current -> setLeft(temp);
                temproot = current -> getLeft();
            }
            else if (current -> getRight() == NULL)
            {
                current -> setRight(temp);
                temproot = current -> getRight();
            }
            else
            {
                EInsert(c, temproot -> getLeft());
                EInsert(c, temproot -> getRight());
            }
        }
    }
    print(root);
}

void Etree::print(Enode *current)
{
    //PRINT IN INFIX
    if(current == NULL)
        cout << "NOTHING TO PRINT" << endl;
    else
    {
        if (!(current -> getLeft() == NULL))
            print(current -> getLeft());
        cout << current -> getData() << " ";
        if (!(current -> getRight() == NULL))
            print(current -> getRight());
    }
}

void Etree::calculate(string c)
{
    //PRINT OUT ANSWER
    while(1)
    {

    }
}

void Etree::Menu()
{
    int choice;
    string cchoice;
    while(1)
    {
        system("cls");
        cout << "MENU" << endl << "(1) PRINT" << endl << "(2) INSERT" << endl << "(3) CALCULATE" << endl << "(4) EXIT" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                print(root);
                cout << endl;
                system("pause");
                break;
            case 2:
                cout << "ENTER A STRING: ";
                cin >> cchoice;
                root = NULL;
                for (int i = 0; i < cchoice.length(); i++)
                {
                    char temp = cchoice[i];
                    EInsert(temp, root);
                }
                system("pause");
                break;
            case 3:
                calculate(cchoice);
                system("pause");
                break;
            case 4:
                return;
        }
    }
}

int main()
{
    Etree myEtree;
    myEtree.Menu();
}
