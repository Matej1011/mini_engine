#include <iostream>
#include "engine.h"


int main() {

	mini_engine::engine e;
	try {
		e.run();
	}
	catch (std::exception e){
		std::cout << e.what();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}