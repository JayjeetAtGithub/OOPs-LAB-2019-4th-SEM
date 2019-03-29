/**
 * Binary Search Tree
 * Created by Jayjeet Chakraborty on 01/03/2019
 */

#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
    Node *root;

    Node *_insert(Node *root, int data)
    {
        if (!root)
        {
            return new Node(data);
        }

        if (data < root->data)
        {
            root->left = _insert(root->left, data);
        }
        else
        {
            root->right = _insert(root->right, data);
        }
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    Node *_delete_node(Node *root, int data)
    {
        if (root == NULL)
            return root;

        if (data < root->data)
            root->left = _delete_node(root->left, data);

        else if (data > root->data)
            root->right = _delete_node(root->right, data);

        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                free(root);
                return temp;
            }

            Node *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = _delete_node(root->right, temp->data);
        }
        return root;
    }

    bool _search(Node *root, int data)
    {
        if (data == root->data)
        {
            return true;
        }

        if (root->left == NULL && root->right == NULL)
        {
            return false;
        }

        if (data < root->data)
        {
            _search(root->left, data);
        }
        else if (data > root->data)
        {
            _search(root->right, data);
        }
    }

    void _traverse_inorder(Node *root)
    {
        if (root)
        {
            _traverse_inorder(root->left);
            cout << root->data << "\n";
            _traverse_inorder(root->right);
        }
    }

  public:
    BST()
    {
        root = NULL;
    }

    void insert(int data)
    {
        root = _insert(root, data);
    }

    void delete_node(int data)
    {
        root = _delete_node(root, data);
    }

    bool search(int data)
    {
        return _search(root, data);
    }

    void traverse_inorder()
    {
        _traverse_inorder(root);
    }
};

int main()
{
    BST bst;
    cout << "1. Insert Node \n";
    cout << "2. Delete Node \n";
    cout << "3. Traverse Inorder \n";
    cout << "4. Find Node \n";

    while (1)
    {
        int choice, data, dec;
        cout << "Enter your choice : \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert : \n";
            cin >> data;
            bst.insert(data);
            break;

        case 2:
            cout << "Enter the data to delete : \n";
            cin >> data;
            bst.delete_node(data);
            break;

        case 3:
            cout << "Travsering Inorder : \n";
            bst.traverse_inorder();
            break;

        case 4:
            cout << "Enter the node you want to find : \n";
            cin >> data;
            cout << bst.search(data) << "\n";
            break;

        default:
            cout << "Wrong choice ! \n";
        }

        cout << "Do you want to continue (1/0) : ";
        cin >> dec;
        if (dec == 0)
        {
            break;
        }
    }
}
