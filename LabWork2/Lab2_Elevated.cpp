// Подключаем библиотеки для ввода/вывода.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

int main() // Объявляем главную функцию.
{
	double a; // Создаём переменную для хранения значения стороны a.
	double b; // Создаём переменную для хранения значения стороны b.
	double c; // Создаём переменную для хранения значения стороны c.
	// Используем double, так как стороны треугольника могут быть дробными числами.
	// При работе с double возможна небольшая погрешность представления некоторых дробных чисел.
	// При использовании очень больших чисел типа double возможна потеря точности или переполнение.

	std::cout << "Enter the a: "; // Запрашиваем у пользователя значение стороны a.
	std::cin >> a; // Считываем введённое значение в переменную a.

	// Проверяем, что пользователь ввёл число.
	if (std::cin.fail())
	{
		// Сбрасываем состояние ошибки ввода.
		std::cin.clear();

		// Удаляем некорректные данные из буфер ввода.
		std::cin.ignore(
			std::numeric_limits < std::streamsize > ::max(), '\n');

		std::cout << "Error a number must be entered." << std::endl;

		return 1;
	}

	// Проверяем граничное значение: сторона треугольника не может быть отрицательной.
	if (a <= 0)
	{
		std::cout << "Error: A valid number must be entered." << std::endl;

		return 1;
	}

	std::cout << "Enter the b: "; // Запрашиваем у пользователя значение стороны b.
	std::cin >> b; // Считываем введённое значение в переменную b.

	// Проверяем, что пользователь ввёл число.
	if (std::cin.fail())
	{
		// Сбрасываем состояние ошибки ввода.
		std::cin.clear();

		// Удаляем некорректные данные из буфер ввода.
		std::cin.ignore(
			std::numeric_limits < std::streamsize > ::max(), '\n');

		std::cout << "Error a number must be entered." << std::endl;

		return 1;
	}

	// Проверяем граничное значение: сторона треугольника не может быть отрицательной.
	if (b <= 0)
	{
		std::cout << "Error: A valid number must be entered." << std::endl;

		return 1;
	}

	std::cout << "Enter the c: "; // Запрашиваем у пользователя значение стороны c.
	std::cin >> c; // Считываем введённое значение в переменную c.

	// Проверяем, что пользователь ввёл число.
	if (std::cin.fail())
	{
		// Сбрасываем состояние ошибки ввода.
		std::cin.clear();

		// Удаляем некорректные данные из буфер ввода.
		std::cin.ignore(
			std::numeric_limits < std::streamsize > ::max(), '\n');

		std::cout << "Error a number must be entered." << std::endl;

		return 1;
	}

	// Проверяем граничное значение: сторона треугольника не может быть отрицательной.
	if (c <= 0)
	{
		std::cout << "Error: A valid number must be entered." << std::endl;

		return 1;
	}

	// Проверяем сущестует ли треуголь ник с заданными сторонами.
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		std::cout << "Error: A triangle with these sides cannot exist." << std::endl;
		return 1;
	}

	// Вычисление по формуле Герона с double.

	double p = (a + b + c) / 2.0; 
	// Формула полурпериметра вычисляет через double для сохранения точности.
	// Деление на 2.0 (а не на 2) — корректное вещественное деление.

	double Sdouble = sqrt(static_cast<double>(p) * static_cast<double>(p - a) * static_cast<double>(p - b) * static_cast<double>(p - c)); 
	// Пишем формулу Герона.
	// Используем static_cast<double> для явного приведения аргумента sqrt.
	// Хотя p и стороны уже double, static_cast демонстрирует понимание механизма явного приведения типов.

	// Вычисление по формуле Герона с float.

	float pfloat = (static_cast<float>(a) + static_cast<float>(b) + static_cast<float>(c)) / 2.0f;
	// При вычитании близких чисел в float теряются значащие цифры — это называется катастрофической отменой (catastrophic cancellation).

	float Sfloat = sqrt(static_cast<float>(pfloat) * static_cast<float>(pfloat - static_cast<float>(a)) * static_cast<float>(pfloat - static_cast<float>(b)) * static_cast<float>(pfloat - static_cast<float>(c)));
	
	// Сравниваем результаты вычислений в float и double. 
	// Разница показывает влияние точности типа данных. 
	double difference = std::fabs(Sdouble - static_cast<double>(Sfloat));

	// Форматируем вещественные числа: fixed выводит число в обычном десятичном формате, setprecision(6) оставляет шесть знаков после запятой.
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Square (double): " << Sdouble << std::endl;
	std::cout << "Square (float):  " << Sfloat << std::endl; // Выводим результат.
	std::cout << "Difference: " << difference << std::endl;

	return 0; // Успешное завершение программы.
}