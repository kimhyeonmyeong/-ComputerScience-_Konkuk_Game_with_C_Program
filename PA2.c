
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define NONE_MARK  "  "
#define LONG_NONE_MARK  "                                                       "
#define PLAYER_MARK1  "��"
#define PLAYER_MARK2  "��"
#define PLAYER_MARK3  "��"
#define WALL_MARK2  "��"
#define GUARD_MARK  "��"
#define TOP_MARK  "��"
#define WALL_MARK "��"
#define TREASURE_MARK "��"
#define TRAP_HOLE "��"
#define TRAP_STOP "��"
#define TRUE_EYE "��"
#define TRUE_LOVE "��"
#define MAX_X 20
#define MAX_Y 30
#define TIME_LIMIT 15
#define TIME_LIMIT_S2 30
#define TIME_LIMIT_S3 60

//���� ������ ���� �Լ���
void display_rule1(void);
void display_rule2(void);
void display_rule3(void);
void make_hidden_and_top1(int topx[], int topy[], int topCnt, int stage1x, int stage1y);
void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b);
void display_map(int matrix[][15], int topx[], int topy[], int stagex, int stagey);
void display_map2(int matrix[][20], int topx[], int topy[], int stagex, int stagey);
void display_map3(int matrix[][25], int topx[], int topy[], int stagex, int stagey);
void stage_game_control(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey);
void stage_game_control2(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey);
void stage_game_control3(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey);
void gotoxy(int x, int y);
void stop_trap();
void stop_trap_up();
void True_eye(int matrix[][20], int topx[], int topy[]);
void True_eye2(int matrix[][25], int topx[], int topy[]);
void True_eye3(int matrix[][25], int topx[], int topy[]);

//���丮 ������ ���� �Լ���
void menu();
void stage1();
void stage2();
void stage3();
int story1();
void story2();
void story3();
int story4();
int story5();
int storyEND();
void textcolor(int color_number);



/*
       main �Լ�
*/
int main(void)

{
    int num;
    char ch;
    int end_flag = 0;


    while (1)
    {
        system("cls");
        menu();
        printf("��ȣ�� �����ϼ���: ");
        scanf("%d", &num);


        switch (num)
        {
        case 1:
            stage1();
            break;

        case 2:
            stage2();
            break;

        case 3:
            stage3();
            break;

        case 4:
            printf("���α׷��� ����˴ϴ�.");
            end_flag = 1;
            break;
        default:
            break;

        }
        if (end_flag = 1)
        {
            break;
        }

    }
    return 0;
}


/*
        ���� menu�� ���� �Լ�
*/
void menu()
{
    textcolor(11);
    puts("����������������������������������������������������������������������������������");
    puts("��                                       ��");
    puts("��       �ߡ�   ���� �ձ�   �ۡ�         ��");
    puts("��                                       ��");
    puts("��          1. Stage1[�ʱ�]              ��");
    puts("��                                       ��");
    puts("��          2. Stage2[�߱�]              ��");
    puts("��                                       ��");
    puts("��          3. Stage3[���]              ��");
    puts("��                                       ��");
    puts("��          0. ��     ��                 ��");
    puts("��                                       ��");
    puts("����������������������������������������������������������������������������������");
}



/*
        ���� stage�� ���� �Լ�
*/
void stage1()
{

    int topCnt = 8;
    int stage1x = 10;
    int stage1y = 15;
    int topx[10], topy[10];
    story1();
    story2();
    story3();



    system("cls");

    clock_t start, end;



    double pst;
    display_rule1();
    srand((unsigned)time(NULL));

    //make_treasure(topx, topy);
    make_hidden_and_top1(topx, topy, topCnt, stage1x, stage1y);
    start = clock();

    system("cls");

    stage_game_control(topx, topy, start, &pst, stage1x, stage1y);



    return 0;

}

void stage2()
{

    int flag = 0;
    int topCnt = 15;
    int s_time;
    int stage2x = 15;
    int stage2y = 20;
    int topx[15], topy[15];
    double pst;
    flag = story4();
    if (flag == 1)
    {
        system("cls");
        display_rule2();
        clock_t start, end;

        srand((unsigned)time(NULL));

        //make_treasure(topx, topy);
        make_hidden_and_top1(topx, topy, topCnt, stage2x, stage2y);

        system("cls");
        start = clock();

        stage_game_control2(topx, topy, start, &pst, stage2x, stage2y);


    }
    return 0;

}

