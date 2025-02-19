#include <iostream>
#include <Windows.h>
using namespace std;
struct BOOK {
    char author[50];
    char title[50];
    int quanty;
    float price;
};
// скидка
float discount(float price, int quanty) {
    float toprice = price * quanty;
    if (quanty >= 2 && quanty <= 4) {
        toprice *= 0.98; // 2% 
    } else if (quanty >= 5) {
        toprice *= 0.90; // 10% 
    }
    return toprice;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    BOOK books[5];
    // Ввод данных
    for (int i = 0; i < 5; i++) {
        cout << "Введите данные о книге " << (i + 1) << endl;
        cout << "Автор: ";
        cin.getline(books[i].author, 50); 
        cout << "Название: ";
        cin.getline(books[i].title, 50); 
        cout << "Количество в наличии: ";
        cin >> books[i].quanty; 
        cout << "Цена: ";
        cin >> books[i].price; 
        cin.ignore();
    }
    // Запрос инфы
    char search[50];
    int buy;
    cout << "Введите название искомой книги: ";
    cin.getline(search, 50);
    cout << "Введите количество книг, которое хотите приобрести: ";
    cin >> buy; 
    // Поиск
    bool flag = false;
    for (int i = 0; i < 5; i++) {
        bool titles = true;
        for (int j = 0; j < 50; j++) {
            if (books[i].title[j] != search[j]) {
                titles = false;
                break;
            }
            if (books[i].title[j] == '\0' && search[j] == '\0') {
                break; 
            }
        }

        if (titles) {
            flag = true;
            if (books[i].quanty >= buy) {
                cout << "Книга найдена:"<<endl;
                cout << "Автор: " << books[i].author << endl;
                cout << "Название: " << books[i].title << endl;
                cout << "Количество в наличии: " << books[i].quanty << endl;
                cout << "Цена: " << books[i].price << endl;
 
                float nemei = discount(books[i].price, buy);
                cout << "Общая стоимость покупки: " << nemei << endl;
            } else {
                cout << "Извините, недостаточно книг в наличии."<<endl;
            }
            break;
        }
    }
    if (flag==false) {
        cout << "Книга с таким названием не найдена."<<endl;
    }
    return 0;
}
