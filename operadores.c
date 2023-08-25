#include <stdio.h>
#include <math.h>
#include <time.h>

int currentDay, currentMonth, currentYear;

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};

void operators()
{
    int num1, num2, soma, sub, mult;
    float div;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    clearBuffer();

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    clearBuffer();

    soma = num1 + num2;
    sub = num1 - num2;
    mult = num1 * num2;
    div = (float)num1 / num2;

    printf("Soma: %d\n", soma);
    printf("Subtracao: %d\n", sub);
    printf("Multiplicacao: %d\n", mult);
    printf("Divisao: %.2f\n", div);
};

void doubleNumber()
{
    int number;
    printf("Digite um numero: ");
    scanf("%d", &number);
    clearBuffer();
    printf("O dobro desse numero e: %d\n", number*2);
};

void calculateArea()
{
    int largura, comprimento;
    float area;
    printf("Digite a largura: ");
    scanf("%d", &largura);
    clearBuffer();
    printf("Digite o comprimento: ");
    scanf("%d", &comprimento);
    clearBuffer();

    area = (float)largura * comprimento;
    printf("A area e: %.2f%s\n", area, "m²");
};

void convertDolar()
{
    float dolar, real;
    printf("Digite o valor em reais: ");
    scanf("%f", &real);
    dolar = real / 4.95;
    printf("R$ %.2f em dolar: $ %.2f\n", real, dolar);
};

void calculateProfit()
{
    int preco, frete, despesas, precoVenda;
    printf("Digite o preco da mercadoria em reais: ");
    scanf("%d", &preco);
    printf("Digite o custo do frete: ");
    scanf("%d", &frete);
    printf("Digite despesas: ");
    scanf("%d", &despesas);
    preco += frete + despesas;
    printf("Digite o valor de venda: ");
    scanf("%d", &precoVenda);

    printf("O lucro em cima da venda e de: %d reais\n", precoVenda - preco);
};

void calculateCircleRadius()
{
    int raio;
    double area;
    printf("Digite o raio do circulo: ");
    scanf("%d", &raio);

    area = 3.14 * pow(raio, 2);

    printf("A area do circulo e: %f\n", area);
};

void getYear()
{
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);

    currentYear = localTime->tm_year + 1900;
    currentMonth = localTime->tm_mon + 1;
    currentDay = localTime->tm_mday;
};

void ageInDays()
{
    getYear();
    int birthYear, birthMonth, birthDay;
    printf("Data de nascimento do estudante...\n");
    printf("dia: ");
    scanf("%2d", &birthDay );
    clearBuffer();
    
    printf("mes: ");
    scanf("%2d", &birthMonth );
    clearBuffer();
    
    printf("ano: ");
    scanf("%4d", &birthYear );
    clearBuffer();

    int year = currentYear - birthYear;
    if(currentMonth < birthMonth || (currentMonth == birthMonth && currentDay != birthDay)) year--;

    int years = year*365;
    int months = currentMonth*30;

    if(currentMonth == birthMonth) months = months - (30 - birthDay);
    else months -= 30 - currentDay;
   
   int ageInDays = years + months;

    printf("Sua idade em dias e: %d dias\n", ageInDays);
};

void monthlySalary()
{
    int salario;
    int percentual;
    printf("Digite seu salario mensal: ");
    scanf("%d", &salario);
    printf("Qual o percentual de reajuste? ");
    scanf("%d", &percentual);

    int reajuste = salario * percentual;
    salario = salario + (reajuste/100);
    printf("Seu salário com o reajuste e: %d\n", salario);
};

void calculateCarCost()
{
    float carCost;
    int factoryCost;
    float distributorPercent = (float)28 / 100;
    float taxesPercent = (float)45 / 100;

    printf("Digite o custo de fabrica do carro: ");
    scanf("%d", &factoryCost);
    
    carCost = factoryCost + (distributorPercent * factoryCost) + (taxesPercent * factoryCost);
    printf("O carro custa: %.2f com as taxas aplicadas\n", carCost);
};

void calculateEmployeesSalary()
{
    int amountSelledCars;
    int totalMoneyReceived;
    int salary;
    int valueByCar;
    printf("Digite a quantidade de carros vendidos: ");
    scanf("%d", &amountSelledCars);
    printf("Digite o valor total das vendas: ");
    scanf("%d", &totalMoneyReceived);
    printf("Digite o salario fixo: ");
    scanf("%d", &salary);
    printf("Digite o valor por carro vendido: ");
    scanf("%d", &valueByCar);

    float finalSalary = salary + (valueByCar * amountSelledCars) + (totalMoneyReceived * (5/100));

    printf("Salario final: %.2f\n", finalSalary);
};

int main()
{
    printf("Escolha uma opcao: \n");
    printf("1 - soma, subtracao, multiplicacao, divisao\n");
    printf("2 - dobro do numero\n");
    printf("3 - area de uma sala\n");
    printf("4 - converter real para dolar\n");
    printf("5 - lucro de mercadoria\n");
    printf("6 - calcular a area de um circulo\n");
    printf("7 - idade em dias\n");
    printf("8 - salario reajustado\n");
    printf("9 - calcular custo de carro\n");
    printf("10 - calcular salario final do vendedor\n");
    int option;

    scanf("%2d", &option);
    clearBuffer();

    switch(option)
    {
        case 1: 
        {
            operators();
            break;
        }
        case 2: 
        {
            doubleNumber();
            break;
        }
        case 3: 
        {
            calculateArea();
            break;
        }
        case 4: 
        {
            convertDolar();
            break;
        }
        case 5: 
        {
            calculateProfit();
            break;
        }
        case 6: 
        {
            calculateCircleRadius();
            break;
        }
        case 7: 
        {
            ageInDays();
            break;
        }
        case 8: 
        {
            monthlySalary();
            break;
        }
        case 9: 
        {
            calculateCarCost();
            break;
        }
        case 10: 
        {
            calculateEmployeesSalary();
            break;
        }
    };

    return 0;
};