void stage3()
{
    int flag = 0;
    int topCnt = 20;
    int s_time;
    int stage3x = 20;
    int stage3y = 25;
    int topx[20], topy[20];
    double pst;

    flag = story5();
    while (flag == 1)
    {

        system("cls");
        display_rule3();
        clock_t start, end;


        srand((unsigned)time(NULL));

        //make_treasure(topx, topy);
        make_hidden_and_top1(topx, topy, topCnt, stage3x, stage3y);

        system("cls");
        start = clock();

        stage_game_control3(topx, topy, start, &pst, stage3x, stage3y);

        flag = storyEND();
        if (flag == 2)
        {
            break;
        }
    }
    return 0;
}


/*
        ���� story�� ���� �Լ�
*/
int story1()
{

    system("cls");
    textcolor(11);
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��                                                                              ��");
    puts("��   ���� �ձ��� ��� �����𿡰Դ� ����ϴ� ����� ���׶�� ���ְ� �ִ�.        ��");
    puts("��  ���� ���� ���� �׿��� �־ ������ �Ƹ��ٿ� ������ ���̺νð� �Ƹ��ٿ���.  ��");
    puts("��  ���� ó������ �� ������ ������.������ ó������ ���� ���� ������ ��������  ��");
    puts("��  �� ����������.���� �������� ���� ���ִ� �����𿡰� �ٰ����� ���� �ʾҴ�.    ��");
    puts("��  �׷��� ����� �ϰ��ִ� �����𿡰� ���׶�� ���ִ� ���� �ٰ����־���.        ��");
    puts("��  �Ӹ��ƴ϶�, �׳�� ������ �ִ� ���׶��, ����, ���簢���� �� ������         ��");
    puts("��  �������� �ʾҴ�. ���� ���� ����ü�� ������ٻ�..                            ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");


    printf("�ƹ�Ű�� ��������");
    _getch();


}



void story2()
{
    char skip;
    system("cls");
    textcolor(11);
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��                                                                              ��");
    puts("��   ������� �׷� ���ָ� ���鼭 ���� ����. �ڽ��� ���� ����� ��¼�� ��ġ��    ��");
    puts("��  �ִ� ���̶�� ������ �����. �׷��� ������� �� �̻� �ڽ��� ���� �����     ��");
    puts("��  �̿����� �ʱ�� �ߴ�. ������ �׷� ������ ����ϰ�, �� �ڽŰ��� ������ �ֺ�  ��");
    puts("��  �����鿡�� �ٰ�����. �� �ķ� ������� �ڽ��� ����ϰ�, �ǹ��ִ� ���� �ϱ�  ��");
    puts("��  ���� ����߰� �׷� ����� ���ֵ� ������ ������ ���� �Ǿ���. �� ���� �帣��");
    puts("��  �ᱹ ������� ���ִ� ����ϴ� ���̰� �Ǿ��� ������� �ٰ����� ����������,   ��");
    puts("��  �׳࿡�� ����ϱ�� ���� �Ծ���.                                            ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");


    printf("�ƹ�Ű�� ��������");

    _getch();
    _getch();

}

void story3()
{
    char skip;
    system("cls");
    textcolor(11);
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");
    puts("��                                                                              ��");
    puts("��   �׷��� ���������� ������ ������ ��⸦ ������ �� ������. ���ڱ� ������   ��");
    puts("��  �Ȱ��� �ձ����� ���� ã�� ���� ������ �а��� �� ���� ������. '����!!'       ��");
    puts("��  ������ ��Ҹ�����. ������� ���������� ���ָ� ���ϱ� ���� �޷����� @        ��");
    puts("��  �����簡 �̹� ���ָ� ����� �־���. ��ħ�� ���ֿ��� �ٰ��� ������� @       ��");
    puts("��  �����縦 ���� ���� �𼭸��� ���������� �̸� �ߵ��ص� �������� ������� ��� ��");
    puts("��  ����. �����ָ� ã�� ������ ž���� �Ͷ�, �ð��� ������ ���ִ� ���� ��        ��");
    puts("��  �����ž�!!����� ���� �Բ�.. ������� ������ �ð��� ����! � ���ָ�       ��");
    puts("��  ���Ϸ� ž���� ����!!                                                        ��");
    puts("��                                                                              ��");
    puts("��                                                                              ��");
    puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");


    printf("�ƹ�Ű�� ��������");

    _getch();
    _getch();

}


