//inclui bibliotecas usadas no programa
#include <iostream>
#include <cmath>
#include <limits>

//declara as variáveis usadas no programa
double valor_presente, valor_futuro, juros;
int numero_periodos;
bool checa_Opcao_Invalida_Digitada();

bool extrai_Dados()
{
    //usuário inputa os dados

    std::cout << "Digite o valor presente: " << std::endl;
    std::cin >> valor_presente;
    if (checa_Opcao_Invalida_Digitada())
    {
        return true;
    }
    std::cout << "Digite o juros: " << std::endl;
    std::cin >> juros;
    if (checa_Opcao_Invalida_Digitada())
    {
        return true;
    }
    std::cout << "Digite o numero de periodos: " << std::endl;
    std::cin >> numero_periodos;
    if (checa_Opcao_Invalida_Digitada())
    {
        return true;
    }

    //retorna que os dados são válidos
    return false;

}

//checa opções inválidas digitadas
bool checa_Opcao_Invalida_Digitada()
{
        //lida com falhas no input
        if(std::cin.fail())
            {

                //limpa buffer de entrada
                std::cin.clear();

                //ignora a próxima linha
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                //pede para o usuário que digitou uma opção inválida, digite uma opção válida
                std::cout << "Digite uma opcao valida" << std::endl;
                
                //retorna que a opção é inválida
                return true;
            
            
            }
        else
        {

            //retorna que a opção é válida
            return false;
        
        }

}

//função que inicia o programa
int main()
{

    //loopa até o input de dados ser correto
    while(extrai_Dados()){}


    //tranforma o juros em decimal
    juros /= 100;

    //executa a conta
    valor_futuro = valor_presente * pow(1+juros, numero_periodos);

    //mostra o rwesultado
    std::cout << "O valor futuro e: " << valor_futuro << std::endl;

}