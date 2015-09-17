#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <locale.h>

using namespace std;

//Função split, retirada da internet
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
    ifstream myfile ("autores.txt"); // ifstream = padrão ios:in
    if (myfile.is_open())
    {
        while (! myfile.eof() ) //enquanto end of file for false continua
        {
            getline (myfile,line); // como foi aberto em modo texto(padrão)
            //e não binário(ios::bin) pega cada linha


            if(line.length()==3){
                number_article = line;
            }
            //cout<<"Numero do artigo = " << number_article << endl; 
            // }else {
            //     cout << line <<" "<< number_article<<endl;

            // }

            //Declaracoes -------
            vector<string> v;
            char *aux;
            int i = 1;
            //-------------------

            split(line, ' ', v);
            if(v.size()!=0){
                int complement = 0;
                if(v[v.size()-1]=="JUNIOR" || v[v.size()-1]=="JÚNIOR" || v[v.size()-1]=="NETTO" || v[v.size()-1]=="NETO" || v[v.size()-1]=="FILHO"){
                    cout<<v[v.size()-2]<<" "<<v[v.size()-1]<<", ";
                    complement = 1;
                }else{
                    cout<<v[v.size()-1]<<", ";
                }
                for (int i = 0; i < v.size()-1-complement; ++i) {
                    if(v[i]=="DE" || v[i]=="DO" || v[i]=="DA" || v[i]=="E" || v[i]=="DOS" || v[i]=="DAS"){
                        cout<<" "<< v[i];
                            if(i != v.size()-2-complement)
                                cout<<" ";
                    }else{
                        cout << v[i][0] << ".";
                    }
                }
                cout<<", "<<number_article<<endl;
            }

    }
    myfile.close();
}

else cout << "Unable to open file"; 

//system("pause");
return 0;
}
