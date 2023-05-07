#include <iostream>
#include <string.h>

#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"


bool checkBalanceBrackets(const std::string text, const int maxDeep);

int main()
{

    int size = 0;
    int choice = 0;
    int count = 0;
    std::cout << "Input size:";
    std::cin >> size;
    limStack<int> test(size);
    while (true)
    {
        std::cout << "\n1 - Add\n" << "2 - Remove\n"
            << "3 - Check\n" << "4 - Exit : ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << std::endl << "Enter number : ";
            std::cin >> count;
            test.push(count);
            std::cout << "Stack:";
            test.print();
            break;
        case 2:
            test.pop();
            std::cout << "Stack:";
            test.print();
            break;
        case 3:
            if (test.isEmpty() == true)
                std::cout << "True\n";
            else
            {
                std::cout << "False\n";
            }
            break;
        case 4:
            break;
        default:
            std::cerr << "Wrong number!";
            exit(-1);
        }
        if (choice == 4) break;

        


    }


    std::cout << "\nInput size queue:";
    std::cin >> size;
    QueueArray <int> qtest(size+1);
    std::cout  << "\n1 - Add\n" << "2 - Remove\n"
        << "3 - Check\n" << "4 - Exit : ";
    while (true)
    {
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << std::endl << "Enter number : ";
            std::cin >> count;
            qtest.enQueue(count);
            std::cout << "Queue:";
            qtest.print();
            break;
        case 2:
            qtest.deQueue();
            std::cout << "Queue:";
            qtest.print();
            break;
        case 3:
            if (qtest.isEmpty() == true)
                std::cerr << "True";
            else
            {
                std::cout << "False";
            }
            std::cout << std::endl;
            break;
        case 4:
            break;
        default:
            std::cerr << "Wrong number!";
            exit(-1);
        }
        if (choice == 4) break;

        std::cout << "\n1 - Add\n" << "2 - Remove\n"
            << "3 - Check\n" << "4 - Exit : ";


    }

    std::cout << std::endl;
    std::string text;
    std::cout << "Enter the string:";
    std::cin >> text;
    int number;
    std::cout << "Enter the count:";
    std::cin >> number;
    if (checkBalanceBrackets(text, number) == true)
        std::cout << "False";
    else
        std::cout << "True";

}

bool checkBalanceBrackets(const std::string text, const int maxDeep) {

    std::pair<char, char> static const type_brackets[] = {
        {'(',')'},
        {'[',']'},
        {'{','}'}
    };

    size_t brackets_size = sizeof(type_brackets) / sizeof(type_brackets[0]);
    limStack<char> brackets(maxDeep);

    for (size_t i = 0; i < text.length(); i++) {
        for (size_t j = 0; j < brackets_size; j++) {
            if (text[i] == type_brackets[j].first) {
                brackets.push(j);
                break;
            }
            else if (text[i] == type_brackets[j].second) {
                if (brackets.isEmpty() || brackets.top() != j)
                    return true;
                brackets.pop();
                break;
            }
        }
    }

    if (!brackets.isEmpty())
        return true;

    return false;
}