int story4()
{
    char num;
    int flag = 1;
    do {

        system("cls");
        textcolor(11);
        puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");
        puts("��                                                                              ��");
        puts("��   ���ָ� ���ߴ�! ������� ������ ���¸� Ȯ���ߴ�. ������ ���ִ� ������ ��    ��");
        puts("��  ����. ���̷� ���� �ƴϾߡ� ������� ���ָ� ������ ž�� ��� ���ѷ� �ձ�   ��");
        puts("��  ���� ���Ϸ� �ߴ�. ���̷��� ��ĥ �� ����!!�� �׷��� �׶� @�������� ������    ��");
        puts("��  ��Ȱ�ٽ� �ѹ� �������� �� ���� ������ ���ָ� ���� �ٰ��Դ�. ���ֿ���      ��");
        puts("��  �ٽ� ������ ���������� ����, ������� ���� ���� ���Ƽ��� ������� ���Ҵ�.   ��");
        puts("��  ���ִ� ��� ��Ȳ������ �̳� ħ��������. ������ ���ϸ� ��.��                 ��");
        puts("��  �̹����� ���� ���ʴ�, ž�� ���εǰ� �ִ� ������ ������!!                  ��");
        puts("��                                                                              ��");
        puts("��                                                                              ��");
        puts("��                                                                              ��");
        puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");

        printf("Start to S");
        scanf("%c", &num);

    } while (num != 'S');

    return flag;

}



int story5()
{
    char num;
    int flag = 1;
    do {

        system("cls");
        textcolor(11);
        puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");
        puts("��                                                                              ��");
        puts("��   ������ ���ߴ�! ������ �����絵 ���� �� ���� ���ϴ�. �׷��� �������      ��");
        puts("��  ���ִ� Ż���� �Ϸ��� ������.. �̴�� ���� ������ �����簡 �ٽ� ���� �𸥴�.  ��");
        puts("��  ������� ���ָ� �ٶ󺸾Ұ� ���ֿ��� ���� ������ �� �ߴ�.  '�� �𼭸��� ���� ��");
        puts("��  �����Ҷ���' �׷��� �����翡�� �����Ϸ� �� ��, ���ִ� ������ ������ ǰ��   ��");
        puts("��  ���� ���� ������ ���´�. �װ��� ���� �ձ����� �������� �����̿���. �θ��̼��� ��");
        puts("��  ����� ������ ������, ���� ������ ���� �ʰų� �ڽ��� �ٷ��� ���ϴ� ����     ��");
        puts("��  ������ ����� ���� ������. ������ ������ ȿ���� �����߰� ���� ������ ����   ��");
        puts("��  ���մ�. ���� ������ @�������̴�! �����縦 ó���Ϸ� ����!                    ��");
        puts("��                                                                              ��");
        puts("��                                                                              ��");
        puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");

        printf("Start to S");
        scanf("%c", &num);

    } while (num != 'S');

    return flag;

}

