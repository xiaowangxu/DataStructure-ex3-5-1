/*
 * @Date         : 2020-01-28 00:51:20
 * @Author       : ssyze
 * @Description  : 
 */
// ex3-5-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "HashList.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace TwiceCheckHashList;

int HashFunction(string &Data)
{
	int ans = 0;
	for (int i = Data.length() - 1; i >= 0; i--)
	{
		char item = Data[i];
		ans = (ans + item) % 23;
	}

	return ans;
}

int main()
{
	fstream test_file;
	test_file.open("test.txt", std::ios::in);

	HashList<string> hash_table(23, HashFunction);

	int test_case = 0;
	int item_count = 0;

	while (test_file >> item_count)
	{
		system("CLS");
		test_case++;

		cout << "Case " << test_case << " :" << endl;
		cout << "\nInsert Test\n"
			 << endl;
		for (int i = 0; i < item_count; i++)
		{
			string item;
			test_file >> item;
			hash_table.insert(item);
		}
		hash_table.print();
		cout << endl;
		system("PAUSE");
		system("CLS");

		cout << "In Case " << test_case << " :" << endl;
		cout << "\n1. Insert" << endl
			 << "2. Search" << endl
			 << "3. Delete\n"
			 << "4. Show\n"
			 << endl
			 << "Enter ActionCode : ";
		int action_code = 0;
		string item;
		while (cin >> action_code)
		{
			if (action_code <= 0 || action_code > 4)
			{
				break;
			}
			int i = 0;
			switch (action_code)
			{
			case 1:
				system("CLS");
				cout << "In Case " << test_case << " :" << endl;
				cout << "\n1. Insert\n"
					 << endl;
				cout << "Enter Item to Insert : ";
				cin >> item;
				hash_table.insert(item);
				cout << endl;
				hash_table.print();
				break;
			case 2:
				system("CLS");
				cout << "In Case " << test_case << " :" << endl;
				cout << "\n2. Search\n"
					 << endl;
				cout << "Enter Item to Search : ";
				cin >> item;
				
				if (hash_table.search(item, i) == FOUND)
				{
					cout << endl;
					cout << "Found !!\n";
				}
				else
				{
					cout << endl;
					cout << "Not Found\n";
				}
				cout << endl;
				hash_table.print();
				break;
			case 3:
				system("CLS");
				cout << "In Case " << test_case << " :" << endl;
				cout << "\n3. Delete\n"
					 << endl;
				cout << "Enter Item to Delete : ";
				cin >> item;
				hash_table.remove(item);
				cout << endl;
				hash_table.print();
				break;
			case 4:
				system("CLS");
				cout << "Case " << test_case << " :" << endl;
				cout << endl;
				hash_table.print();
				break;
			default:
				break;
			}
			cout << endl;
			system("PAUSE");
			system("CLS");
			cout << "In Case " << test_case << " :" << endl;
			cout << "\n1. Insert" << endl
				 << "2. Search" << endl
				 << "3. Delete\n"
				 << endl
				 << "Enter ActionCode : ";
		}
	}

	test_file.close();
	system("CLS");
	cout << "End of Test\n\n";
	system("PAUSE");
	system("CLS");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
