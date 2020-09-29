// lab_1 dereva.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <queue>
#include <iostream>
using namespace std;

#include "my_list.h"

struct Node
{
    int data = 0;
    vector<Node*> children;
};
struct My_Node
{
    int data = 0;
    List<My_Node*> children;
};

class Tree
{
private:
    Node* newNode(int data)
    {
        Node* temp = new Node;
        temp->data = data;
        return temp;
    }
public:
    Node* root = NULL;

    Node* add_root(int data)
    {
        if (root != NULL)
        {
            cout << "Cannot add root" << endl;
            return root;
        }
        root = newNode(data);
        return root;
    }

    Tree(int data)
    {
        add_root(data);
    }

    Tree() {}

    ~Tree()
    {
        // TODO
    }

    
    Node* add_children(Node* parent, int data)
    {
        if (root == NULL)
            return NULL;

        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            while (n > 0)
            {

                Node* p = q.front();
                q.pop();
                //cout << p->data << " ";
                if (p == parent)
                {
                    //add a children
                    Node* new_child = newNode(data);
                    p->children.push_back(new_child);
                    return new_child;
                }

                for (int i = 0; i < p->children.size(); i++)
                    q.push(p->children[i]);
                n--;
            }
        }
        cout << "Parent node not found" << endl;
        return NULL;
        
    };
};
class My_Tree
{
private:
    My_Node* newNode(int data)
    {
        My_Node* temp = new My_Node;
        temp->data = data;
        return temp;
    }
public:
    My_Node* root = NULL;
    bool poshuk_za_znachennyam(int data)
    {
        if (root == NULL)
            return NULL;

        queue<My_Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            while (n > 0)
            {

                My_Node* p = q.front();
                q.pop();
                //cout << p->data << " ";
                if (p->data == data)
                {
                    return true;
                    
                   
                }

                List<My_Node*>::ListNode* cur_el = p->children.head;
                while (cur_el != NULL)
                {
                    q.push(cur_el->data);
                    cur_el = cur_el->pNext;
                }
                n--;
            }
        }
        return false;
    }
    
    My_Node* add_root(int data)
    {
        if (root != NULL)
        {
            cout << "Cannot add root" << endl;
            return root;
        }
        root = newNode(data);
        return root;
    }

    My_Tree(int data)
    {
        add_root(data);
    }

    My_Tree() {}

    ~My_Tree()
    {
        // TODO
    }


    My_Node* add_children(My_Node* parent, int data)
    {
        if (root == NULL)
            return NULL;

        queue<My_Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            while (n > 0)
            {
                
                My_Node* p = q.front();
                q.pop();
                //cout << p->data << " ";
                if (p == parent)
                {
                    //add a child
                    My_Node* new_child = newNode(data);
                    p->children.add(new_child);
                    return new_child;
                }

                List<My_Node*>::ListNode* cur_el = p->children.head;
                while (cur_el != NULL)
                {
                    q.push(cur_el->data);
                    cur_el = cur_el->pNext;
                }
                n--;
            }
        }
        cout << "Parent node not found" << endl;
        return NULL;

    }
};
void LevelOrderTraversal(const Tree& tree)
{
    const Node* root = tree.root;
    if (root == NULL)
        return;

    queue<const Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n > 0)
        {

            const Node* p = q.front();
            q.pop();
            cout << p->data << " ";

            for (int i = 0; i < p->children.size(); i++)
                q.push(p->children[i]);
            n--;
        }

        cout << endl;
    }
}
void LevelOrderTraversal(const My_Tree& tree)
{
    const My_Node* root = tree.root;
    if (root == NULL)
        return;

    queue<const My_Node*> q;
    q.push(root);
    
        cout << endl;
}



/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node_bin
{
    int data;
    struct Node_bin* left, * right;
    Node_bin(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

struct Binary_search_tree
{
private:
    void add_child(Node_bin* parent, int data)
    {
        if (data > parent->data)
        {
            if (parent->right == NULL)
            {
                Node_bin* child = new Node_bin(data);
                parent->right = child;
            }
            else
            {
                add_child(parent->right, data);
             }
        }
        else
        {
            if (parent->left == NULL)
            {
                Node_bin* child = new Node_bin(data);
                parent->left = child;
            }
            else
            {
                add_child(parent->left, data);
            }
        }

    }
public:
    Node_bin* root = NULL;
    void add_child(int data)
    {
        if (root == NULL)
        {
            Node_bin* t = new Node_bin(data);
            root = t;
            return;
        }
        add_child(root, data);

    }
};


/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct Node_bin* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree 
    printPostorder(node->left);

    // then recur on right subtree 
    printPostorder(node->right);

    // now deal with the node 
    cout << node->data << " ";
}


/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node_bin* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node_bin* node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}
bool search(struct Node_bin* root, int data)
{
    
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    if (root->data < data)
        return search(root->right, data);

    // Key is smaller than root's key 
    return search(root->left, data);
}





int main()
{
    /* Let us create below tree
    *       1
    *    / / \    \
    *   2 3    4    5
    *     / \  |   / |
    *    6  7  8   9 10
    */
    {
    Tree tree;
    Node* root = tree.add_root(1);
    Node* children_2 = tree.add_children(root, 2);
    Node* children_3 = tree.add_children(root, 3);
    Node* children_6 = tree.add_children(children_3, 6);
    Node* children_7 = tree.add_children(children_3, 7);
    Node* children_4 = tree.add_children(root, 4);
    Node* children_5 = tree.add_children(root, 5);
    Node* children_8 = tree.add_children(children_4, 8);
    Node* children_9 = tree.add_children(children_5, 9);
    Node* children_10 = tree.add_children(children_5, 10);
    LevelOrderTraversal(tree);
    }

    {
        My_Tree mytree;
        My_Node* root = mytree.add_root(1);
        My_Node* children_2 = mytree.add_children(root, 2);
        My_Node* children_3 = mytree.add_children(root, 3);
        My_Node* children_6 = mytree.add_children(children_3, 6);
        My_Node* children_7 = mytree.add_children(children_3, 7);
        My_Node* children_4 = mytree.add_children(root, 4);
        My_Node* children_5 = mytree.add_children(root, 5);
        My_Node* children_8 = mytree.add_children(children_4, 8);
        My_Node* children_9 = mytree.add_children(children_5, 9);
        My_Node* children_10 = mytree.add_children(children_5, 10);
        LevelOrderTraversal(mytree);
        cout << "Poshuk za znachennyam. Vvedit znachennya: " << endl;
        int p;
        cin >> p;
        
        if (mytree.poshuk_za_znachennyam(p))
        {
            cout << "Element is found" << endl;
        }
        else
            cout << "Element isn't found";
        
    }
    struct Node_bin* root = new Node_bin(1);
    root->left = new Node_bin(2);
    root->right = new Node_bin(3);
    root->left->left = new Node_bin(4);
    root->left->right = new Node_bin(5);

    

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    cout << "\nInorder traversal of binary search tree is \n";
    Binary_search_tree bst;
    bst.add_child(10);
    bst.add_child(9);
    bst.add_child(2);
    bst.add_child(14);
    bst.add_child(15);
    printInorder(bst.root);
    cout << endl;
    cout << "Vvedit element dlya binarnogo poshuku" << endl;
    int g;
    cin >> g;
    if (search(bst.root, g)) cout << "Element is found" << endl;
    else cout << "Element isn't found." << endl;
   
    return 0;

  
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
