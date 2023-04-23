#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct HuffmanNode
{
    char data;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct comparison
{
    bool operator()(HuffmanNode *l, HuffmanNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct HuffmanNode *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct HuffmanNode *left, *right, *top;
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, comparison> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new HuffmanNode(data[i], freq[i]));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new HuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