int storyEND()
{
    char num;
    int flag = 2;
    do {
        system("cls");
        textcolor(11);
        puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");
        puts("��                                                                              ��");
        puts("��   @�����縦 �����ƴ�! ������� ���ִ� ��ģ���� �̲��� �ձ����� ���ߴ�.       ��");
        puts("��  �޽��� ���ϰ� ������� ��⸦ ���� ������ ����� �߰� ���ִ� �޾Ƶ�         ��");
        puts("��  ����. ���ָ� ���ؿ� ��⿡ ������ �յ� �� ���̸� ����߰� �������          ��");
        puts("��  ������ ��ȥ���� ������ �Ǿ���. ������ ������, ���ֵ� ���ǿ����̶��       ��");
        puts("��  �������� �ʾҴ�. �׵鿡�Դ� �ؾ��� �ϵ��� �־��� ���� �� @������ ����       ��");
        puts("��  �������� �ձ��� �ĵ�� ���� �𸣴� ���̿����ϱ�. ������� �׻� ����߰�     ��");
        puts("��  ���� �𼭸���� ����޴� ���� ���� �����ߴ�. �ڽ��� ���� ����� �ڶ�        ��");
        puts("��  �ϸ鼭 ���̴�. ���ֵ� �� �ϴ� ��ó�� �ٸ� �������� �ݷ��߰� ������ �Ʋ�   ��");
        puts("��  �־���. ��, ���� �츮�� �����Դϴ�! �츮���� ������ �ϰ� �츮����           ��");
        puts("��              Story�� ����ݽô�! �Ǵٸ� ����������!                          ��");
        puts("����������������������������������������������������������������������������������������������������������������������������������������������������������������");

        printf("END to E");
        scanf("%c", &num);

    } while (num != 'E');

    return flag;

}







/*

���� ��Ģ�� ����ϴ� �Լ� display_rule

*/

void display_rule1(void)

{
    gotoxy(1, 1);

    printf("�ߡ�   ���� �ձ�   �ۡ�");

    gotoxy(1, 3);

    printf("ž�� ���� ���ָ� ���ؾ� �մϴ�. ");

    gotoxy(1, 5);

    printf("ž�ȿ��� ���� �Ǵ� �����簡 �غ��� ���� ������ �ֽ��ϴ�. \n");

    gotoxy(1, 7);

    printf("���ѵ� �ð�(30��)�� ������ ž�� ������ �ϼ��� �ǰ�\n");

    gotoxy(1, 9);

    printf("���ָ� ���� ������ �����ϴ�.\n");

    gotoxy(1, 11);

    printf("��, ���� ������!!\n");

    gotoxy(1, 12);
    printf("------------------------------------------------\n");

    gotoxy(1, 14);
    printf("8���� (��)ž�� �ֽ��ϴ�.\n");

    gotoxy(1, 16);
    printf("�ظ����� �ɸ��� 2�ʰ� ������ ���� �����ϴ�.\n");

    _getch();
    _getch();
}
void display_rule2(void)

{

    gotoxy(1, 1);

    printf("�ߡ�   ���� �ձ�   �ۡ�");

    gotoxy(1, 3);

    printf("ž�ȿ��� ������ �Ǵ� �����簡 �غ��� ������ ��ٸ��� �ֽ��ϴ�. \n");

    gotoxy(1, 5);

    printf("���ѵ� �ð�(45��)�� ������ ž�� ������ �ϼ��� �ǰ�\n");

    gotoxy(1, 7);

    printf("������� ���� ������ �����ϴ�.\n");

    gotoxy(1, 9);

    printf("���� @������� �� �پ��� ������ �θ��ϴ�.\n");

    gotoxy(1, 11);

    printf("������ ���ִ� Ư�� ž���� ������ ��(��) ������ ����� �� �ֽ��ϴ�. ��������!\n");

    gotoxy(1, 12);
    printf("------------------------------------------------\n");

    gotoxy(1, 14);
    printf("15���� (��)ž�� �ֽ��ϴ�.\n");

    gotoxy(1, 16);
    printf("(��)STOP������ �ɸ��� 2�ʰ� ������ ���� �����ϴ�. x 2\n");

    gotoxy(1, 18);
    printf("(��)��Ȧ ������ �ɸ��� ž���� ����ǰ� �ʱ� ��ġ�� �̵��˴ϴ�. x 2 \n");

    gotoxy(1, 20);
    printf("(��)������ ���� ����� ž �ϳ��� �������ϴ�. x 1\n");


    _getch();
    _getch();
}


void display_rule3(void)

