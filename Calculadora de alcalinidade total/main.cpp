#include <iostream>

using namespace std;

int main()
{
    // ai - Alcalinidade Ideal, ae - Alcalinidade Encontrada, va - Volume de água da piscina, quant - Quantidade de bicarbonato de sódio em gramas
    float ai,ae,va,quant;
    cout << "Insira o volume de água da piscina: ";
    cin >> va;
    cout << "Insira a alcalinidade encontrada: ";
    cin >> ae;
    volta:
    cout << "Insira a alcalinidade ideal (obs: precisa ser entre 80 e 120 ppm): ";
    cin >> ai;
    if(80 < ai > 120)
    {
        cout << "Error ao inserir, você não colocou entre 80 e 120 ppm a alcalinidade ideal!" << endl;
        goto volta;
    }       
    if(ae == ai)
        cout << "Não é necessário a adição de bicarbonato de sódio!" << endl;
    if(ae > 120)
        cout << "Utilize um redutor de alcalinidade!" << endl;
    printf("A Quantidade de bicarbonato de sódio: %.2f\n",((ai-ae)*1.7)*va);
    if(ae < ai)
    {
        cout << "Quantidade necessária de alcalinidade encontrada a ser adicionada é " << (ai-ae) << endl;
    }
}