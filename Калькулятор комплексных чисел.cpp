//Калькулятор комплексных чисел
//Основные операции над комплексными числами, модуль числа. Номер операции задается пользователем. Предусмотреть команду завершения работы с приложением.

#include <iostream>
#include <locale>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
 
typedef struct Complex {
    double Re; //действительная часть числа
    double Im; //мнимая часть числа
} z;

z summa(z z1, z z2) // операция сложения
{
    z sum;
    sum.Re = z1.Re + z2.Re;
    sum.Im = z1.Im + z2.Im;
    return sum;
}
 
z difference(z z1, z z2) // операция вычитания
{
    z diff;
    diff.Re = z1.Re - z2.Re;
    diff.Im = z1.Im - z2.Im;
    return diff;
}
 
z multiplication(z z1, z z2) //операция умножения
{
    z mult;
    mult.Re = (z1.Re * z2.Re) - (z1.Im * z2.Im);
    mult.Im = (z1.Im * z2.Re) + (z2.Im * z1.Re);
    return mult;
}
 
z division(z z1, z z2) //операция деления
{
    z div;
    div.Re = (z1.Re * z2.Re + z1.Im * z2.Im) / (pow(z2.Re,2) + pow(z2.Im,2));
    div.Im = (z1.Im * z2.Re - z2.Im * z1.Re) / (pow(z2.Re,2) + pow(z2.Im,2));
    return div;
}

z module1(z z1) //модуль 1 комплексного числа
{
	z mod1;
	mod1.Re = (z1.Re * z1.Re);
    mod1.Im = (z1.Im * z1.Im);
	return mod1;
}

z module2(z z2) //модуль 2 комплексного числа
{
	z mod2;
	mod2.Re = (z2.Re * z2.Re);
    mod2.Im = (z2.Im * z2.Im);
	return mod2;
}
	
int main() 
{
    setlocale(LC_ALL,"Russian");
    z chislo1, chislo2;
    int k;
    
    cout<<"Калькулятор комплексных чисел"<<endl;
    
   	cout<<"Введите a и b для первого комплексного числа" << endl;
   	cin>>chislo1.Re;
   	cin>>chislo1.Im;
   	cout<<"Первое комплексное число: " << chislo1.Re << " + (" << chislo1.Im << ")i" << endl;
   	cout<<"Введите a и b для второго комплексного числа" << endl;
   	cin>>chislo2.Re;
   	cin>>chislo2.Im;
   	cout<<"Второе комплексное число: " << chislo2.Re << " + (" << chislo2.Im << ")i" << endl;
   	
    cout<<"0 - Прекаращение работы"<<endl;
    cout<<"1 - Сумма комплексных чисел"<<endl;
    cout<<"2 - Разность комплексных чисел"<<endl;
    cout<<"3 - Произведение комплексных чисел"<<endl;
    cout<<"4 - Деление комплексных чисел"<<endl;
    cout<<"5 - Модули 1 комплексных чисел"<<endl;
    cout<<"6 - Модули 2 комплексных чисел"<<endl;
	z sum=summa(chislo1, chislo2);
    z diff=difference(chislo1, chislo2);
    z mult=multiplication(chislo1, chislo2);
    z div=division(chislo1, chislo2);
    z mod1=module1(chislo1);
    z mod2=module2(chislo2);
	
	
	do
	{
		cout<<"Введите номер операции ";
		cin>>k;
		switch(k)
		{
			case 1: cout<<"Сумма этих чисел = "<<sum.Re<<" + ("<< sum.Im <<")i"<<endl;break;
			case 2: cout<<"Разность этих чисел = "<<diff.Re<<" + ("<<diff.Im<<")i"<<endl;break;
			case 3: cout<<"Произведение этих чисел ="<< mult.Re<<" + ("<<mult.Im <<")i"<<endl;break;
			case 4: cout<<"Частное этих чисел (первое/второе) = "<<div.Re<<" + ("<<div.Im<<")i"<<endl;break;
			case 5: cout<<"Модуль 1 числа = "<<sqrt(mod1.Re+mod1.Im)<<endl;break;
			case 6: cout<<"Модуль 2 числа = "<<sqrt(mod2.Re+mod2.Im)<<endl;break;
			default: if (k==0) cout<<"Конец работы";
			else
			cout<<"Введите один из предложенных номеров операции"<<endl;break;
		}
	}
	while (k!=0);
    return 0;
}