{

    gotoxy(1, 1);

    printf("�ߡ�   ���� �ձ�   �ۡ�");

    gotoxy(1, 3);

    printf("ž�ȿ��� ��ģ @�����簡 ���� �ֽ��ϴ�. \n");

    gotoxy(1, 5);

    printf("���ѵ� �ð�(60��)�� ������ ���� �������� �ϼ��� �ǰ�\n");

    gotoxy(1, 7);

    printf("@������� ������̴ϴ�.\n");

    gotoxy(1, 9);

    printf("@������� ������ �����ϰ����� ���� ���� �� ������ ���ΰ� �ֽ��ϴ�.\n");

    gotoxy(1, 11);

    printf("�������� ����� ȥ�ڰ� �ƴմϴ�, �� ��������!!\n");

    gotoxy(1, 12);
    printf("------------------------------------------------\n");

    gotoxy(1, 14);
    printf("20���� (��)ž�� �ֽ��ϴ�.\n");

    gotoxy(1, 16);
    printf("(��)STOP������ �ɸ��� 2�ʰ� ������ ���� �����ϴ�. x 3\n");

    gotoxy(1, 18);
    printf("������ (��)STOP������ �ɸ��� 4�ʰ� ������ ���� �����ϴ�. x 2\n");

    gotoxy(1, 20);
    printf("(��)��Ȧ ������ �ɸ��� ž���� ����ǰ� �ʱ� ��ġ�� �̵��˴ϴ�. x 5\n");

    gotoxy(1, 22);
    printf("(��)������ ���� ����� ž �ϳ��� �������ϴ�. x 2 \n");

    _getch();
    _getch();

}





/*

    ž�� ��ġ ���� ��������� �Լ�

*/

void make_hidden_and_top1(int topx[], int topy[], int topCnt, int stagex, int stagey)

{
    int i;

    for (i = 0; i < topCnt; i++) //top, hidden ��ǥ �����

    {
        do
        {
            topx[i] = rand() % stagex - 1; //hidden�� x ��ǥ
            topy[i] = rand() % stagey - 1; //hidden�� y ��ǥ

        } while ((topx[i] < 2) || (topy[i] < 2));
    }
}






/*

    ���� ������ �Լ�

*/

void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}




/*

    ����� �Է¿� ���� Ŀ�� �����ϱ� ���� �Լ�

*/
void gotoxy(int x, int y)

{

    COORD Pos = { x  , y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}



/*

    �Լ� move_arrow_key ����Ű�� ���� �����̱� ���� �Լ�

*/
void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b)

{

    switch (key)

    {

    case 72:
        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *y1 = *y1 - 1; //���� ������ ȭ��ǥ Ű �Է�

        if (*y1 < 1)

            *y1 = 1;

        break;

    case 75:

        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *x1 = *x1 - 2; //���� ������ ȭ��ǥ Ű �Է�

        if (*x1 < 2)

            *x1 = 2;

        break;

    case 77:

        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *x1 = *x1 + 2; //������ ������ ȭ��ǥ Ű �Է�

        if (*x1 > x_b - 2)

            *x1 = x_b - 2;

        break;

    case 80:

        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *y1 = *y1 + 1; //�Ʒ��� ������ ȭ��ǥ Ű �Է�

        if (*y1 > y_b - 1)

            *y1 = y_b - 1;

        break;

    default:

        return;

    }

}





/*

    �����ձ� ���ӿ��� �����Ǵ� �������� ���� �Լ�

*/
void wormhole_trap(int* x, int* y)
{
    gotoxy(1, 28);
    textcolor(4);
    printf("��Ȧ ������ ���߽��ϴ�. �ʱ���ġ�� ���ư��ϴ�");
    Sleep(1000); // ��Ȧ ������ ��
    gotoxy(1, 30);
    printf(LONG_NONE_MARK);
    *x = 2; *y = 2; //�ʱ���ġ

}

void stop_trap()
{
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(8);
    printf("�������� ������ �ɷȽ��ϴ�. 2�ʰ� ����ϴ�.");
    Sleep(2000);
}

void stop_trap_up()
{

    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(12);
    printf("�������� ������ ������ �ɷȽ��ϴ�. 4�ʰ� ����ϴ�.");
    Sleep(4000);
}
void True_eye(int matrix[][20], int topx[], int topy[])
{
    int i;
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(1);
    printf("������ ���� ž�� ����� �������ϴ�.\n");
    matrix[topx[9]][topy[9]] = 2;
    
}

