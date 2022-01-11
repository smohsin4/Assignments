/*Book Management System implemetation using Singly Linked List
*/
#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct Node
{
	int id;
	char name[30];
	struct Node* next;
}*head, *temp, *newNode, *nextNode;


//function to insert a node
void insertNode()
{
	int position;
	while(1)
	{
		printf("Enter the position to store the Book (Press 0 to go back to main menu): ");
		scanf("%d", &position);
		if(position == 0)
		{
			return;
		}
		if(position > count + 1)
		{
			printf("ERROR: Invalid position entered.\n\n");
			continue;
		}
		break;
	}
	
	temp = head;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter Book ID: ");
	scanf("%d", &newNode->id);
	while(temp != NULL)
	{
		if(temp->id == newNode->id)
		{
			printf("This book already exists in List.\n\n");
			return;
		}
		temp = temp->next;
	}
	temp = head;
	printf("Enter Book title: ");
	scanf("%s", newNode->name);
	
	if(head == NULL)
	{
		head = newNode;
		newNode->next = head->next = NULL;
		count++;
		return;
	}
	
	if(position == 1)
	{
		newNode->next = head;
		head = newNode;
		count++;
		return;
	}
	int i = 1;
	while(i < position - 1)
	{
		temp = temp->next;
		i++;
	}
	
	newNode->next = temp->next;
	temp->next = newNode;
	count++;
	
	return;
}


//function to delete a node
void deleteNode()
{
	int position;
	while(1)
	{
		printf("Enter the position to delete the Book(Press 0 to go back to main menu): ");
		scanf("%d", &position);
		if(position == 0)
		{
			return;
		}
		if(position > count)
		{
			printf("Invalid position. %d books exist in List\n", count);
			continue;
		}
		break;
	}
	
	temp = head;
	int i = 1;
	while(i < position - 1)
	{
		temp = temp->next;
		i++;
	}
	
	nextNode = temp->next;
	temp->next = nextNode->next;
	free(nextNode);
	nextNode = NULL;
	count--;
	printf("Book successfully deleted\n\n");
	return;
}


//function to print all nodes on console
void display()
{
	if(head == NULL)
	{
		printf("Book list is empty\n");
		return;
	}
	
	temp = head;
	printf("Displaying all available books: \n");
	while(temp != NULL)
	{
		printf("ID: %d - Title: %s \n", temp->id, temp->name);
		temp = temp->next;
	}
	printf("\n");
	return;
}


//function to search for a node in SLL
void search()
{
	if(head == NULL)
	{
		printf("Book list is empty\n");
		return;
	}
	
	int choice;
	while(1)
	{
		printf("Search by? \n1: ID \n2: Position  \n0: Main Menu   \nEnter choice: ");
		scanf("%d", &choice);
		if(choice == 1)
		{
			int id;
			printf("Enter Book ID: ");
			scanf("%d", &id);
			temp = head;
			while(temp != NULL)
			{
				if(temp->id == id)
				{
					printf("Book found.  \nBook ID: %d and Title: %s\n\n", temp->id, temp->name);
					return;
				}
				temp = temp->next;
			}
			printf("No book found\n\n");
			return;
		}
		
		if(choice == 2)
		{
			int position;
			printf("Enter position: ");
			scanf("%d", &position);
			if(position > count)
			{
				printf("Invalid position entered. Going back to main menu.\n\n");
				return;
			}
			int i = 1;
			temp = head;
			
			while(i < position)
			{
				printf("HERE");
				temp = temp->next;
				i++;
			}
			printf("Book found.  \nBook ID: %d and Title: %s\n\n", temp->id, temp->name);
			return;
		}
		if(choice == 0)
		{
			return;
		}
		printf("ERROR: Invalid choice entered.\n");
	}
	return;
}


//Driver function
int main()
{
	int choice;

	
	while(1)
	{
		printf("Menu: \n");
		printf("1: Insert\n2: Delete\n3: View all Books\n4: Search for a Book\n5: Quit...\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: {
				insertNode();
				break;
			}
			case 2: {
				deleteNode();
				break;
			}
			case 3: {
				display();
				break;
			}
			case 4: {
				search();
				break;
			}
			case 5: {
				exit(1);
				break;
			}
			default: {
				printf("Incorrect input. Please try again\n\n");
				break;
			}
		}
	}
	return 0;
}
