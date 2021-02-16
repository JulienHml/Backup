#include "File.hpp"
#include "Save.hpp"

#include <iostream>
#include <exception>
#include <vector>
#include <string>


int main()
{
    std::cout << "-- Backup v1.0.0 --\n" << std::endl;

    try {
        julienhml::File inputFolders("input_folders.txt");
        julienhml::File outputFolder("output_folder.txt");

        julienhml::Save myBackup(inputFolders.getListOfPaths(), outputFolder.getListOfPaths().front());
        myBackup.start();

        std::cout << "\nThe backup is complete, check the generated directory -> \"" + myBackup.getNameOfGeneratedFolder() + "\"" << std::endl;
        std::cout << "You can compress it and place it in an encrypted hard drive" << std::endl;
        system("pause");
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        system("pause");
        return 1;
    }

    return 0;
}