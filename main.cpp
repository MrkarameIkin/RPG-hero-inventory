#include <iostream>
#include <vector>

void addItem(std::vector<std::string>& inventory)
{
    std::string input;
    std::cin >> input;

    inventory.push_back(input);
}

void outputInventory(std::vector<std::string>& inventory)
{
    int quantity;

    std::cout << "\nИнвентарь: \n";

    if(inventory.size() == 1)
    {
        std::cout << "1) " << inventory.back();
    }
    else
    {
        std::vector<std::string> buffer = inventory;

        for(int count = 0; buffer.size() != 0; count++)
        {
            quantity = 1;

            for(int j = 1; j < buffer.size(); j++)
            {
                if(buffer[0] == buffer[j])
                {
                    quantity++;
                    buffer.erase(buffer.begin() + j);
                    j--;
                }
            }

            std::cout << (1+count) << ") " << buffer[0];
            
            if(quantity != 1) std::cout << " x" << quantity;
            std::cout << std::endl;

            if(!buffer.empty()) buffer.erase(buffer.begin());
            else break;
        }
    }

    std::cout << "\n\n";
}

void useItem(std::vector<std::string>& inventory)
{
    int input;
    outputInventory(inventory);

    std::cout << "Введите номер предмета, который вы хотите использовать: ";
    std::cin >> input;
    
    if(input >= 1 and input <= inventory.size())
    {
        std::cout << "\nПредмет " << inventory[input - 1] << " был использован!\n\n";
        inventory.erase(inventory.begin() + input - 1);
    }
    else std::cout << "\nОшибка ввода!\nПопробуйте снова\n\n";
}

void dropItem(std::vector<std::string>& inventory)
{
    int input;
    outputInventory(inventory);

    std::cout << "Введите номер предмета, который вы хотите выбросить: ";
    std::cin >> input;
    
    if(input >= 1 and input <= inventory.size())
    {
        std::cout << "\nПредмет " << inventory[input - 1] << " был Выброшен!\n\n";
        inventory.erase(inventory.begin() + input - 1);
    }
    else std::cout << "\nОшибка ввода!\nПопробуйте снова\n\n";
}

void clearInventory(std::vector<std::string>& inventory)
{
    std::string input;

    std::cout << "Вы уверены, что хотите очистить свой инвентарь? (Да/Нет)\n";
    std::cin >> input;
    
    if(input == "Да" or input == "да")
    {
        std::cout << "\nИнвентарь был очищен!\n\n";
        inventory.resize(0);
    }
    else if(input == "Нет" or input == "нет") return;
    else std::cout << "Ошибка ввода!\n";
}

void display(std::vector<std::string>& inventory)
{
    char input;

    do
    {
        if(inventory.empty()) break;

        outputInventory(inventory);

        std::cout << "Выберите действие в инвентаре:\n";
        std::cout << "1 - Использовать предмет\n";
        std::cout << "2 - Выбросить предмет\n";
        std::cout << "3 - Очистить инвентарь\n";
        std::cout << "4 - Выход из инвентаря\n";

        std::cout << "\n> ";
        std::cin >> input;
        std::cout << '\n';

        if(input == '1') useItem(inventory);
        else if(input == '2') dropItem(inventory);
        else if(input == '3') clearInventory(inventory);
        else if(input == '4') break;
        else std::cout << "\nОшибка ввода!\n\n";
    } while(true);
}

int main()
{
    std::vector<std::string> inventory;
    char input;

    do
    {
        std::cout << "Выберите действие:\n";
        std::cout << "1 - Добавить предмет\n";
        std::cout << "2 - Инвентарь\n";
        std::cout << "3 - Выход\n";

        std::cout << "\n> ";
        std::cin >> input;

        if(input == '1')
        {
            std::cout << "\nВведите название предмета: ";
            addItem(inventory);
            std::cout << '\n';
        }
        else if(input == '2')
        {
            if(inventory.empty()) std::cout << "\nИнвентарь пуст!\n\n";
            else display(inventory);
        }
        else if(input == '3') break;
        else std::cout << "\nОшибка ввода!\n\n";
    } while (true);
}