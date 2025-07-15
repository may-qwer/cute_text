#include <iostream>
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

void cout_finish_text_len(char* f_text, int len) {
    for (int i = 0; i < len; i++) {
        cout << f_text[i];
    }
}

void show_simbol(char* str, char sim, int str_len) {
    char maybe_sim;
    for (int i = FIRST_SIMBOL; i < LAST_SIMBOL; i++) {
        maybe_sim = i;
        cout_finish_text_len(str, str_len);
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
    char* start_text;
    int len_of_start_text;
    char* finish_text;

    cout << "Enter some text: ";
    cin >> start_text;
    len_of_start_text = get_len(start_text);
    set_empty_str(finish_text, len_of_start_text);
    for (int i = 0; i < len_of_start_text+1; i++) {
        cout_finish_text_len(finish_text, i);
        show_simbol(finish_text, start_text[i], i);
        finish_text[i] = start_text[i];
    }

    return 0;
}