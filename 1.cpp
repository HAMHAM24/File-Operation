#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
string line, filename;

void penampilData(){
    fstream file;
    file.open(filename);
    if(file.is_open()){
        while(getline(file, line)){
            cout << line << endl;
        }
        file.close();
    }
}

int main(){
    int lineNumber;
    cout << "\n=============================================" << endl;
    cout << "Masukkan Nama File       : ";
    getline(cin, filename);
    cout << "=============================================\n" << endl;
    cout << "=============================================" << endl;
    cout << "Nama File : " << filename << endl;
    cout << "=============================================\n" << endl;
    cout << "=============================================" << endl;
    cout << "Isi file  : " << endl;
    penampilData();
    cout << "=============================================\n" << endl;
    
    cout << "=============================================" << endl;
    cout << "Baris Yang Ingin Dihapus : ";
    cin >> lineNumber;
    cout << "=============================================\n" << endl;

    fstream readFile;
    readFile.open(filename);

    if(readFile.fail()){
        cout << "Eror Saat Membuka File!" << endl;
        return 1;
    }

    vector<string> lines;
    string line;

    while(getline(readFile, line))
        lines.push_back(line);
        readFile.close();
    
    if(lineNumber > lines.size()){
        cout << "Line " << lineNumber;
        cout << " tidak ditemukan." << endl;
        cout << "File hanya mempunyai " << lines.size() << " line." << endl;
        return 1;
    }

    ofstream writeFile;
    writeFile.open(filename);

    if(writeFile.fail()){
        cout << "Eror saat membuka file." << endl;
        return 1;
    }

    lineNumber--;

    for(int i = 0; i < lines.size(); i++)
    if(i != lineNumber)
    writeFile << lines[i] << endl;
    writeFile.close();
    cout << "=============================================" << endl;
    cout << "Isi file setelah dihapus : " << endl;
    penampilData();
    cout << "=============================================\n" << endl;
}