#include <iostream>
using namespace std;

struct Node
{
    int row;
    int col;
    int data;
    Node *nxt;
};

Node *createNode(Node *p, int ridx, int cidx, int x)
{
    Node *temp = new Node();
    temp->row = ridx;
    temp->col = cidx;
    temp->data = x;
    temp->nxt = NULL;

    if (p == NULL)
    {
        p = temp;
    }
    else
    {
        Node *r = p;
        while (r->nxt != NULL)
            r = r->nxt;
        r->nxt = temp;
    }
    return p;
}

void print(Node *init)
{
    Node *ptr = init;
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->nxt;
    }
    cout << endl;

    ptr = init;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->nxt;
    }
    cout << endl;
    ptr = init;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->nxt;
    }
}

int main()
{
    int i = 0;
    int sparse_matrix[4][5] =
        {{0, 0, 3, 0, 4},
         {0, 0, 5, 7, 0},
         {0, 0, 0, 0, 0},
         {0, 2, 6, 0, 0}};

    Node *init = NULL;
    while (i < 4)
    {
        int j = 0;
        while (j < 5)
        {
            if (sparse_matrix[i][j] != 0)
                init = createNode(init, i, j, sparse_matrix[i][j]);
            j++;
        }
        i++;
    }
    print(init);
}
