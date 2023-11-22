/* 1951889 ���� ����Ǫ*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

int main() 
{
    cerr << "�ļ���������ʽ������:\n";
    cerr << "    a.txt                     : ����·����ʽ\n"
        << "    ..\\data\\b.dat             : ���·����ʽ\n"
        << "    C:\\Windows\\System32\\c.dat : �������·����ʽ\n"
        << "�������ļ��� : ";
    char filename[300];
     cin.getline(filename, 300);
    ifstream in(filename, ios::in | ios::binary);
    if (!in.is_open()) {
        cout << "�����ļ�" << filename << "��ʧ��!" << endl;
        in.close();
        return 0;
    }
    int c;
    int count = 0;
    int size = 0;
    char save[16];

    while ((c = in.get()) != EOF) {
        // ����ǰ�˸�����
        if (count % 16 == 0) {
            memset(save, 0, sizeof(save));
            cout << setfill('0') << setw(8) << hex << uppercase << size;
            cout << ": ";
            size += 16;
        }

        // ��ӡ�ָ��
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

        // ÿ16����ӡԭ�ļ�
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