void True_eye2(int matrix[][25], int topx[], int topy[])
{
    int i;
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(1);
    printf("������ ���� ž�� ����� �������ϴ�.\n");
    matrix[topx[13]][topy[13]] = 2;
   
}
void True_eye3(int matrix[][25], int topx[], int topy[])
{
    int i;
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(1);
    printf("������ ���� ž�� ����� �������ϴ�.\n");
    matrix[topx[14]][topy[14]] = 2;
}


/*

    ���� control������ �ٲ�� ���� �����ϱ� ���� �Լ�

*/

void display_map(int matrix[][15], int topx[], int topy[], int stagex, int stagey)
{
    int i, j;

    for (i = 0; i < stagex; i++)
    {
        for (j = 0; j < stagey; j++)
        {
            if (matrix[i][j] >= 2)

            {
                gotoxy(2 * i, j);
                textcolor(5);
                printf(TOP_MARK);

                if (matrix[i][j] == 6)
                {
                    gotoxy(2 * i, j);
                    textcolor(3);
                    printf(PLAYER_MARK2);
                }
                else if (matrix[i][j] == 4)
                {
                    textcolor(8);
                    gotoxy(2 * i, j);
                    printf(TRAP_STOP);
                }
            }

            else if (matrix[i][j] == 1)
            {
                textcolor(10);
                gotoxy(2 * i, j);
                printf(WALL_MARK);

            }
            else if (matrix[i][j] == -1)
            {
                gotoxy(2 * i, j);
                printf(NONE_MARK);

            }

        }

    }

}

void display_map2(int matrix[][20], int topx[], int topy[], int stagex, int stagey)
{
    int i, j;

    for (i = 0; i < stagex; i++)
    {
        for (j = 0; j < stagey; j++)
        {
            if (matrix[i][j] >= 2)

            {
                gotoxy(2 * i, j);
                textcolor(5);
                printf(TOP_MARK);

                if (matrix[i][j] == 6)
                {
                    gotoxy(2 * i, j);
                    printf(PLAYER_MARK1);
                }
                else if (matrix[i][j] == 4)
                {
                    gotoxy(2 * i, j);
                    textcolor(8);
                    printf(TRAP_STOP);
                }
                else if (matrix[i][j] == 5)
                {
                    gotoxy(2 * i, j);
                    textcolor(4);
                    printf(TRAP_HOLE);
                }
                else if (matrix[i][j] == 2)
                {
                    gotoxy(2 * i, j);
                    textcolor(1);
                    printf(TRUE_EYE);
                }
            }

            else if (matrix[i][j] == 1)
            {
                gotoxy(2 * i, j);
                textcolor(11);
                printf(WALL_MARK);

            }
            else if (matrix[i][j] == -1)
            {
                gotoxy(2 * i, j);
                printf(NONE_MARK);

            }

        }

    }

}

void display_map3(int matrix[][25], int topx[], int topy[], int stagex, int stagey)
{
    int i, j;

    for (i = 0; i < stagex; i++)
    {
        for (j = 0; j < stagey; j++)
        {
            if (matrix[i][j] >= 2)

            {
                gotoxy(2 * i, j);
                textcolor(5);
                printf(TOP_MARK);

                if (matrix[i][j] == 6)
                {
                    gotoxy(2 * i, j);
                    textcolor(4);
                    printf(TRUE_LOVE);
                }
                else if (matrix[i][j] == 4 || matrix[i][j] == 7)
                {
                    gotoxy(2 * i, j);
                    textcolor(8);
                    printf(TRAP_STOP);
                }
                else if (matrix[i][j] == 5)
                {
                    gotoxy(2 * i, j);
                    textcolor(12);
                    printf(TRAP_HOLE);
                }

                else if (matrix[i][j] == 2)
                {
                    textcolor(1);
                    gotoxy(2 * i, j);
                    printf(TRUE_EYE);
                }
            }

            else if (matrix[i][j] == 1)
            {
                textcolor(4);
                gotoxy(2 * i, j);
                printf(WALL_MARK);

            }
            else if (matrix[i][j] == -1)
            {
                gotoxy(2 * i, j);
                printf(NONE_MARK);

            }

        }

    }

}

/*
    stage�� ���� control�� ���� �Լ�
*/


void stage_game_control(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey)

