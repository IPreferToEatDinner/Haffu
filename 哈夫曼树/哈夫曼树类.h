#pragma once
#include<string>
#include<iostream>
using namespace std;

class Node
{
	friend class Huffman;
	friend class Letter;

private:
	int weight = 0;//Ȩ
	char letter = 0;//�ַ�
	int parent = 0;//����
	int left = 0;//����
	int right = 0;//�Һ���
};

class Letter
{
	friend class Huffman;

private:
	char letter = 0;//�����ַ�
	string code = "";//�����ַ��ı���

	void getArray( Letter* LetterHead, Node* NodeHead, int numberOfNodes);
	void read(int& point, Letter* LetterHead, Node* NodeHead,int& write);//���ڵݹ��ȡ
};


class Huffman
{
public:
	Huffman();//��ȡ�ļ�����ʼ����̬������ַ�����
	void showtotal(void);//չʾ���е��ַ��ͱ���(��������0��1����)
	string showCode(string);//չʾ�ض��ַ����ı���
	string translate(string);//���������ַ���
	void combine(void);//�������еĽڵ�ֱ��������ýڵ�Ϊ1,��ʱ��һ������һ������Ľڵ�
	void createLetterArray();//����ù�������֮��ѱ��������
	

private:
	string seekcode(char input);//�ҵ������ַ�������ı��벢����
	void findtwo(int& big, int& small);//�ҵ���С������
	void putnew(void);//�������ϲ�֮������µ�λ��(��С�Ҵ�)


	Node* NodeHead = nullptr;//��̬�����ͷָ��
	int firstNode = 0;//���ڴ�Ź�����Ϲ��������Ķ�ȡ�±�
	int numberOfNodes = 0;
	Letter* LetterHead = nullptr;//���ڴ�ű���ɹ����ַ�
	int freePosition = 0;//��̬�������д�����С�հ��±�
};