#include <iostream>
#include <vector>

void addItem(std::vector<std::string>& inventory)
{
    std::string input;
    std::cin >> input;

    inventory.push_back(input);
}

void useItem(std::vector<std::string>& inventory)
{
    ;
}

void dropItem(std::vector<std::string>& inventory)
{
    ;
}

void clearInventory(std::vector<std::string>& inventory)
{
    ;
}

void outputInventory(std::vector<std::string>& inventory)
{
    std::cout << "\nИнвентарь: \n";

    for(int i = 0; i < inventory.size(); i++)
    {
        std::cout << (i+1) << ") " << inventory[i] << '\n';
    }

    std::cout << '\n';
}

void display(std::vector<std::string>& inventory)
{
    short int input;

    do
    {
        outputInventory(inventory);

        std::cout << "Выберите действие в инвентаре:\n";
        std::cout << "1 - Использовать предмет\n";
        std::cout << "2 - Выбросить предмет\n";
        std::cout << "3 - Очистить инвентарь\n";
        std::cout << "4 - Выход из инвентаря\n";

        std::cout << "\n> ";
        std::cin >> input;
        std::cout << '\n';

        if(input == 1) useItem(inventory);
        else if(input == 2) dropItem(inventory);
        else if(input == 3) clearInventory(inventory);
        else if(input == 4) break;
        else std::cout << "\nОшибка ввода!\n\n";
    } while(true);
}

int main()
{
    std::vector<std::string> inventory;
    short int input;

    do
    {
        std::cout << "Выберите действие:\n";
        std::cout << "1 - Добавить предмет\n";
        std::cout << "2 - Показать инвентарь\n";
        std::cout << "3 - Выход\n";

        std::cout << "\n> ";
        std::cin >> input;

        if(input == 1)
        {
            std::cout << "\nВведите название предмета: ";
            addItem(inventory);
            std::cout << '\n';
        }
        else if(input == 2) display(inventory);
        else if(input == 3) break;
        else std::cout << "\nОшибка ввода!\n\n";
    } while (true);
}