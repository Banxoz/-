#include <iostream>
#include <string>
#include <Windows.h> 
using namespace std;
struct BOOK {
    string author;
    string title;
    int quantity;
    double price;
};
// Расчета скидки
double discount(double totalCost, int quantity) {
    if (quantity >= 5) {
        return totalCost * 0.90; //10%
    }
    else if (quantity >= 2) {
        return totalCost * 0.98; //2%
    }
    return totalCost; // Без
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    BOOK books[5];

    // Ввод данных о книгах
    for (int i = 0; i < 5; ++i) {
        cout << "Книга " << i + 1 << ":"<<endl;
        cout << "  Автор: ";
        getline(cin, books[i].author);
        cout << "  Название: ";
        getline(cin, books[i].title);
        cout << "  Количество: ";
        cin >> books[i].quantity;
        cout << "  Цена: ";
        cin >> books[i].price;
        cin.ignore();
    }

    // Поиск книги
    string searchTitle;
    int searchquantity;
    cout << "\nВведите название книги: ";
    getline(cin, searchTitle);
    cout << "Введите количество: ";
    cin >> searchquantity;

    bool flag = false;
    for (const auto& book : books) {
        if (book.title == searchTitle) {
            flag = true;
            if (book.quantity >= searchquantity) {
                double totalCost = book.price * searchquantity;
                double finalCost = discount(totalCost, searchquantity); // расчет скидки

                cout << "Книга найдена:"<<endl;
                cout << "  Автор: " << book.author <<endl;
                cout << "  Название: " << book.title << endl;
                cout << "  Стоимость: " << finalCost << " руб." << endl;
            }
            else {
                cout << "Недостаточно книг в наличии.\n";
            }
            break;
        }
    }

    if (flag == false) {
        cout << "Книга с названием \"" << searchTitle << "\" не найдена.\n";
    }

    return 0;
}