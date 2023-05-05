#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "");
    bool block = 0;
    // Местоположение шашек
    std::vector<int> white_rook;
    std::vector<int> white_elephant;
    std::vector<int> black_king;
    std::cout << "Введите координаты чёрного короля по горизонтали и вертикали (цифрами) слитно: ";
    std::string input_str;
    std::cin >> input_str;
    for (char c : input_str) {
        black_king.push_back(c - '0');
    }

    std::cout << "Введите координаты белого слона по горизонтали и вертикали (цифрами) слитно: ";
    std::cin >> input_str;
    for (char c : input_str)
    {
        white_elephant.push_back(c - '0');
    }

    std::cout << "Введите координаты белого ладьи по горизонтали и вертикали (цифрами) слитно: ";
    std::cin >> input_str;
    for (char c : input_str)
    {
        white_rook.push_back(c - '0');
    }

    // Проверка на правильность расположения шашек
    bool valid_positions = true;
    for (int i = 0; i < 2; i++)
    {
        if (black_king[i] < 1 || black_king[i] > 8 ||
            white_elephant[i] < 1 || white_elephant[i] > 8 ||
            white_rook[i] < 1 || white_rook[i] > 8)
        {
            valid_positions = false;
            break;
        }
    }

    if (!valid_positions)
    {
        std::cout << "Ошибка: координаты шашек должны быть в пределах 1-8\n";
        return 1;
    }

    // Проверка условия №1
    if (((white_rook[0] != black_king[0]) && (white_rook[1] != black_king[1])) && (fabs(white_elephant[0] - black_king[0]) != fabs(white_elephant[1] - black_king[1])))
    {
        std::cout << "Короля не атакует никакая фигура\n";
        return 0;
    }

    if (white_rook[0] == black_king[0] || white_rook[1] == black_king[1]) {                                          //Проверка условия №2 
        if (((white_elephant[0] == white_rook[0] && white_rook[0] == black_king[0]) || (white_elephant[1] == white_rook[1] && white_rook[1] == black_king[1])) &&                                           //Уточняющее условие №1
            (((white_elephant[1] > white_rook[1] && black_king[1] > white_elephant[1]) || (white_elephant[1] < white_rook[1] && black_king[1] < white_elephant[1])) || ((white_elephant[0] > white_rook[0] && black_king[0] > white_elephant[0]) || (white_elephant[0] < white_rook[0] && black_king[0] < white_elephant[0])))) 
        {
            std::cout << "Слон перекрывает шах от ладьи\n";
        }
        else
        {
            std::cout << "Ладья объявляет шах королю\n";
           
        }
    }

    if (fabs(white_elephant[0] - black_king[0]) == fabs(white_elephant[1] - black_king[1])) { //Проверка условия №3  
        if ((fabs(white_rook[0] - white_elephant[0]) == fabs(white_rook[1] - white_elephant[1]) && fabs(black_king[0] - white_rook[0]) == fabs(black_king[1] - white_rook[1])) && //Уточняющее условие №2
            (((white_rook[1] > white_elephant[1]) && (black_king[1] > white_rook[1])) || ((white_rook[1] < white_elephant[1]) && (black_king[1] < white_rook[1]))))
        {
            std::cout << "Ладья перекрывает шах от слона\n";
        }
        else
        {
            std::cout << "Слон объявляет шах королю\n";
           
        }
    }

    return 0;
}