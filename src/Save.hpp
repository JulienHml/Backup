#pragma once
#include <vector>
#include <string>


namespace julienhml
{
	class Save
	{
		private:
			std::vector<std::string> inputPaths;
			std::string outputPath;
			std::string nameGeneratedFolder;

		public:
			Save(const std::vector<std::string>& fileOfInputPaths, const std::string& fileOfOutputPath);
			~Save();

			void start();
			const std::string getNameOfGeneratedFolder();

			static bool isPathExist(const std::string& path);

	};
}

