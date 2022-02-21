#include <map>

#include<iostream>

#include<iomanip>

#include <string> ///

#include <sstream>

#include <algorithm>

#include <fstream>



using namespace std;

string mystr;

int n;



class Man//Man

{

public:

    Man() {}

    ~Man() {}

    string famely;

    string name;

    string fatherName;

    string adres;

    string tel;



    void setFamely(string myfamely) { famely = myfamely; }

    string getfamely() { return famely; }



    void setName(string myname) { name = myname; }

    string getName() { return name; }



    void setFatherName(string myfatherName) { fatherName = myfatherName; }

    string getFatherName() { return fatherName; }



    void setadres(string myadres) { adres = myadres; }

    string getadres() { return adres; }



    void settel(string mytel) { tel = mytel; }

    string gettel() { return tel; }



};



void setPassword(Man& ob)

{



    ofstream fout;

    fout.open("password.txt", std::ofstream::app);

    cout << setw(15) << " Insert login: ";

    cin >> mystr;

    fout << mystr << std::endl;

    cout << setw(15) << " Insert password(only numbers) of login: ";

    cin >> n;

    fout << n << std::endl;

    cout << "Insert all name of users:\n";

    cout << setw(10) << "Name:\n              ";

    cin >> mystr;

    ob.setName(mystr);

    fout << mystr << std::endl;

    cout << setw(10) << "famely:\n              ";

    cin >> mystr;

    ob.setFamely(mystr);

    fout << mystr << std::endl;

    cout << setw(10) << "fatherName:\n              ";

    cin >> mystr;

    ob.setFatherName(mystr);

    fout << mystr << std::endl;

    cout << ob.getName() << " ";

    cout << ob.getfamely() << " ";

    cout << ob.getFatherName() << " " << endl;

    fout.close();

}



void checkPassword()

{



    ifstream file("password.txt");

    string s;

    char c;



    while (!file.eof()) {

        file.get(c);

        s.push_back(c);

    }



    file.close();

    cout << " Введите логин пользователя" << endl;

    cin >> mystr;

    int pos = s.find(mystr); // поиск



    if (pos == -1)

        cout << "not finded" << endl;

    else

    {

        cout << " account is valid " << endl;

        cout << pos << endl;

    }

    cout << " Введите пароль пользователя" << endl;

    cin >> n;



}



class Admin : public Man

{

public:

};



class Users : public Man

{

public:

};



void Showmenu1() {

    cout << endl;

    cout << " Сделайте выбор" << endl;

    cout << "1. Ввести нового пользователя" << endl;

    cout << "2. Очистить экран" << endl;

    cout << "3. Ввойти как пользователь" << endl;

    cout << "4. Ввойти как admin" << endl;

    cout << "0. Выход" << endl;

}



void Showmenu2() {

    cout << endl;

    cout << " Сделайте выбор" << endl;

    cout << "1. Просмотреть задание " << endl;

    cout << "2. Прошлые результаты" << endl;

    cout << "3. Продолжить тестирование" << endl;

    cout << "4. Пройти новое тестирование" << endl;

    cout << "0. Выход" << endl;

}







int main()

{

    setlocale(LC_ALL, "");

    cout << "First start for admin:\n";

    int menu = 77;

    map <int, string> mp;  //массив для хранения логинов

    int count = 0; //количество пользователей



    Admin myadmin;

    setPassword(myadmin);

    do {

        Showmenu1();

        cin >> menu;

        switch (menu)

        {

        case 1: {

            Users myusers;

            setPassword(myusers);

            break;

        }

        case 2: {

            system("cls");

            break;
        }

        case 3: {
            checkPassword();
            Showmenu2();
            break;
        }
       case 4: {

            cout << " Введите логин админа" << endl;

            cin >> mystr;

            cout << " Введите пароль админа" << endl;

            cin >> n;

            break;

        }
        default:
           break;
       }
    } while (menu != 0);
    return 0;
}