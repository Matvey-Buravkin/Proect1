//����������� ����������� �����
//�������� �������� ��� ������������ �������, ������ �����. ����� �������� �������� �������������. ������������� ������� ���������� ������ � �����������.

#include <iostream>
#include <locale>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
 
typedef struct Complex {
    double Re; //�������������� ����� �����
    double Im; //������ ����� �����
} z;

z summa(z z1, z z2) // �������� ��������
{
    z sum;
    sum.Re = z1.Re + z2.Re;
    sum.Im = z1.Im + z2.Im;
    return sum;
}
 
z difference(z z1, z z2) // �������� ���������
{
    z diff;
    diff.Re = z1.Re - z2.Re;
    diff.Im = z1.Im - z2.Im;
    return diff;
}
 
z multiplication(z z1, z z2) //�������� ���������
{
    z mult;
    mult.Re = (z1.Re * z2.Re) - (z1.Im * z2.Im);
    mult.Im = (z1.Im * z2.Re) + (z2.Im * z1.Re);
    return mult;
}
 
z division(z z1, z z2) //�������� �������
{
    z div;
    div.Re = (z1.Re * z2.Re + z1.Im * z2.Im) / (pow(z2.Re,2) + pow(z2.Im,2));
    div.Im = (z1.Im * z2.Re - z2.Im * z1.Re) / (pow(z2.Re,2) + pow(z2.Im,2));
    return div;
}

z module1(z z1) //������ 1 ������������ �����
{
	z mod1;
	mod1.Re = (z1.Re * z1.Re);
    mod1.Im = (z1.Im * z1.Im);
	return mod1;
}

z module2(z z2) //������ 2 ������������ �����
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
    
    cout<<"����������� ����������� �����"<<endl;
    
   	cout<<"������� a � b ��� ������� ������������ �����" << endl;
   	cin>>chislo1.Re;
   	cin>>chislo1.Im;
   	cout<<"������ ����������� �����: " << chislo1.Re << " + (" << chislo1.Im << ")i" << endl;
   	cout<<"������� a � b ��� ������� ������������ �����" << endl;
   	cin>>chislo2.Re;
   	cin>>chislo2.Im;
   	cout<<"������ ����������� �����: " << chislo2.Re << " + (" << chislo2.Im << ")i" << endl;
   	
    cout<<"0 - ������������ ������"<<endl;
    cout<<"1 - ����� ����������� �����"<<endl;
    cout<<"2 - �������� ����������� �����"<<endl;
    cout<<"3 - ������������ ����������� �����"<<endl;
    cout<<"4 - ������� ����������� �����"<<endl;
    cout<<"5 - ������ 1 ����������� �����"<<endl;
    cout<<"6 - ������ 2 ����������� �����"<<endl;
	z sum=summa(chislo1, chislo2);
    z diff=difference(chislo1, chislo2);
    z mult=multiplication(chislo1, chislo2);
    z div=division(chislo1, chislo2);
    z mod1=module1(chislo1);
    z mod2=module2(chislo2);
	
	
	do
	{
		cout<<"������� ����� �������� ";
		cin>>k;
		switch(k)
		{
			case 1: cout<<"����� ���� ����� = "<<sum.Re<<" + ("<< sum.Im <<")i"<<endl;break;
			case 2: cout<<"�������� ���� ����� = "<<diff.Re<<" + ("<<diff.Im<<")i"<<endl;break;
			case 3: cout<<"������������ ���� ����� ="<< mult.Re<<" + ("<<mult.Im <<")i"<<endl;break;
			case 4: cout<<"������� ���� ����� (������/������) = "<<div.Re<<" + ("<<div.Im<<")i"<<endl;break;
			case 5: cout<<"������ 1 ����� = "<<sqrt(mod1.Re+mod1.Im)<<endl;break;
			case 6: cout<<"������ 2 ����� = "<<sqrt(mod2.Re+mod2.Im)<<endl;break;
			default: if (k==0) cout<<"����� ������";
			else
			cout<<"������� ���� �� ������������ ������� ��������"<<endl;break;
		}
	}
	while (k!=0);
    return 0;
}
