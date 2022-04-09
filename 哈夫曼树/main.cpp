#include"哈夫曼树类.h"
#include"Copyright.h"

int main()
{
	//创建一个哈夫曼树然后读取文件
	Huffman tree;

	//将哈夫曼树构建起来
	tree.combine();

	//利用创建好的哈夫曼树，创建一个搜索数组
	tree.createLetterArray();

	//通过搜索数组展示所有编号码的值
	tree.showtotal();

	//求出这段字符串的编码
	string input = "AACDEFG";
	string temp = tree.showCode(input);

	//利用编码进行译码
	cout << endl << "解码成功，原文是" << tree.translate(temp) << endl;

	//版权信息
	Copyright();
}