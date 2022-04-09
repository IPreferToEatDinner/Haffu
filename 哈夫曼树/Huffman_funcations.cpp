#include<iostream>
#include"哈夫曼树类.h"
using namespace std;


//构造函数:初始化静态链表和字符编码数组
Huffman::Huffman()
{
	//打开文件
	string path = "D:\\hafuman_test.txt", temp;
	cout << "请输入测试文件目录，如果输入 0 就会使用默认路径  D:/hafuman_test.txt " << endl;
	cin >> temp;
	if (temp != "0") { path = temp; }

	FILE* stream;
	freopen_s(&stream, path.c_str(), "rt", stdin);

	if (stream)
	{
		cin >> numberOfNodes;

		//初始化静态链表(有2n-1个节点，这里就给尾部没有多的节点)
		NodeHead = new Node[2 * numberOfNodes - 1];

		while (freePosition != 8)
		{
			cin >> NodeHead[freePosition].letter;
			cin >> NodeHead[freePosition].weight;
			freePosition++;
		}

		//初始化字符数组
		LetterHead = new Letter[numberOfNodes];

		fclose(stream);
	}
	else
	{
		cout << "文件打开失败" << endl;
		exit(0);
	}
}


//产生一个新的节点并且添加在静态链表上(左小右大)
void Huffman::putnew()
{
	//找到最小的和倒数第二小的节点的下标
	int big, small;
	findtwo(big, small);

	//添加
	NodeHead[freePosition].left = small;
	NodeHead[freePosition].right = big;
	NodeHead[freePosition].weight = NodeHead[big].weight + NodeHead[small].weight;
	
	//修改
	NodeHead[big].parent = freePosition;
	NodeHead[small].parent = freePosition;

	//向后
	firstNode = freePosition;
	freePosition++;

}


//在父节点为0且在有效位里的节点里面找到权最小的两个节点的下标
void Huffman::findtwo(int& big, int& small)
{
	int  one = 999999;//最大权重
	big = 0;//次小
	small = 0;//最小
	for (int i = 0; i < freePosition; i++)
	{
		if (NodeHead[i].parent != 0)
		{
			continue;
		}
		if (NodeHead[i].weight < one)
		{
			small = i;
			one = NodeHead[i].weight;
		}
	}

	one = 999999;//最大权重
	for (int i = 0; i < freePosition ; i++)
	{
		if (i == small || NodeHead[i].parent != 0)
		{
			continue;
		}
		if (NodeHead[i].weight < one)
		{
			big = i;
			one = NodeHead[i].weight;
		}
	}
}


//整合所有的节点直到空余可用节点为0,此树占满了所有位置
void Huffman::combine(void)
{
	for (int i = 0; i < numberOfNodes - 1; i++)
	{
		putnew();
	}
}


//整理好哈夫曼树之后把编码存在 LetterHead 里面
void Huffman::createLetterArray()
{
	LetterHead->getArray(LetterHead, NodeHead, numberOfNodes);
}


//将一串字符变成哈夫曼代码
string Huffman::showCode(string input)
{
	string result = "";
	cout << "输入的字符是" << endl << input << endl << "编码是" << endl;
	for (int i = 0; i < input.length(); i++)
	{
		result += seekcode(input[i]);
		cout << seekcode(input[i]);
	}
	cout << endl;
	return result;
}


//将一串代码解译变成字符
string Huffman::translate(string input)
{
	//字符串缓存
	string buffer = "";

	while (input.length() != 0)
	{
		int current = firstNode;

		//定位
		while (NodeHead[current].left != 0 || NodeHead[current].right != 0)
		{
			if (input[0] == '0')
			{
				current = NodeHead[current].left;
			}
			else
			{
				current = NodeHead[current].right;
			}

			//input末端处理
			input.erase(0, 1);
		}

		//读取
		buffer += NodeHead[current].letter;
	}

	return buffer;
}


//找到输入字符在数组的编码并返回
string Huffman::seekcode(char input)
{
	for (int i = 0; i < numberOfNodes; i++)
	{
		if (NodeHead[i].letter == input)
		{
			return LetterHead[i].code;
		}
	}
	cout << "输入的编码里有不合法的字符" << endl;
	exit(0);
}


//将所有代码完善的字符打印出来
void Huffman::showtotal(void)
{
	cout << "将此文件中的数据构建哈夫曼树之后，按照 左小右大 和 左0右1 的原则，我们输出哈夫曼树为" << endl;
	for (int i = 0; i < numberOfNodes; i++)
	{
		cout << "字符为  " << LetterHead[i].letter << endl;
		cout << "权为    " << NodeHead[i].weight << endl;
		cout << "编码为  " << LetterHead[i].code << endl;
		cout << "---------------------" << endl;
	}
}