/*Program to check if entered string is a palindrome or not, using array.
*/

#include<stdio.h>
#include<string.h>

//Takes in a string and returns 1 if string is palindrome and 0 otherwise
int isPalindrome(char* str)
{
	int length = strlen(str);
	int i;
	for(i = 0; i < length / 2; i++)
	{
		if(str[i] != str[length - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

//Driver function
int main()
{
	char str[100];
	printf("Enter a string: ");
	gets(str);
	int flag = isPalindrome(str);
	if(flag)
	{
		printf("%s is a palindrome \n", str);
	}
	else
	{
		printf("%s is not a palindrome \n", str);
	}
	return 0;
}
