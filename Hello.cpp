#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#include <limits.h>
#include "LL.h"


void run() {
	srand((unsigned)time(NULL));
	LL list1{};
	LL list2{};
	int tmp[5];
	std::string strBuild = "";
	for (int i = 0; i < 10; i++) {
		int tmp = rand()%100;
		std::string tmpStr = std::to_string(tmp);
		strBuild += tmpStr + " ";
		list1.pushBack(tmp);
		list2.pushFront(tmp);
	}
	std::cout << "nums generated: " << strBuild << std::endl;
	std::cout << "list created  : " << list1 << std::endl;
	std::cout << "backward list : " << list2 << std::endl;
}

int main(int argc, const char * argv[]) {
	try {
		run();
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

