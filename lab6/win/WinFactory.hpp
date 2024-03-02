#pragma once

#include "WinControls.hpp"
#include "../controls/Factory.hpp"

/*определяет класс WinFactory, который является конкретной реализацией интерфейса Factory. Этот интерфейс определяет методы
для создания различных элементов пользовательского интерфейса. Каждый метод createX() возвращает указатель на объект определенного типа X, 
который является одним из элементов пользовательского интерфейса.WinFactory реализует каждый из этих методов, создавая объекты конкретных 
классов WinControls.Каждый метод создает новый объект соответствующего элемента пользовательского интерфейса и возвращает указатель на него.*/
class WinFactory : public Factory {
public:
	Button* createButton() {
		return (Button*)new WinButton();
	};
	ComboBox* createComboBox() {
		return (ComboBox*)new WinComboBox();
	};
	Form* createForm() {
		return (Form*)new WinForm();
	};
	Label* createLabel() {
		return (Label*)new WinLabel();
	};
	TextBox* createTextBox() {
		return (TextBox*)new WinTextBox();
	};
};
