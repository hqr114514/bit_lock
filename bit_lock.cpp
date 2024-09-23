#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const unsigned int gb = 1024 * 1024 * 1024;
double jda, jdb;
int main(int num, char** args) {
    if (num < 4) return 1;
    char* op_tmp = args[1];
    string op(op_tmp);
    char* filename_in = args[2];
    char* filename_out = args[3];
    ifstream fin(filename_in, ios::in | ios::binary);
    ofstream fout(filename_out, ios::out | ios::binary);
    fin.seekg(0, ios::end);
    ull len = fin.tellg(), i = 0;
    fin.seekg(0, ios::beg);
    if (op.find("e") != -1 || op.find("E") != -1) {
        srand(time(0));
        unsigned char salt = rand() % 128;
        fout.write((char*)&salt, sizeof(salt));
        jdb = len;
        while (i <= len) {
            //1GB=1024*1024*1024B
            if (i + gb <= len) {
                unsigned char* tmp = (unsigned char*)malloc(gb);
                fin.read((char*)tmp, gb);
                for (int j = 0; j < gb; j++) tmp[j] ^= salt;
                fout.write((char*)tmp, gb);
                i += gb;
            }
            else {
                unsigned char* tmp = (unsigned char*)malloc(len-i);
                fin.read((char*)tmp, len - i);
                for (int j = 0; j < len - i; j++) tmp[j] ^= salt;
                fout.write((char*)tmp, len - i);
                break;
            }
        }
    }
    else {
        len--;
        unsigned char salt;
        fin.read((char*)&salt, sizeof(salt));
        while (i <= len) {
            //1GB=1024*1024*1024B
            if (i + gb <= len) {
                unsigned char* tmp = (unsigned char*)malloc(gb);
                fin.read((char*)tmp, gb);
                for (int j = 0; j < gb; j++) tmp[j] ^= salt;
                fout.write((char*)tmp, gb);
                i += gb;
            }
            else {
                unsigned char* tmp = (unsigned char*)malloc(len-i);
                fin.read((char*)tmp, len - i);
                for (int j = 0; j < len - i; j++) tmp[j] ^= salt;;
                fout.write((char*)tmp, len - i);
                break;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}