#include <bits/stdc++.h>
#define int long long
using namespace std;

// Node struct
struct Node
{
    int freq;
    int data;
    Node *left, *right;
};

// unordered_map to store the data mapped to code
unordered_map<int, string> umap;

// custom compare function
struct cmp
{
    bool operator()(Node *x, Node *y)
    {
        return x->freq > y->freq;
    }
};

// function to traverse the tree
void traverse(Node *root, string str)
{
    if (root)
    {
        // if root is a leaf Node
        if (!root->left && !root->right)
        {
            umap[root->data] = str;
            // store the code in the map
            return;
        }
        traverse(root->left, str + '0');
        traverse(root->right, str + '1');
    }
}

// function to create and return a new Node
Node *create()
{
    Node *p = new Node;
    return p;
}

// display function
void huffman(Node *root)
{
    if (root)
    {
        if ((!(root->left)) && (!(root->right)))
        {
            cout << umap[root->data] << " ";
            return;
        }
        huffman(root->left);
        huffman(root->right);
    }
}

int32_t main()
{
    int t, i, n, x;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        n = s.length();
        Node *p;
        priority_queue<Node *, vector<Node *>, cmp> pq;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            p = create();
            p->freq = x;
            p->left = NULL;
            p->right = NULL;
            p->data = i;
            pq.push(p);
        }
        while (pq.size() > 1)
        {
            Node *l = pq.top();
            pq.pop();
            Node *r = pq.top();
            pq.pop();
            Node *ptr = create();
            ptr->left = l;
            ptr->right = r;
            ptr->data = min(l->data, r->data);
            ptr->freq = l->freq + r->freq;
            pq.push(ptr);
        }
        // traverse(pq.top()->left, "0");
        traverse(pq.top(), "");
        huffman(pq.top());
        cout << endl;
    }
}
