#include<iostream>
#include"����������.h"
using namespace std;


//���캯��:��ʼ����̬������ַ���������
Huffman::Huffman()
{
	//���ļ�
	string path = "D:\\hafuman_test.txt", temp;
	cout << "����������ļ�Ŀ¼��������� 0 �ͻ�ʹ��Ĭ��·��  D:/hafuman_test.txt " << endl;
	cin >> temp;
	if (temp != "0") { path = temp; }

	FILE* stream;
	freopen_s(&stream, path.c_str(), "rt", stdin);

	if (stream)
	{
		cin >> numberOfNodes;

		//��ʼ����̬����(��2n-1���ڵ㣬����͸�β��û�ж�Ľڵ�)
		NodeHead = new Node[2 * numberOfNodes - 1];

		while (freePosition != 8)
		{
			cin >> NodeHead[freePosition].letter;
			cin >> NodeHead[freePosition].weight;
			freePosition++;
		}

		//��ʼ���ַ�����
		LetterHead = new Letter[numberOfNodes];

		fclose(stream);
	}
	else
	{
		cout << "�ļ���ʧ��" << endl;
		exit(0);
	}
}


//����һ���µĽڵ㲢������ھ�̬������(��С�Ҵ�)
void Huffman::putnew()
{
	//�ҵ���С�ĺ͵����ڶ�С�Ľڵ���±�
	int big, small;
	findtwo(big, small);

	//���
	NodeHead[freePosition].left = small;
	NodeHead[freePosition].right = big;
	NodeHead[freePosition].weight = NodeHead[big].weight + NodeHead[small].weight;
	
	//�޸�
	NodeHead[big].parent = freePosition;
	NodeHead[small].parent = freePosition;

	//���
	firstNode = freePosition;
	freePosition++;

}


//�ڸ��ڵ�Ϊ0������Чλ��Ľڵ������ҵ�Ȩ��С�������ڵ���±�
void Huffman::findtwo(int& big, int& small)
{
	int  one = 999999;//���Ȩ��
	big = 0;//��С
	small = 0;//��С
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

	one = 999999;//���Ȩ��
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


//�������еĽڵ�ֱ��������ýڵ�Ϊ0,����ռ��������λ��
void Huffman::combine(void)
{
	for (int i = 0; i < numberOfNodes - 1; i++)
	{
		putnew();
	}
}


//����ù�������֮��ѱ������ LetterHead ����
void Huffman::createLetterArray()
{
	LetterHead->getArray(LetterHead, NodeHead, numberOfNodes);
}


//��һ���ַ���ɹ���������
string Huffman::showCode(string input)
{
	string result = "";
	cout << "������ַ���" << endl << input << endl << "������" << endl;
	for (int i = 0; i < input.length(); i++)
	{
		result += seekcode(input[i]);
		cout << seekcode(input[i]);
	}
	cout << endl;
	return result;
}


//��һ������������ַ�
string Huffman::translate(string input)
{
	//�ַ�������
	string buffer = "";

	while (input.length() != 0)
	{
		int current = firstNode;

		//��λ
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

			//inputĩ�˴���
			input.erase(0, 1);
		}

		//��ȡ
		buffer += NodeHead[current].letter;
	}

	return buffer;
}


//�ҵ������ַ�������ı��벢����
string Huffman::seekcode(char input)
{
	for (int i = 0; i < numberOfNodes; i++)
	{
		if (NodeHead[i].letter == input)
		{
			return LetterHead[i].code;
		}
	}
	cout << "����ı������в��Ϸ����ַ�" << endl;
	exit(0);
}


//�����д������Ƶ��ַ���ӡ����
void Huffman::showtotal(void)
{
	cout << "�����ļ��е����ݹ�����������֮�󣬰��� ��С�Ҵ� �� ��0��1 ��ԭ�����������������Ϊ" << endl;
	for (int i = 0; i < numberOfNodes; i++)
	{
		cout << "�ַ�Ϊ  " << LetterHead[i].letter << endl;
		cout << "ȨΪ    " << NodeHead[i].weight << endl;
		cout << "����Ϊ  " << LetterHead[i].code << endl;
		cout << "---------------------" << endl;
	}
}