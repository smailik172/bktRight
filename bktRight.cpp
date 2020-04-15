// bktRight.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stack>



class bkt
{
private:
	static char bktOp[3];
	static char bktCl[3];
	static bool bktOpen(char c)
	{
		for (auto k : bkt::bktOp)
		{
			if (c == k)
				return true;
		}
		return false;
	}
	static char bktRevers(char c)
	{
		for (int i = 0; i < sizeof(bkt::bktCl) / sizeof(bkt::bktCl[0]); i++)
		{
			if (c == bkt::bktCl[i])
				return bkt::bktOp[i];
			if (c == bkt::bktOp[i])
				return bkt::bktCl[i];
		}
		return c;
	}
public:
	static bool checkRight(std::string line)
	{
		std::stack<char> stackBkt;
		for (int i = 0; i < line.size(); i++)
		{
			if (bktOpen(line[i]))  //есть скобка открывающая
				stackBkt.push(line[i]);  //добавляем в стек
			else if (bktOpen(bktRevers(line[i])))  //если скобка закрывающая
				if (!stackBkt.empty())  //проверяем, есть ли скобки в стеке, иначе return false
				{
					if (line[i] == bktRevers(stackBkt.top()))  //проверяем, совпадает ли тип скобок, да - вынимаем из стека, иначе return false
						stackBkt.pop();
					else
						return false;
				}
				else
					return false;
		}
		if (!stackBkt.empty())
			return false;
		else
			return true;
	}
};

char bkt::bktOp[] = { '(','[','{' };
char bkt::bktCl[] = { ')',']','}' };

int main()
{
	std::string line;
	std::cout << "Input line\n";
	getline(std::cin, line);
	if (bkt::checkRight(line))
		std::cout << "Right\n";
	else
		std::cout << "Wrong\n";
	getchar();
	return 0;
}