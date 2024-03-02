#include <iostream>
#include "controls/Factory.hpp"
#include "linux/LinuxFactory.hpp"
#include "macos/MacFactory.hpp"
#include "win/WinFactory.hpp"

using namespace std;

/*Шаблон "Фабрика" (Factory) - это паттерн проектирования, который предоставляет общий интерфейс для создания объектов, но позволяет подклассам 
решать, какой класс конкретного объекта следует создать. Это позволяет делегировать создание объектов подклассам, таким образом, обеспечивая 
более гибкую архитектуру и упрощая добавление новых типов объектов без изменения существующего кода.*/

int main()
{
    Factory *factory = new Factory(); //создает указатель на объект типа Factory
    //Цикл выбора операционной системы:
    int os = -1;
    while (os != 0) {
        cout << "Choose your OS\nWindows - 1\nLinux - 2\nMacOS - 3\nExit - 0\n";
        cin >> os;
        //В зависимости от выбранной операционной системы создается объект соответствующей фабрики.
        //Объект этой фабрики затем используется для создания элементов управления.
        switch (os) {
        case 1:
            //создает новый объект типа WinFactory и приводит его к указателю на базовый класс Factory. Такое приведение типов позволяет 
            //сохранить объект типа WinFactory в указателе типа Factory, что упрощает работу с ним
            factory = (Factory*)new WinFactory(); 
            break;
        case 2:
            factory = (Factory*)new LinuxFactory();
            break;
        case 3:
            factory = (Factory*)new MacFactory();
            break;
        }
        /*Создание элементов управления с использованием выбранной фабрики:
        Вызывается метод createButton() на объекте фабрики factory, который создает объект Button и возвращает указатель на него.
        на созданном объекте Button вызывается метод click(), который выполняет необходимое действие*/
        factory->createButton()->click(); 
        factory->createComboBox()->getItems(); //создается комбинированный список, получается список его элементов
        factory->createForm()->addControl();   //создается форма, добавляется управляющий элемент (Control) к этой форме
        factory->createLabel()->getText();     //создается метка (Label),получается текст, который отображается на этой метке
        factory->createTextBox()->getText();   //создается текстовое поле, получается текст, введенный в это текстовое поле
        cout << endl << endl;
    }
}
