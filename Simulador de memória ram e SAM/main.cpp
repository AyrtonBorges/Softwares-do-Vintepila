#include <iostream>
#include <fstream>
#include <ctime>
#include <limits>
#include <chrono>

const char* arquivo = "arquivo.txt";

using namespace std;

string *entrada(int tamanho);
float ram(int tamanho);

string *entrada_SAM(int tamanho);
float sam(int tamanho);

int main()
{
    float tempo[6];
    cout << "Memória RAM de 10 posições: " << endl;
    tempo[0] = ram(10);
    cout << "Memória RAM de 50 posições: " << endl;
    tempo[1] = ram(50);
    cout << "Memória RAM de 100 posições: " << endl;
    tempo[2] = ram(100);
    cout << "Memória SAM de 10 posições: " << endl;
    tempo[3] = sam(10);
    cout << "Memória SAM de 50 posições: " << endl;
    tempo[4] = sam(50);
    cout << "Memória SAM de 100 posições: " << endl;
    tempo[5] = sam(100);

    cout << "\n\nResultado final:" << endl;
    cout << "Memória RAM de 10 posições teve " << tempo[0] << " ms" << endl;
    cout << "Memória RAM de 50 posições teve " << tempo[1] << " ms" << endl;
    cout << "Memória RAM de 100 posições teve " << tempo[2] << " ms" << endl;
    cout << "Total da memória RAM deu " << (tempo[0]+tempo[1]+tempo[2]) << " ms" << endl;
    cout << "A média da memória RAM deu " << ((tempo[0]+tempo[1]+tempo[2])/3) << " ms" << endl;
    cout << "Memória SAM de 10 posições teve " << tempo[3] << " ms" << endl;
    cout << "Memória SAM de 50 posições teve " << tempo[4] << " ms" << endl;
    cout << "Memória SAM de 100 posições teve " << tempo[5] << " ms" << endl;
    cout << "Total da memória SAM deu " << (tempo[3]+tempo[4]+tempo[5]) << " ms" << endl;
    cout << "A média da memória SAM deu " << ((tempo[3]+tempo[5]+tempo[5])/3) << " ms" << endl;
}

/*

    Memória RAM

*/

string *entrada(int tamanho)
{
    string *saida = new string[tamanho];
    int quantidade = 0;
    ifstream fp(arquivo);
    srand(time(NULL));
    if(fp.is_open())
    {
        int posicoes[tamanho];
        int posicao = rand()%tamanho;
        while(getline(fp,saida[posicao]))
        {  
            posicoes[quantidade] = posicao;
            volta:
            bool achou = false;
            posicao = rand()%tamanho;
            for(int i = 0; i < tamanho; i++)
            {
                
                if(posicao == posicoes[i])
                    achou = true;
            }
            if(achou && quantidade != tamanho-1)
                goto volta;
            quantidade++;
            if(quantidade > tamanho-1)
                break;
        }
        fp.close();
    }else
    {
        cout << "Arquivo não encontrado, programa encerrando!" << endl;
        exit(0);
    }
    return saida;
}
float ram(int tamanho)
{
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using std::chrono::duration;
    using chrono::milliseconds;
    bool passou = true;
    float saida_int;
    string *saida = new string[tamanho];
    saida = entrada(tamanho);
    for(int i = 0; i < tamanho; i++)
    {
        if(saida[i] != "")
            cout << i+1 << " " << saida[i] << endl;
    }
    srand(time(NULL));
    
    do
    {
        int escolha = 0;
        cout << "Escolha 1- Procurar, 2- Sair: ";
        cin >> escolha;
        inicio_e_ram:
        if(escolha == 1)
        {
            passou = true;
            int quantidade = 0;
            string palavra;
            cout << "Insira a palavra para recorrer na memória: ";
            cin >> palavra;
            passou = true;
            auto t1 = high_resolution_clock::now();
            int posicoes[tamanho];
            int posicao = rand()%tamanho;
            while(true)
            {
                if(saida[posicao] != "")
                {
                    if(saida[posicao] == palavra)
                    {
                        cout << "A palavra exite, está na posição: " << posicao << endl;
                        passou = false;
                    }
                }
                posicoes[quantidade] = posicao;
                volta:
                //cout << posicao << endl;
                bool achou = false;
                posicao = rand()%tamanho;
                for(int i = 0; i < quantidade+1; i++)
                {
                    if(posicao == posicoes[i])
                        achou = true;
                }
                if(achou && quantidade < tamanho-1)
                    goto volta;
                quantidade++;
                if(quantidade == tamanho)
                    break;
            }
            auto t2 = high_resolution_clock::now();
            //auto ms_int = duration_cast<milliseconds>(t2-t1);
            duration<double, std::milli> fp_ms = t2 - t1;
            saida_int = fp_ms.count();
            if(passou)
            {
                cout << "Palavra não foi encontrada, tente novamente!" << endl;
                goto inicio_e_ram;
            } 
            cout << saida_int << " ms" << endl;
        }
        if(escolha != 1 && escolha != 2)
            cout << "Não entendi sua escolha, tente novamente!" << endl;
        else if(escolha == 2 && !passou)
            return saida_int;
        if(passou && escolha == 2)
            cout << "Procure primeiro uma palavra antes de sair!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
    } while (true);
}

/*

    Memória SAM

*/
string *entrada_SAM(int tamanho)
{
    string *saida = new string[tamanho];
    ifstream fp(arquivo);
    if(fp.is_open())
    {
        
        for(int i = 0; i < tamanho; i++)
        {
            getline(fp,saida[i]);
        }
        fp.close();
    }else
    {
        cout << "Arquivo não encontrado, programa encerrando!" << endl;
        exit(0);
    }
    return saida;
}

float sam(int tamanho)
{
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using std::chrono::duration;
    using chrono::milliseconds;
    bool achou = true;
    float saida_int;
    string *saida = new string[tamanho];
    saida = entrada_SAM(tamanho);
    for(int i = 0; i < tamanho; i++)
    {
        if(saida[i] != "")
            cout << i+1 << " " << saida[i] << endl;
    }
    do
    {
        int escolha;
        cout << "Escolha 1- Procurar, 2- Sair: ";
        cin >> escolha;
        inicio_e_sam:
        if(escolha == 1)
        {
            achou = true;
            int quantidade = 0;
            using namespace std::chrono_literals;
            string palavra;
            cout << "Insira a palavra para recorrer na memória: ";
            cin >> palavra;
            auto t1 = high_resolution_clock::now();
            for(int i = 0; i < tamanho; i++)
            {
                if(saida[i] == palavra)
                {
                    cout << "A palavra exite, está na posição: " << i << endl;
                    achou = false;
                }
            }
            auto t2 = high_resolution_clock::now();
            //auto ms_int = duration_cast<milliseconds>(t2-t1);
            duration<double, std::milli> fp_ms = t2 - t1;
            saida_int = fp_ms.count();
            if(achou)
            {
                cout << "Palavra não foi encontrada, tente novamente!" << endl;
                goto inicio_e_sam;
            }
            cout << saida_int << " ms" << endl;
        }
        if(escolha != 1 && escolha != 2)
            cout << "Não entendi sua escolha, tente novamente!" << endl;
        else if(escolha == 2 && !achou)
            return saida_int;
        if(achou && escolha == 2)
            cout << "Procure primeiro uma palavra antes de sair!" << endl;
    } while (true);
}