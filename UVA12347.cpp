#include <cstdio>
#include <iostream>
using namespace std;

struct Tree
{
    int val = 0;
    Tree *left = nullptr;
    Tree *right = nullptr;
};

Tree *Insert(Tree *old_tree, int new_val)
{
    Tree *New_node = new Tree;
    New_node->val = new_val; //New_node是新的節點 

    if (old_tree == nullptr) //如果是第一個節點(根)，回傳自己 
		return New_node; 

    Tree *parent = old_tree; //parent用來記住父母 
	Tree *next = old_tree;   //next記住空的葉子 
    while (next != nullptr) //尋找空的葉子 
	{
        parent = next;
        if (new_val > next->val) 
			next = next->right;
        else 
			next = next->left;
    }
    //找到空的葉子之後將新節點加入 
    if (new_val > parent->val)
		parent->right = New_node;
    else 
		parent->left = New_node;
	//printf("work\n");	
    return old_tree;
}

void Post_Order(Tree *node)
{
    if (node == nullptr) return;
    Post_Order(node->left);
    Post_Order(node->right);
    printf("%d\n", node->val);
}

int main()
{
    Tree *myTree = nullptr;
    int input;
    while (cin>>input)
	{
		myTree = Insert(myTree,input);
	}
	printf("1 done\n");
    Post_Order(myTree);
    printf("2 done\n");
    return 0;
}
