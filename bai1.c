#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Hàm tách chuỗi dựa trên chuỗi ký tự.
char *multi_token(char *input, char *delimiter)
{
    static char *string;
    if (input != NULL)
    {
        string = input;
    }

    if (string == NULL)
    {
        return string;
    }
    char *end = strstr(string, delimiter);
    if (end == NULL)
    {
        char *temp = string;
        string = NULL;
        return temp;
    }
    char *temp = string;
    *end = '\0';
    string = end + strlen(delimiter);
    return temp;
}

void extractData(char khachHang[], char Hoten[], char Gioitinh[], char sdt[], char email[])
{
    // Khai báo mảng hai chiều, chieu x la kich thuoc info, chieu y la kich thuoc cac mang.
    // info[0] se luu gia tri cua "hoten":"Tran Anh Tu"
    // info[1] se luu gia tri cua "gioitinh":"nam"
    // info[2] se luu gia tri cua "sdt":"0123456789"
    // info[3] se luu gia tri cua "email":"anhtuthemen@gmail.com"

    char info[4][100];
    int i;

    // Cat chuoi khachHang dua vao dau ,
    char *token = strtok(khachHang, ",");

    i = 0;
    while (token != NULL)
    {
        strcpy(info[i], token);
        i++;
        token = strtok(NULL, ",");
    }
    // Trich xuat hoten.
    char *hoten_token = strtok(info[0], ":");
    strcpy(Hoten, strtok(NULL, ":"));

    // Trich xuat gioitinh.
    char *gioitinh_token = strtok(info[1], ":");
    strcpy(Gioitinh, strtok(NULL, ":"));

    // Trich xuat sdt.
    char *sdt_token = strtok(info[2], ":");
    strcpy(sdt, strtok(NULL, ":"));

    // Trich xuat email.
    char *email_token = strtok(info[3], ":");
    strcpy(email, strtok(NULL, "\""));

    // Xoa bo dau } nam o cuoi email thay vao la gia tri null
    if (email[strlen(email) - 1] == '}' || email[strlen(email) - 1] == ']' && khachHang[0] == '[' && khachHang[1] == '{')
    {
        email[strlen(email) - 1] = '\0';
    }
}

int main()
{
    char anhtu[] = "[{\"hoten\":\"Le Thi My Duyen\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0935777888\",\"email\":\"duyen86@gmail.com\"},{\"hoten\":\"Tran Trung Thanh\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0976333444\",\"email\":\"thanhtt98.com\"},{\"hoten\":\"Huynh Anh Hoang\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0939745220\",\"email\":\"hahoang88@gmail.com\"},{\"hoten\":\"Nguyen Minh Khoi\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0703666777\",\"email\":\"khoimaster@gmail.com\"}]";
    char Hoten[100], Gioitinh[100], sdt[100], email[100];
    char khachHang[100];
    char Hoten_Nam[100][100];
    int sl_nam = 0;
    int sl_khachHang = 0;
    int i = 0;

    char *token = multi_token(anhtu, "},{");

    while (token != NULL)
    {
        strcpy(khachHang, token);

        extractData(khachHang, Hoten, Gioitinh, sdt, email);

        if (strcmp(Gioitinh, "\"nam\"") == 0)
        {
            strcpy(Hoten_Nam[i], Hoten);
            sl_nam++;
            i++;
        }
        sl_khachHang++;

        token = multi_token(NULL, "},{");
    }

    printf("Co tong cong %d khach hang nam / Tong so %d khach hang\n", sl_nam, sl_khachHang);

    if (sl_nam > 0)
    {
        printf("Ho ten cac khach hang nam: \n");
        for (i = 0; i < sl_nam; i++)
        {
            printf("%d. %s\n", i + 1, Hoten_Nam[i]);
        }
    }
    return 0;
}
