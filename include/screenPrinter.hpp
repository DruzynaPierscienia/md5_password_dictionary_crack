#pragma once

#include "IPasswordsOutput.hpp"
#include <iostream>
#include <string>

class screenPrinter :IPasswordsOutput {
	public:
		void sendPassword(std::string const& password);	
};

