#include <iostream>
#include <list>
//#include <cstring>


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
	
	number = std::atoi(user_in);

	if(number == 0)
	{
		throw MyException(fail_chars_to_int);
	}
}

int main()
{
	const char* in_msg = "[IN]:\n";
	const char* out_msg = "[OUT]:\n";

	int size = 0;
	bool isSize = false;

	while (!isSize)
	{
		try
		{
			std::cout << in_msg;
			cin_to_int(size);
			isSize = true;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << out_msg << size << '\n';

	return 0;
}
