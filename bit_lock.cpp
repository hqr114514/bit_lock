#include <bits/stdc++.h>
using namespace std;
int main(int num, char **args) {
    if (num < 4) return 1;
    char* op_temp = args[1];
    string op(op_temp);
    char* filename_in = args[2];
    char* filename_out = args[3];
    ifstream fin(filename_in, ios::binary);
    ofstream fout(filename_out,ios::binary);
    if (op.find("E") != -1 || op.find("e") != -1) {
        fin.seekg(0, ios::end);
        long long len = fin.tellg(), t = 1;
        fin.seekg(0, ios::beg);
        fout << (len>>2) << endl;
        while (t <= len - 4) {
            unsigned char tmp[4];
            memset(tmp, 0, 4);
            fin.read((char*)tmp + 0, 4);
            unsigned int a1 = ((unsigned int)tmp[0]) << 24;
            unsigned int a2 = ((unsigned int)tmp[1]) << 16;
            unsigned int a3 = ((unsigned int)tmp[2]) << 8;
            unsigned int a4 = ((unsigned int)tmp[3]);
            fout << (a1 | a2 | a3 | a4) << endl;
            t+=4;
        }
        if (t < len) {
            unsigned char tmp[4];
            memset(tmp, 0, 4);
            fin.read((char*)tmp + 0, len - t);
            unsigned int a1 = ((unsigned int)tmp[0]) << 24;
            unsigned int a2 = ((unsigned int)tmp[1]) << 16;
            unsigned int a3 = ((unsigned int)tmp[2]) << 8;
            fout << (a1 | a2 | a3 ) << endl;
        }
    }
    else if (op.find("D") != -1 || op.find("d") != -1) {
        unsigned int tmp, t = 1;
        long long len;
        fin >> len;
        while (t <= len) {
            fin >> tmp;
            unsigned char a1 = (tmp & 0xff000000) >> 24;
            unsigned char a2 = (tmp & 0x00ff0000) >> 16;
            unsigned char a3 = (tmp & 0x0000ff00) >> 8;
            unsigned char a4 = (tmp & 0x000000ff);
            fout.write((char*)&a1, 1);
            fout.write((char*)&a2, 1);
            fout.write((char*)&a3, 1);
            fout.write((char*)&a4, 1);
            t++;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
