#include <bits/stdc++.h>
using namespace std;
struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, int freq)
    {
 
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};
void printCodes(struct MinHeapNode* root, string str)
{
 
    if (!root)
        return;
 
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int f[], int size)
{
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
 
    for (int i = 0; i < size; ++i)
    {
        MinHeapNode* x=new MinHeapNode(data[i],f[i]);
        minHeap.push(x);
    }
    while (minHeap.size() != 1) {
 
        MinHeapNode* left = minHeap.top();
        minHeap.pop();
 
        MinHeapNode* right = minHeap.top();
        minHeap.pop();
        
        MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}
int main()
{
 
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int f[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCodes(arr, f, size);
 
    return 0;
}
