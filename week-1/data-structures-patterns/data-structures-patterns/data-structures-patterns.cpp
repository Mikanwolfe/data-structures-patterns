#include <iostream>

int main(int argc, char* argv[] )

{
	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << " ";
	}

	std::cout << std::endl;

	//std::cout << "Hello, World!" << std::endl;

	return 0;
}