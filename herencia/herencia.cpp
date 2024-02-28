// herencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <list>

using namespace std;

class User
{
    string _username;
    string _password;
public:
    User(string username, string password) {
        _username = username;
        _password = password;
    }
    string getUsername() {
        return _username;
    }
    string getPassword() {
        return _password;
    }
};


class BaseClase
{
 protected:
    static int number;
    static list<int> numberList;
    static list<User*> userList;
};

int BaseClase::number = 5;
list<int> BaseClase::numberList = { 1,2 };
list<User*> BaseClase::userList = {new User("Boniich","123456")};

class DerivedOne : public BaseClase
{
public:
    int getNumber() {
        return number;
    }

    list<int> getList() {
        return numberList;
    }

    list<User*> getUserList() {
        return userList;
    }

    void addNewUser(const string username, const string password) {
        userList.push_back(new User(username,password));
    }

};

class DerivedTwo : public BaseClase
{
public:
    int getNumber() {
        return number;
    }

    void setNumber() {
        number = 10;
    }

};

int main()
{
    //std::cout << "Hello World!\n";
    DerivedOne derived;
    std::cout << derived.getNumber() << std::endl;
    cout << "Los item de la lista son: ";
    for (int item : derived.getList()) {
        cout << item << " ";
    }
    //std::cout << derived.getList().front() << std::endl;

    DerivedTwo derivedTwo;
    cout << endl;
    std::cout << derivedTwo.getNumber() << std::endl;
    derivedTwo.setNumber();


    std::cout << derived.getNumber() << std::endl;

    cout << "#### User list ###" << endl;
    auto user = derived.getUserList().front();
    cout << user->getUsername();

    cout << endl;
    cout << "### Agregamos un nuevo usuario desde la clase derivada one: username = GodBuffer, password = 454545" << endl;
    derived.addNewUser("GodBuffer", "454545");

    cout << "### Mostramos el ultimos usuario agregado desde la clase derivada one" << endl;
    auto user2 = derived.getUserList().back()->getUsername();
    cout << user2;

    cout << "### Mostramos la lista completa de usuarios";
    cout << endl;
    for (auto item : derived.getUserList()) {
        cout << "El usuario es: " << item->getUsername() << endl;
    }






    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
