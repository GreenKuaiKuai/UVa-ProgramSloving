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
    New_node->val = new_val; //New_node�O�s���`�I 

    if (old_tree == nullptr) //�p�G�O�Ĥ@�Ӹ`�I(��)�A�^�Ǧۤv 
		return New_node; 

    Tree *parent = old_tree; //parent�ΨӰO����� 
	Tree *next = old_tree;   //next�O��Ū����l 
    while (next != nullptr) //�M��Ū����l 
	{
        parent = next;
        if (new_val > next->val) 
			next = next->right;
        else 
			next = next->left;
    }
    //���Ū����l����N�s�`�I�[�J 
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