{
    char key, restart;
    int i, j, count = 0;
    int x = 2, y = 2;

    int s_time = time(NULL);
    clock_t end;

    int matrix[10][15] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };


    for (i = 0; i < 8; i++)
    {
        matrix[topx[i]][topy[i]] = 9;
    }

    do
    {
        gotoxy(x, y);
        textcolor(3);
        printf(PLAYER_MARK1);
        //matrix[(x + 1) / 2][y] = 0;// ������ ���� ǥ��.

        for (i = 0; i < 15; i++)
        {
            if (((x) / 2 == topx[i]) && (y == topy[i]))
                matrix[topx[i]][topy[i]] = -1;
        }

        if (((x) / 2 == topx[0]) && (y == topy[0]))
            matrix[(x) / 2][y] = 6;  //���� ���ϱ�


        else if (x / 2 == topx[4] && (y == topy[4]))
        {
            matrix[(x + 1) / 2][y] = 4; // ���߱� ���� ǥ��
            stop_trap();
            gotoxy(x, y);
        }

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 15; j++)
                if (matrix[i][j] == 6)
                {
                    count = count + 1;
                }

        }

        gotoxy(2, 2);

        display_map(matrix, topx, topy, stagex, stagey); //������ �ٲ۴�

        key = _getch();

        move_arrow_key(key, &x, &y, 18, 14);
        end = clock();

        *pst = (double)(end - start) / CLK_TCK;
        gotoxy(1, 17);

        printf("����ð�:%.1f��", *pst);

        if (*pst > TIME_LIMIT)
        {
            gotoxy(1, 19);
            printf("ž�� ������ �ϼ� �Ǿ����ϴ�. \n");
            Sleep(1000);
            *pst = 0;
            stage1();
            
        }


    } while (count < 1);
    {
        printf("���ָ� ���߽��ϴ�!!\n");
        Sleep(2000);
        stage2(); }

}

void stage_game_control2(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey)
{
    char key, restart;
    int i, j, count = 0;
    int x = 2, y = 2;

    int s_time = time(NULL);
    clock_t end;

    int matrix[15][20] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };

    for (i = 0; i < 15; i++)
    {
        matrix[topx[i]][topy[i]] = 9;
    }

    do
    {
        gotoxy(x, y);

        printf(PLAYER_MARK2);

        //matrix[(x + 1) / 2][y] = 0;// ������ ���� ǥ��.

        for (i = 0; i < 15; i++)
        {
            if (((x) / 2 == topx[i]) && (y == topy[i]))
                matrix[topx[i]][topy[i]] = -1;
        }

        if (((x) / 2 == topx[0]) && (y == topy[0]))
            matrix[(x) / 2][y] = 6;  //������ ���ϱ�


        else if (x / 2 == topx[4] && (y == topy[4]))
        {
            matrix[(x + 1) / 2][y] = 4; // ���߱� ���� ǥ��
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[5] && (y == topy[5]))
        {
            matrix[(x + 1) / 2][y] = 4; // ���߱� ���� ǥ��
            stop_trap();
            gotoxy(x, y);
        }

        else if (x / 2 == topx[6] && (y == topy[6]))
        {
            matrix[(x + 1) / 2][y] = 5; // ��Ȧ ���� ǥ��
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[7] && (y == topy[7]))
        {
            matrix[(x + 1) / 2][y] = 5; // ��Ȧ ���� ǥ��
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[8] && (y == topy[8]))
        {
            matrix[(x + 1) / 2][y] = 2; // ������ �� ǥ��(��� ����)
            True_eye(matrix, topx, topy);


        }


        for (i = 1; i < 15; i++)
        {
            for (j = 1; j < 20; j++)
                if (matrix[i][j] == 6)
                {
                    count = count + 1;
                }

        }

        gotoxy(2, 2);
        display_map2(matrix, topx, topy, stagex, stagey); //������ �ٲ۴�

        key = _getch();

        move_arrow_key(key, &x, &y, 28, 19);
        end = clock();

        *pst = (double)(end - start) / CLK_TCK;
        gotoxy(1, 22);

        printf("����ð�:%.1f��", *pst);

        if (*pst > TIME_LIMIT_S2)
        {
            gotoxy(1, 23);
            printf("ž�� ������ �ϼ� �Ǿ����ϴ�. \n");
            Sleep(1000);
            *pst = 0;
            stage2();
        }



    } while (count < 1);
    {

        gotoxy(1, 22);
        printf("������ ���߽��ϴ�!!\n");
        Sleep(2000);
        stage3(); }

}


