#include <iostream>
#include <windows.h>

using namespace std;

class Node
{
    private:
        int data;
        Node *next;
    public:
        Node(int d, Node *n)
        {
            data = d;
            next = n;
        }
        int getData()
        {
            return data;
        }
        Node* getNext()
        {
            return next;
        }
        void setData(int n)
        {
            data = n;
        }
        void setNext(Node *x)
        {
            next = x;
        }
};

class List
{
    private:
        Node *first;
    public:
        List()
        {
            first = NULL;
        }
        void Add(int num);
        void Remove(int num);
        void print();
        void trial();
        void Menu();
};

void List::trial()
{
    cout << "Hello" << endl;
    cout << first << endl; // Counter-intuitive, nothing has been created yet   NULL defined as 0 when cout
    first = new Node(5, NULL); // new is a command word to initialize a new object
    cout << first << endl;
    cout << first -> getData() << endl;
    cout << first -> getNext() << endl;
    Node *temp = new Node(12,NULL);
    cout << temp -> getData() << endl;
    first -> setNext(temp);
    cout << temp << endl;
    cout << first -> getNext() << endl;
    cout << first -> getNext() -> getData() << endl;
    Node *potter = new Node(666, NULL);
    temp -> setNext(potter);
    cout << first -> getNext() -> getNext() -> getData() << endl;
    Node *current = first; // Setting current to same address of first
    cout << current -> getData() << endl;
    current = current -> getNext(); // Slider : Current = temp
    cout << current -> getData() << endl;
                                        // Erase last: If next doors next door is null, set current's next to be null
}

void List::Menu()
{
    int choice, nchoice;
    while(1)
    {
        system("cls");
        cout << "MENU" << endl << "(1) PRINT" << endl << "(2) ADD" << endl << "(3) REMOVE" << endl << "(4) EXIT" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                print();
                break;
            case 2:
                cout << "ENTER A NUMBER: ";
                cin >> nchoice;
                Add(nchoice);
                break;
            case 3:
                cout << "ENTER A NUMBER: ";
                cin >> nchoice;
                Remove(nchoice);
                break;
            case 4:
                return;
        }
    }
}

void List::print()
{
    Node *current = first;
    if(current == NULL)
        cout << "NOTHING TO PRINT" << endl;
    else
    {
        while(current != NULL)
        {
            cout << current -> getData() << " ";
            current = current -> getNext();
        }
        cout << endl;
    }
    system("pause");
}

void List::Add(int num)
{
    if(first == NULL)
    {
        first = new Node(num, NULL);
    }
    else
    {
        if(num <= first -> getData())
        {
            Node *temp = new Node(first -> getData(), first -> getNext());
            first -> setData(num);
            first -> setNext(temp);
        }
        else
        {
            Node *current = first;
            while (current != NULL)
            {
                if (current -> getNext() == NULL && current -> getData() <= num)
                {
                    Node *temp = new Node(num, NULL);
                    current -> setNext(temp);
                    return;
                }
                else if(current -> getData() <= num && current -> getNext() -> getData() >= num)
                {
                    Node *temp = new Node(num, current -> getNext());
                    current -> setNext(temp);
                    return;
                }
                current = current -> getNext();
            }
        }
    }
}

void List::Remove(int num)
{
    Node *current = first;
    if (current == NULL)
    {
        cout << "DUMMY, THERE IS NO LIST!" << endl;
        system("pause");
        return;
    }
    while (current != NULL)
    {
        if (current -> getData() == num)
        {
            break;
        }
        else if (current -> getNext() == NULL && current -> getData() != num)
        {
            cout << "NOT IN LIST" << endl;
            system("pause");
            return;
        }
        current = current -> getNext();
    }
    if (first -> getNext() == NULL && first -> getData() == num)
    {
        first = NULL;
    }
    else if (first -> getData() == num)
    {
        first -> setData(first -> getNext() -> getData());
        first -> setNext(first -> getNext() -> getNext());
        return;
    }
    else
    {
        Node *current = first;
        while (current != NULL)
        {
            if (current -> getNext() -> getData() == num && current -> getNext() -> getNext() == NULL)
            {
                current -> setNext(NULL);
                return;
            }
            else if (current -> getNext() -> getData() == num)
            {
                current -> setNext(current -> getNext() -> getNext());
                return;
            }
            current = current -> getNext();
        }
    }
}

int main()
{
    List mylist;
    mylist.trial();
    mylist.Menu();
    return 0;
}
