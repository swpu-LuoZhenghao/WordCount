#include <stdio.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_TEXT_LEN 1000000

int main(int argc, char *argv[]) {
    char parameter[3];
    char file_name[MAX_FILE_NAME_LEN];
    char text[MAX_TEXT_LEN];
    int text_len = 0;
    int char_count = 0;
    int word_count = 0;
    
    // 解析命令行参数
    if (argc == 3) {
        strcpy(parameter, argv[1]);
        strcpy(file_name, argv[2]);
    } else {
        printf("Error: Invalid input parameters\n");
        return -1;
    }
    
    // 读取文件内容
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Failed to open input file\n");
        return -1;
    }
    while (fgets(text+text_len, MAX_TEXT_LEN-text_len, fp) != NULL) {
        text_len = strlen(text);
    }
    fclose(fp);
    
    // 统计字符数或单词数
    if (strcmp(parameter, "-c") == 0) {
        // 统计字符数
        int i=0; 
        for (i = 0; i < text_len; i++) {
            if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n') {
                char_count++;
            }
        }
        printf("Characters count: %d\n", char_count);
    } else if (strcmp(parameter, "-w") == 0) {
        // 统计单词数
        // ...
        printf("Words count: %d\n", word_count);
    } else {
        printf("Error: Invalid input parameter\n");
        return -1;
    }
    
    return 0;
}

