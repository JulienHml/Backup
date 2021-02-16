#pragma once
#include <string>
#include <fstream>
#include <vector>


namespace julienhml
{
	class File
	{
		private:
			std::string name;
			std::ifstream file;

		public:
			File(const std::string name);
			~File();

			const std::vector<std::string> getListOfPaths();
	};
}

