#include<iostream>
#include<string>
#include <algorithm>
#include"¹ş·òÂüÊ÷Àà.h"
using namespace std;

 
void Letter::getArray(Letter* LetterHead, Node* NodeHead, int numberOfNodes)
{
	int write = 0;
	int point;
	for (int i = 0; i < numberOfNodes; i++)
	{
		//Ğ´Èë×Ö·û
		LetterHead[write].letter = NodeHead[i].letter;

		//Ğ´Èë±àÂë
		point = i;
		read(point, LetterHead, NodeHead, write);
		
		//·´×ª±àÂë
		reverse(LetterHead[write - 1].code.begin(), LetterHead[write - 1].code.end());
	}
}


void Letter::read(int& point, Letter* LetterHead, Node* NodeHead, int& write)
{
	if (NodeHead[point].parent != 0)
	{
		if (point == NodeHead[NodeHead[point].parent].left)
		{
			LetterHead[write].code += "0";
		}
		else if (point == NodeHead[NodeHead[point].parent].right)
		{
			LetterHead[write].code += "1";
		}
		point = NodeHead[point].parent;
		read(point, LetterHead, NodeHead, write);
	}
	else
	{
		write++;
	}
}