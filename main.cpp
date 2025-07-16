#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

#define FIRST_SIMBOL 32
#define LAST_SIMBOL 126

int get_len(char* str) {
    int len = 0;
    while (str[len] != 0) {
        len++;
    }
    return len;
}

void set_empty_str(char* str, int str_len) {
    for (int i = 0; i < str_len+1; i++) {
        str[i] = ' ';
    }
}

void cout_output_str_by_len(char* str, int len) {
    for (int i = 0; i < len; i++) {
        cout << str[i];
    }
}

void show_simbol(char* str, char sim, int str_len) {
    char maybe_sim;
    for (int i = FIRST_SIMBOL; i < LAST_SIMBOL; i++) {
        maybe_sim = i;
        cout_output_str_by_len(str, str_len);
        cout << maybe_sim << endl; 
        usleep(25000);
        if (sim == ' ') {
            cout << " " << endl;
            return;
        }
        if (sim == maybe_sim) {
            return;
        }
    }
}


int main() {
    char* input_str;
    int len_of_input_str = 100;
    char* output_str;

    cout << "Enter some text: ";
    fgets(input_str, len_of_input_str, stdin);
    len_of_input_str = get_len(input_str);
    set_empty_str(output_str, len_of_input_str);
    for (int i = 0; i < len_of_input_str-1; i++) {
        cout_output_str_by_len(output_str, i);
        show_simbol(output_str, input_str[i], i);
        output_str[i] = input_str[i];
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << output_str << endl;
    }

    return 0;
}