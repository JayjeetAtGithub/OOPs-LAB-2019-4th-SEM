#include <bits/stdc++.h>
#define int long long
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

  public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(int data)
    {
        // Inserts a Node in Linked List
        if (!head)
        {
            head = new Node(data);
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new Node(data);
        }
    }

    void display()
    {
        if (!head)
        {
            cout << "Empty List\n";
        }
        else
        {
            // Displays the Linked List
            cout << "Contents Of Linked List List : \n";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "\n";
                temp = temp->next;
            }
        }
    }

    void del_beg()
    {
        // Delete a Node from beginning
        if (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void del_end()
    {

        // Delete a Node from end
        if (head != NULL && head->next == NULL)
        {
            del_beg();
            return;
        }
        if (head != NULL)
        {
            Node *temp = head;
            Node *prev = NULL;
            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            prev->next = NULL;
        }
    }
};

int32_t main()
{
    LinkedList *list = new LinkedList();
    list->insert(10);
    list->insert(11);
    list->insert(16);
    list->display();
    list->del_end();
    list->display();
    list->del_beg();
    list->display();
}
