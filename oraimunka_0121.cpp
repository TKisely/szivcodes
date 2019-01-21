// oramunka_0121.cpp 

#include <iostream>

using namespace std;

int main()
{
	char tomb[100] = "norqipenwabhqxygapjtuevfufnsyfwkibhlfrzpefpnisqnvmbtcbogcqtspednjbpbghahujfrxobntdedydyjlzrmaljeneo";
	for (int i = 0; i < 100; i++)
	{
		if (tomb[i] == 'e') {
			cout << " ";
		}
		else if (tomb[i] == 'n') {
			cout << '\n';
		}
		else {
			cout << tomb[i];
		}

	}


    std::cout << "Hello World!\n"; 
}
