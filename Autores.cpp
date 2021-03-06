#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <locale.h>
#include <algorithm>


using namespace std;

//Fun��o split, retirada da internet
void split(const string& s, char c,
        vector<string>& v) {
            string::size_type i = 0;
            string::size_type j = s.find(c);

            while (j != string::npos) {
                v.push_back(s.substr(i, j-i));
                i = ++j;
                j = s.find(c, j);

                if (j == string::npos)
                    v.push_back(s.substr(i, s.length()));
            }
        }

int main () {
    setlocale(LC_ALL,"Portuguese");
    string line;
    string number_article;
    ifstream myfile ("autores.txt"); // ifstream = padr�o ios:in
    ofstream myOutputFile;
    //Abrindo arquivo para c�pia
    myOutputFile.open("output.txt");

    if (myfile.is_open())
    {
        while (! myfile.eof() ) //enquanto end of file for false continua
        {
            getline (myfile,line); // como foi aberto em modo texto(padr�o)
            //e n�o bin�rio(ios::bin) pega cada linha


            if(line.length()==3){
                number_article = line;
            }

            //Declaracoes -------
            vector<string> v;
            char *aux;
            int i = 1;
            //-------------------

            split(line, ' ', v);
            //Pula linha em branco
            if(v.size()!=0){
                int complement = 0;
                /*Esta vari�vel � utilizada caso o nome da pessoa possua algum dos sobrenomes abaixo
                 que no caso ir� modificar a forma a ser tratado, exemplo:
                 GILCEMIR ANGELO DA CONCEI��O -> CONCEI��O, G.A. da, [n�mero]
                 j� 
                 GILCEMIR ANGELO DA CONCEI��O FILHO -> CONCEI��O FILHO, G.A., [n�mero]
                */
                 if(v[v.size()-1]=="JUNIOR" || v[v.size()-1]=="J�NIOR" || v[v.size()-1]=="NETTO" || v[v.size()-1]=="NETO" || v[v.size()-1]=="FILHO" || v[v.size()-1]=="SOBRINHO"){
                    cout<<v[v.size()-2]<<" "<<v[v.size()-1]<<", ";
                    myOutputFile<<v[v.size()-2]<<" "<<v[v.size()-1]<<", ";
                    complement = 1;
                }else{
                    cout<<v[v.size()-1]<<", ";
                    myOutputFile<<v[v.size()-1]<<", ";
                }
                for (int i = 0; i < v.size()-1-complement; ++i) {
                    //Aqui, tais partes de sobrenome N�O s�o abreviados - por isso o teste.
                    if(v[i]=="DE" || v[i]=="DO" || v[i]=="DA" || v[i]=="E" || v[i]=="DOS" || v[i]=="DAS"){
                        transform(v[i].begin(), v[i].end(), v[i].begin(), ::tolower);
                        cout<<" "<< v[i];
                        myOutputFile<<" "<< v[i];
                            if(i != v.size()-2-complement)
                                cout<<" ";
                                myOutputFile<<" ";
                    }else{
                        cout << v[i][0] << ".";
                        myOutputFile << v[i][0] << ".";
                    }
                }
                cout<<", "<<number_article<<endl;
                myOutputFile<<", "<<number_article<<endl;
            }

    }
    myfile.close();
    myOutputFile.close();
}

else cout << "Unable to open file"; 

//system("pause");
return 0;
}
