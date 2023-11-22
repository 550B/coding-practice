/* 1951889 电气 王淞仟*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

int main() 
{
    cerr << "文件名以下形式均可以:\n";
    cerr << "    a.txt                     : 不带路径形式\n"
        << "    ..\\data\\b.dat             : 相对路径形式\n"
        << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式\n"
        << "请输入文件名 : ";
    char filename[300];
     cin.getline(filename, 300);
    ifstream in(filename, ios::in | ios::binary);
    if (!in.is_open()) {
        cout << "输入文件" << filename << "打开失败!" << endl;
        in.close();
        return 0;
    }
    int c;
    int count = 0;
    int size = 0;
    char save[16];

    while ((c = in.get()) != EOF) {
        // 处理前八个数字
        if (count % 16 == 0) {
            memset(save, 0, sizeof(save));
            cout << setfill('0') << setw(8) << hex << uppercase << size;
            cout << ": ";
            size += 16;
        }

        // 打印分割符
        if (count % 8 == 0 && count % 16 != 0) {
            cout << " -";
        }
        
        if (c < 16)
            cout << " 0" << hex << c;
        else
            cout << setfill(' ') << setw(3) << hex << uppercase << c;
        if (c >= 33 && c <= 126)
            save[count % 16] = (char)c;
        else
            save[count % 16] = '.';
        count++;

        // 每16个打印原文件
        if (count % 16 == 0) {
            cout << "  ";
            for (int i = 0; i < 16; i++)
                cout << save[i];
            cout << endl;
        }
    }

    if (count % 16 != 0) {
        int p = count % 16;
        while (count % 16 != 0) {
            if (count % 8 == 0)
                cout << "  ";
            cout << "   ";
            count++;
        }
        cout << "  ";
        for (int i = 0; i < p; i++)
            cout << save[i];
        cout << endl;
    }
    in.close();
    return 0;
}
