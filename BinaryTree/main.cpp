#include <iostream>
#include <windows.h>

using namespace std;

COORD coord={0,0};

 void gotoxy(int x,int y) {
 	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

class Leaf
{
    private:
        string letter;
        Leaf *left;
        Leaf *right;
        int depth;
    public:
        Leaf(string c, Leaf *l, Leaf *r, int d)
        {
            letter = c;
            left = l;
            right = r;
            depth = d;
        }
        string getLetter()
        {
            return letter;
        }
        Leaf* getLeft()
        {
            return left;
        }
        Leaf* getRight()
        {
            return right;
        }
        int getDepth()
        {
            return depth;
        }
        void setLetter(char d)
        {
            letter = d;
        }
        void setLeft(Leaf *l)
        {
            left = l;
        }
        void setRight(Leaf *r)
        {
            right = r;
        }
        void setDepth(int d)
        {
            depth = d;
        }
};

class Tree
{
    private:
        Leaf *root;
    public:
        Tree()
        {
            root = NULL;
        }
        void Insert(string c, Leaf *current, int depth);
        void print(Leaf *current);
        void Menu();
        void printTree(Leaf *current, int depth);
        int maxDepth(Leaf *current);
};

void Tree::Insert(string c, Leaf *current, int depth)
{
    if (root == NULL)
    {
        root = new Leaf(c, NULL, NULL, 0);
    }
    else
    {
        if (c > current -> getLetter())
        {
            if (current -> getRight() == NULL)
            {
                Leaf *temp = new Leaf(c, NULL, 0);
                current -> setRight(temp);
                return;
            }
            Insert(c, current -> getRight(), depth);
        }
        else if (c <= current -> getLetter())
        {
            if (current -> getLeft() == NULL)
            {
                Leaf *temp = new Leaf(c, NULL, NULL);
                current -> setLeft(temp);
                return;
            }
            Insert(c, current -> getLeft(), depth);
        }
    }
}

void Tree::print(Leaf *current)
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

int Tree::maxDepth(Leaf *current)
{
    if (current == NULL)
    {
        return 0;
    }
    int leftHeight = maxDepth(current -> getLeft());
    int rightHeight = maxDepth(current -> getRight());
    if (leftHeight > rightHeight)
        return leftHeight;
    else
        return rightHeight;
}

//void Tree::printTree(Leaf *current, int depth)
//{
//    if(current == NULL)
//        cout << "NOTHING TO PRINT" << endl;
//    else
//    {
//        if ((!(current -> getLeft() == NULL)) && current -> getDepth() == depth)
//            print(current -> getLeft(), depth);
//        for (int i = depth; i > 0; i--;)
//        cout << current -> getLetter() << " ";
//        if ((!(current -> getRight() == NULL)) && current -> getDepth() == depth)
//            print(current -> getRight(), depth);
//        depth++;
//    }
//}

void Tree::Menu()
{
    int choice;
    string cchoice, temp = " ";
    while(1)
    {
        system("cls");
        cout << "MENU" << endl << "(1) PRINT ALPHABETICALLY" << endl << "(2) PRINT TREE" << endl << "(3) ADD" << endl << "(4) EXIT" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                print(root);
                system("pause");
                break;
            case 2:
                cout << maxDepth(root) << endl;
                //print(root, 0);
                system("pause");
                break;
            case 3:
                cout << "ENTER A STRING: ";
                cin >> cchoice;
                for (int i = 0; i < cchoice.length(); i++)
                {
                    temp = cchoice[i];
                    Insert(temp, root, 0);
                }
                cout << endl;
                system("pause");
                break;
            case 4:
                return;
        }
    }
}

int main()
{
    Tree myTree;
    myTree.Menu();
}