void stage_game_control3(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey)
{
    char key, restart;
    int i, j, count = 0;
    int x = 2, y = 2;

    int s_time = time(NULL);
    clock_t end;

    int matrix[20][25] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    for (i = 0; i < 20; i++)
    {
        matrix[topx[i]][topy[i]] = 9;
    }

    do
    {
        gotoxy(x, y);
        textcolor(6);
        printf(PLAYER_MARK3);

        //matrix[(x + 1) / 2][y] = 0;// ������ ���� ǥ��.

        for (i = 0; i < 20; i++)
        {
            if (((x) / 2 == topx[i]) && (y == topy[i]))
                matrix[topx[i]][topy[i]] = -1;
        }

        if (((x) / 2 == topx[0]) && (y == topy[0]))
        {
            matrix[(x) / 2][y] = 6;
            gotoxy(1, 27);
            printf("�����縦 ����⿡ ���� �����մϴ�, ���� ���� ���ּ���!");//  @������ óġ�ϱ�
        }

        else if (x / 2 == topx[4] && (y == topy[4]))
        {
            matrix[(x + 1) / 2][y] = 4; // ���߱� ���� ǥ��
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[5] && (y == topy[5]))
        {
            matrix[(x + 1) / 2][y] = 4; // ���߱� ���� ǥ��
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[6] && (y == topy[6]))
        {
            matrix[(x + 1) / 2][y] = 4; // ���߱� ���� ǥ��
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[7] && (y == topy[7]))
        {
            matrix[(x + 1) / 2][y] = 7; // ������ ���߱� ���� ǥ��
            stop_trap_up();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[8] && (y == topy[8]))
        {
            matrix[(x + 1) / 2][y] = 7; // ������ ���߱� ���� ǥ��
            stop_trap_up();
            gotoxy(x, y);
        }

        else if (x / 2 == topx[9] && (y == topy[9]))
        {
            matrix[(x + 1) / 2][y] = 5; // ��Ȧ ���� ǥ��
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[10] && (y == topy[10]))
        {
            matrix[(x + 1) / 2][y] = 5; // ��Ȧ ���� ǥ��
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[10] && (y == topy[10]))
        {
            matrix[(x + 1) / 2][y] = 5; // ��Ȧ ���� ǥ��
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[11] && (y == topy[11]))
        {
            matrix[(x + 1) / 2][y] = 2; // ������ �� ǥ��(��� ����)
            True_eye2(matrix, topx, topy);
        }
        else if (x / 2 == topx[12] && (y == topy[12]))
        {
            matrix[(x + 1) / 2][y] = 2; // ������ �� ǥ��(��� ����)
            True_eye3(matrix, topx, topy);
        }
        else if (x / 2 == topx[15] && (y == topy[15]))
        {
            matrix[(x + 1) / 2][y] = 6; // @������ óġ2

        }

        count = 0;
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 25; j++)
            {
                if (matrix[i][j] == 6)
                {
                    count = count + 1;
                }
            }

        }

        gotoxy(2, 2);
        display_map3(matrix, topx, topy, stagex, stagey); //������ �ٲ۴�

        key = _getch();

        move_arrow_key(key, &x, &y, 38, 24);
        end = clock();

        *pst = (double)(end - start) / CLK_TCK;
        gotoxy(1, 26);

        printf("����ð�:%.1f��", *pst);

        if (*pst > TIME_LIMIT_S3)
        {
            gotoxy(1, 30);
            printf("@�����簡 ���������ϴ�. �Ŀ� �� ���������� ���ƿ� �� �ֽ��ϴ�.\n");
            Sleep(1000);
            *pst = 0;
            stage3();
        }
    } while (count < 2);

    gotoxy(1, 30);
    printf("@�����縦 ���񷶽��ϴ�!! �ձ����� ���� ��ȭ�� �������..?\n");
    Sleep(2000);
    storyEND();


}


