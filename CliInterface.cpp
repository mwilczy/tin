//
// Created by john on 6/7/18.
//

#include "CliInterface.h"

void CliInterface::startInterface()
{
    std::string choice;
    std::string path;
    std::string hash;

    std::cout << "Hello!" << std::endl << std::endl;
    std::cin >> choice;
    if (choice == "discover")
        discover();
    else if(choice == "ls")
    {
        std::cin >> hash;
        ls(hash);
    }
    else if(choice == "lsh")
    {
        lsh();
    }
    else if(choice == "create")
    {
        create();
    }
    else
    {
        std::cout << "You fucked up, you stupid bitch!" << std::endl;
    }

}

int CliInterface::lsh()
{
    //TODO
    return 69;
}
std::string CliInterface::ls(std::string hash)
{
    //TODO
    return hash;
}

void CliInterface::create()
{
    std::string choice;
    std::string name;
    std::string hash;
    std::string path;
    std::cin >> choice;



    if(choice == "cd")
    {
        std::cin >> path;
        if(path.empty())
        {
            std::cout << "The fuck you doing prick" << std::endl;
            return;
        }

    }
    else if(choice == "mkdir")
    {
        std::cin >> name;
        if(name.empty())
        {
            std::cout << "The fuck you doing prick" << std::endl;
            return;
        }

        mkdir(name);
    }
    else if(choice == "touch")
    {
        std::cin >> name;
        if(name.empty())
        {
            std::cout << "You stupid af!" << std::endl;
            return;
        }


    }
    else if(choice == "touch")
    {
        std::cin >> name;
        if(name.empty())
        {
            std::cout << "You stupid af!" << std::endl;
            return;
        }

    }
    else
    {
        std::cout << "chuj" << std::endl;
    }

}

std::string CliInterface::mkdir(std::string name)
{
    return name;
}

void CliInterface::cd(std::string path)
{
    std::cout << "cd wlazlo" << std::endl;
    return;
}

void CliInterface::touch(std::string name)
{
    std::cout << name << std::endl;
    return;
}

void CliInterface::publish()
{
    std::cout << "Published bitch" << std::endl;
    return;
}

void CliInterface::search(std::string hash)
{
    std::cout << "Znalazlem" <<hash << std::endl;
    return;
}

void CliInterface::download(std::string hash)
{
    std::cout << "Zasysam" << hash << std::endl;
    return;
}

int CliInterface::discover() {
    std::cout << "HOSTY:" << std::endl;

    return 0;
}

