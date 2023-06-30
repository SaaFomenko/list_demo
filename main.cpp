#include <iostream>
#include <list>
#include <functional>


static const unsigned int chars_size = 32;
static const std::string fail_chars_to_int = "Ошибка ввода целого числа!";

class MyException : public std::exception
{
	private:
	const std::string msg;

	public:
		MyException(const std::string msg_) : msg(msg_){}
		virtual ~MyException(){}

		const char* what() const noexcept override
		{
			return msg.c_str();
		}
};

void cin_to_int(int& number)
{
	char user_in[chars_size]{};
	std::cin >> user_in;

	if (user_in[0] == '0')
	{
		number = 0;
	}
	else
	{
		number = std::atoi(user_in);
 
		if(number == 0)
		{
			throw MyException(fail_chars_to_int);
		}
	}
}

int main()
{
	const std::string size_err = "Размер списка должен быть положительным целым числом "
		"не равным нулю, повторите ввод.\n";
	const char* in_msg = "[IN]:\n";
	const char* out_msg = "[OUT]:\n";

	unsigned int size = 0;
	int temp = 0;
	bool isSize = false;
	bool isDigit = false;

	while (!isSize)
	{
		try
		{
			std::cout << in_msg;
			cin_to_int(temp);
			if (temp <= 0)
			{
				std::cout << size_err;
			}
			else
			{
				size = static_cast<unsigned int>(temp);
				isSize = true;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::list<int> list_demo;

	for (unsigned int i = 0; i < size; ++i)
	{
		while (!isDigit)
		{
			try
			{
				cin_to_int(temp);
				isDigit = true;
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		list_demo.push_back(temp);
		isDigit = false;
	}

	list_demo.sort(std::greater<int>());
	list_demo.unique();

	std::cout << out_msg;
	for(int& elem : list_demo)
	{
		std::cout << elem << '\n';

	}

	return 0;
}
