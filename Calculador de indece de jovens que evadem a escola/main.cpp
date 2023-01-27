#include <iostream>

using namespace std;
#define quantidade 50

struct jovem
{
    char genero;
    bool trabalha;
};

int main()
{
    int trabalho[4] = {0,0,0,0};
    /*
        Posições no array "trabalho":
        0 - Homens que trabalham
        1 - Homens que não trabalham
        2 - Mulheres que trabalham
        3 - Mulheres que não trabalham
    */
    jovem j[quantidade];
    cout << "--Formulário de pesquisa--" << endl;
    for(int i = 0; i < quantidade; i++)
    {
        volta1:
        cout << "Insira o gênero da " << i+1 << "ª pessoa, (exemplo: m-Masculino ou f-feminino):";
        cin >> j[i].genero;
        if(j[i].genero == 'm' || j[i].genero == 'f' || j[i].genero == 'M' || j[i].genero == 'F')
        {
        }else{
            cout << "Gênero escolhido inválido!" << endl;
            goto volta1;
        }
        cout << "Esse jovem trabalha?(exemplo: 0-não ou 1-sim):";
        cin >> j[i].trabalha; 
    }
    for(int i = 0; i < quantidade; i++)
    {
        if(j[i].genero == 'm' || j[i].genero == 'M')
        {
            if(j[i].trabalha)
                trabalho[0]++;
            else
                trabalho[1]++;
        }
        if(j[i].genero == 'f' || j[i].genero == 'F')
        {
            if(j[i].trabalha)
                trabalho[2]++;
            else
                trabalho[3]++;
        }
    }
    cout << "Homens que não trabalham são " << (trabalho[1]*100)/quantidade << "%" <<endl;
    cout << "Homens que trabalham são " << (trabalho[0]*100)/quantidade << "%" << endl;
    cout << "Mulheres que não trabalham são " << (trabalho[3]*100)/quantidade << "%" <<endl;
    cout << "Mulheres que trabalham são " << (trabalho[2]*100)/quantidade << "%" << endl;
}