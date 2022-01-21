/*Program to find possible solutions for a crossword puzzle
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Tree {
    char data[100];
    struct Tree * left;
    struct Tree * right;
};


//function to create a new Tree
struct Tree* create(struct Tree * root, char val[100]) {
    struct Tree * newnode = (struct Tree*)(malloc(sizeof(struct Tree)));
    root = newnode;
    strcpy(newnode->data, val);
    newnode->left = NULL;
    newnode->right = NULL;
    return root;
}


//function to insert nodes into Tree
struct Tree* insert(struct Tree* node, char val[100]) {
    struct Tree * newnode;
    struct Tree * temp;
    if (node == NULL) {
        newnode = (struct Tree * ) malloc(sizeof(struct Tree));
        strcpy(newnode->data, val);
        newnode -> left = NULL;
        newnode -> right = NULL;
        return newnode;
    }
	
	if(strcmp(node->data, val) >= 0)
    {
    	node->left = insert(node->left, val);
	}
	else
	{
		node->right = insert(node->right, val);
	}
    return node;
}


//function to find and print the solutions onto the console
void getSolutions(struct Tree* node, char* str) {
    if (node == NULL) return;
    
	getSolutions(node->left, str);
    int i;
    if(strlen(str) == strlen(node->data))
    {
		for(i = 0; i < strlen(str); i++)
		{
			if(isalpha(str[i]))
				if((str[i] != node->data[i])) break;
		}
		
		if(i == strlen(str))
			printf("%s   ", node->data);
	}
	getSolutions(node->right, str);
    return;
}


int main() {
    char str[100];
    struct Tree * root = NULL;
    struct Tree * temp;
    char words[][100] = {"India", "Guyana", "China", "USA", "England", "Algeria", "Albania", "Kuwait", "Israel", "Egypt", "Republic of Congo", "Peru", "Panama", "Vatican City", "Bhutan", "Bangladesh"};
    
    int i;
    int length = sizeof(words) / 100;
    root = create(root, words[0]);
    for(i = 1; i < length; i++)
    {
    	temp = insert(root, words[i]);
	}
    
    while(1)
    {
	    printf("Enter the incomplete word (quit() to Quit): ");
	    gets(str);
	    if(!strcmp(str, "quit()"))
	    {
	    	printf("Exiting...\n");
	    	break;
		}
		
		printf("Possible solutions are: ");
		getSolutions(root, str);
		printf("\n\n\n");
	}
    return 0;
}
