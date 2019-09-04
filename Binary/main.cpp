#include <iostream>
#include <windows.h>

using namespace std;

class Bnode
{
    private:
        string letter;
        Bnode *left;
        Bnode *right;
    public:
        Bnode(string d, Bnode *l, Bnode *r)
        {
            letter = d;
            left = l;
            right = r;
        }
        string getLetter()
        {
            return letter;
        }
        Bnode* getLeft()
        {
            return left;
        }
        Bnode* getRight()
        {
            return right;
        }
        void setLetter(char d)
        {
            letter = d;
        }
        void setLeft(Bnode *l)
        {
            left = l;
        }
        void setRight(Bnode *r)
        {
            right = r;
        }
};

class Btree
{
    private:
        Bnode *root;
    public:
        Btree()
        {
            root = NULL;
        }
        void Insert(string c, Bnode *current);
        void print(Bnode *current);
        void Menu();
};

void Btree::Insert(string c, Bnode *current)
{
    if (root == NULL)
    {
        root = new Bnode(c, NULL, NULL);
    }
    else
    {
        if (c > current -> getLetter())
        {
            if (current -> getRight() == NULL)
            {
                Bnode *temp = new Bnode(c, NULL, NULL);
                current -> setRight(temp);
                return;
            }
            Insert(c, current -> getRight());
        }
        else if (c <= current -> getLetter())
        {
            if (current -> getLeft() == NULL)
            {
                Bnode *temp = new Bnode(c, NULL, NULL);
                current -> setLeft(temp);
                return;
            }
            Insert(c, current -> getLeft());
        }
    }
}

void Btree::print(Bnode *current)
{
    if(current == NULL)
        cout << "NOTHING TO PRINT" << endl;
    else
    {
        if (!(current -> getLeft() == NULL))
            print(current -> getLeft());
        cout << current -> getLetter() << " ";
        if (!(current -> getRight() == NULL))
            print(current -> getRight());
    }
}

void Btree::Menu()
{
    int choice;
    string cchoice, temp = " ";
    while(1)
    {
        cout << "MENU" << endl << "(1) PRINT" << endl << "(2) ADD" << endl << "(3) EXIT" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                print(root);
                system("pause");
                cout<<"Pottercheck:"<<root->getRight()->getLeft()->getLeft()->getLetter();
                break;
            case 2:
                cout << "ENTER A STRING: ";
                cin >> cchoice;
                root = NULL;
                for (int i = 0; i < cchoice.length(); i++)
                {
                    temp = cchoice[i];
                    Insert(temp, root);
                }
                break;
            case 3:
                return;
        }
        cout << endl;
    }
}

int main()
{
    Btree myBtree;
    myBtree.Menu();
}
