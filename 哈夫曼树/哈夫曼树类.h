#pragma once
#include<string>
#include<iostream>
using namespace std;

class Node
{
	friend class Huffman;
	friend class Letter;

private:
	int weight = 0;//权
	char letter = 0;//字符
	int parent = 0;//父类
	int left = 0;//左孩子
	int right = 0;//右孩子
};

class Letter
{
	friend class Huffman;

private:
	char letter = 0;//这是字符
	string code = "";//这是字符的编码

	void getArray( Letter* LetterHead, Node* NodeHead, int numberOfNodes);
	void read(int& point, Letter* LetterHead, Node* NodeHead,int& write);//用于递归读取
};


class Huffman
{
public:
	Huffman();//读取文件并初始化静态链表和字符数组
	void showtotal(void);//展示所有的字符和编码(编码是左0右1读法)
	string showCode(string);//展示特定字符串的编码
	string translate(string);//将代码变成字符串
	void combine(void);//整合所有的节点直到空余可用节点为1,此时有一个树与一个空余的节点
	void createLetterArray();//整理好哈夫曼树之后把编码存起来
	

private:
	string seekcode(char input);//找到输入字符在数组的编码并返回
	void findtwo(int& big, int& small);//找到最小的两个
	void putnew(void);//将两树合并之后放在新的位置(左小右大)


	Node* NodeHead = nullptr;//静态链表的头指针
	int firstNode = 0;//用于存放构建完毕哈夫曼树的读取下标
	int numberOfNodes = 0;
	Letter* LetterHead = nullptr;//用于存放编码成功的字符
	int freePosition = 0;//静态链表可以写入的最小空白下标
};