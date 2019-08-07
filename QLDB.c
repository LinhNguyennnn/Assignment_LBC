#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct DoiBong
{
    char MaDoi[10];
    char TenDoi[50];
    char TenHLV[50];
    int Thang;
    int Thua;
    int Hoa;
};

struct LichThiDau
{
    char MaTran[20];
    char SanThiDau[20];
    char TenDoi1[50];
    char TenDoi2[50];
    char MaDoi1[50];
    char MaDoi2[50];
    int dd, mm, yyyy;
    int gg, pp;
};

struct KetQua
{
    char Tran[20];
    int KetQua1;
    int KetQua2;
};

int CountDB;
int CountLTD;
int CountKQ;

void MainMenu();

void QuanLyDanhSachDoiBong();
void HienThiDoiBong();
void CapNhatDoiBong();
void ThemDoiBong();

void QuanLyLichThiDau();
void HienThiLichThiDau();
void ThemLichThiDau();

void KetQuathiDau();

void ThongKe();

struct LichThiDau *ThemLich;
struct DoiBong *ThemDoi;
struct KetQua *KQ;

int i;

int main(int argc, char const *argv[])
{
    ThemDoi = (struct DoiBong *)malloc(CountDB * sizeof(struct DoiBong));
    ThemLich = (struct LichThiDau *)malloc(CountLTD * sizeof(struct LichThiDau));
    KQ = (struct KetQua *)malloc(CountKQ * sizeof(struct KetQua));
    MainMenu();

    return 0;
}

void MainMenu()
{
    char select;
    while (true)
    {
        system("cls");
        printf("--- CHÀO MỪNG ĐẾN VỚI V-LEAGUE 2018 ---\n");
        printf("=======================================\n");
        printf("1. Quản lý danh sách đội bóng\n");
        printf("2. Quản lý lịch thi đấu\n");
        printf("3. Quản lý kết quả thi đấu\n");
        printf("4. Thống kê\n");
        printf("0. Thoát\n");

        printf("#Chọn: ");
        fflush(stdin);
        scanf("%c", &select);

        switch (select)
        {
        case '1':
            QuanLyDanhSachDoiBong();
            getchar();
            break;
        case '2':
            QuanLyLichThiDau();
            getchar();
            break;

        case '3':
            KetQuathiDau();
            getchar();
            break;
        case '4':
            ThongKe();
            getchar();
            break;
        case '0':
            printf("Exit");
            exit(0);
            break;
        }
    }
}

void QuanLyDanhSachDoiBong()
{
    char select;
    while (true)
    {
        system("cls");
        printf("===== QUẢN LÝ DANH SÁCH ĐỘI BÓNG =====\n");
        printf("1. Xem danh sách đội bóng\n");
        printf("2. Cập nhật thông tin đội bóng\n");
        printf("3. Thêm mới một đội bóng\n");
        printf("0. Trở về Menu chính\n");

        printf("#Chọn: ");
        fflush(stdin);
        scanf("%c", &select);
        switch (select)
        {
        case '1':
            HienThiDoiBong();
            break;
        case '2':
            CapNhatDoiBong();
            break;
        case '3':
            ThemDoiBong();
            break;
        case '0':
            MainMenu();
            break;
        }
    }
}
void HienThiDoiBong()
{
    system("cls");
    if (CountDB == 0)
    {
        printf("Danh sách trống!\n");
        printf("Nhấn Enter để quay lại! ");
        fflush(stdin);
        getchar();
    }
    else
    {
        printf("================================================================\n");
        printf("Danh sách đội bóng\n");
        printf("================================================================\n");
        printf("| %-6s | %-30s     | %-18s    |\n", "Mã đội", "Tên đội", "Huấn luyện viên");
        printf("================================================================\n");
        for (int i = 0; i < CountDB; i++)
        {
            printf("| %-6s | %-30s | %-18s |\n", (ThemDoi + i)->MaDoi, (ThemDoi + i)->TenDoi, (ThemDoi + i)->TenHLV);
        }
        printf("================================================================\n");
        printf("Bấm Enter để quay lại! ");
        fflush(stdin);
        getchar();
    }
}

void CapNhatDoiBong()
{
    int Count = 0;
    char select;
    char MaDoi[20];
    char TenDoi[20];
    char TenHLV[30];
    system("cls");
    if (CountDB == 0)
    {
        printf("Danh sách trống !\n");
        while (true)
        {
            char Question;
            printf("Bạn có muốn thêm mới một đội bóng ? (Y/N): ");
            fflush(stdin);
            scanf("%c", &select);
            switch (select)
            {
            case 'y':
                ThemDoiBong();
                getchar;
                break;
            case 'Y':
                ThemDoiBong();
                getchar;
                break;
            case 'n':
                QuanLyDanhSachDoiBong();
                getchar;
                break;
            case 'N':
                QuanLyDanhSachDoiBong();
                getchar;
                break;
            }
        }
    }
    else
    {
        printf("==== CẬP NHẬT THÔNG TIN ĐỘI BÓNG ====\n");
        printf("- Nhập mã đội: ");
        fflush(stdin);
        scanf("%[^\n]s", &MaDoi);
        for (int i = 0; i <= CountDB; i++)
        {
            if (strcmp(MaDoi, (ThemDoi + i)->MaDoi) == 0)
            {
                Count = 1;
                printf("- Sửa tên đội: ");
                fflush(stdin);
                scanf("%[^\n]s", &TenDoi);
                printf("- Sửa tên HLV: ");
                fflush(stdin);
                scanf("%[^\n]s", &TenHLV);
                while (true)
                {
                    printf("Bạn có muốn cập nhật không? (Y/N): ");
                    fflush(stdin);
                    scanf("%c", &select);
                    if (select == 'y' || select == 'Y')
                    {
                        strcpy((ThemDoi + i)->TenDoi, TenDoi);
                        strcpy((ThemDoi + i)->TenHLV, TenHLV);

                        printf("Cập nhật thành công !\n");
                        break;
                    }
                    if (select == 'n' || select == 'N')
                    {
                        QuanLyDanhSachDoiBong();
                        getchar;
                        break;
                    }
                }
            }
            if (Count == 1)
            {
                break;
            }
        }
        if (Count == 0)
        {
            printf("Mã đội không tồn tại! \n");
            while (true)
            {
                printf("Bạn có muốn nhập lại mã đội không? (Y/N): ");
                fflush(stdin);
                scanf("%c", &select);
                if (select == 'n' || select == 'N')
                {
                    QuanLyDanhSachDoiBong();
                    getchar;
                    break;
                }
                if (select == 'y' || select == 'Y')
                {
                    printf("- Nhập lại mã đội : ");
                    fflush(stdin);
                    scanf("%[^\n]s", &MaDoi);
                    for (int i = 0; i <= CountDB; i++)
                    {
                        if (strcmp(MaDoi, (ThemDoi + i)->MaDoi) == 0)
                        {
                            Count = 1;
                            printf("- Sửa tên đội: ");
                            fflush(stdin);
                            scanf("%[^\n]s", &TenDoi);
                            printf("- Sửa tên HLV: ");
                            fflush(stdin);
                            scanf("%[^\n]s", &TenHLV);
                            while (true)
                            {
                                printf("Bạn có muốn cập nhật không? (Y/N): ");
                                fflush(stdin);
                                scanf("%c", &select);
                                if (select == 'y' || select == 'Y')
                                {
                                    strcpy((ThemDoi + i)->TenDoi, TenDoi);
                                    strcpy((ThemDoi + i)->TenHLV, TenHLV);

                                    printf("Cập nhật thành công !\n");
                                    break;
                                }
                                else if (select == 'n' || select == 'N')
                                {
                                    QuanLyDanhSachDoiBong();
                                    getchar;
                                    break;
                                }
                            }
                        }
                        if (Count == 1)
                        {
                            break;
                        }
                    }
                }
                if (Count == 1)
                {
                    break;
                }
            }
        }
    }
    printf("Bạn muốn tiếp tục ?(Y/N): ");
    fflush(stdin);
    scanf("%c", &select);
    switch (select)
    {
    case 'y':
        CapNhatDoiBong();
        getchar;
        break;
    case 'Y':
        CapNhatDoiBong();
        getchar;
        break;
    case 'n':
        QuanLyDanhSachDoiBong();
        getchar;
        break;
    case 'N':
        QuanLyDanhSachDoiBong();
        getchar;
        break;
    }
}
void ThemDoiBong()
{
    char chon;
    char MaDoi[10];
    int Count = 0;
    system("cls");
    printf("==== THÊM MỘT ĐỘI BÓNG ====\n");
    ThemDoi = realloc(ThemDoi, (CountDB + 1) * sizeof(struct DoiBong));
    printf("- Nhập mã đội : ");
    fflush(stdin);
    scanf("%[^\n]s", &MaDoi);
    for (int k = 0; k <= CountDB; k++)
    {
        if (strcmp(MaDoi, (ThemDoi + k)->MaDoi) != 0)
        {
            strcpy((ThemDoi + i)->MaDoi, MaDoi);
            Count = 1;
        }
        break;
    }
    if (Count == 0)
    {
        printf("Mã trận đã tồn tại!\n");
        while (true)
        {
            printf("Bạn có muốn nhập lại mã trận không? (Y/N): ");
            fflush(stdin);
            scanf("%c", &chon);
            if (chon == 'y' || chon == 'Y')
            {
                printf("- Mã trận: ");
                fflush(stdin);
                scanf("%[^\n]s", &MaDoi);
                for (int k = 0; k <= CountDB; k++)
                {
                    if (strcmp(MaDoi, (ThemDoi + k)->MaDoi) != 0)
                    {
                        strcpy((ThemDoi + i)->MaDoi, MaDoi);
                        Count = 1;
                    }
                    break;
                }
            }
            else if (chon == 'n' || chon == 'N')
            {
                QuanLyDanhSachDoiBong();
                getchar;
                break;
            }
            if (Count == 1)
            {
                break;
            }
        }
    }
    printf("- Nhập tên đội : ");
    fflush(stdin);
    scanf("%[^\n]s", &(ThemDoi + i)->TenDoi);
    printf("- Nhập tên HLV : ");
    fflush(stdin);
    scanf("%[^\n]s", &(ThemDoi + i)->TenHLV);
    (ThemDoi + i)->Thang = 0;
    (ThemDoi + i)->Hoa = 0;
    (ThemDoi + i)->Thua = 0;
    i++;
    CountDB = i;
    while (true)
    {
        printf("Bạn muốn tiếp tục ?(Y/N): ");
        fflush(stdin);
        scanf("%c", &chon);
        switch (chon)
        {
        case 'y':
            ThemDoiBong();
            getchar;
            break;
        case 'Y':
            ThemDoiBong();
            getchar;
            break;
        case 'n':
            QuanLyDanhSachDoiBong();
            getchar;
            break;
        case 'N':
            QuanLyDanhSachDoiBong();
            getchar;
            break;
        }
    }
}
void QuanLyLichThiDau()
{
    char select;
    while (true)
    {
        system("cls");
        printf("=== QUẢN LÝ LỊCH THI ĐẤU ===\n");
        printf("1. Xem lịch thi đấu\n");
        printf("2. Tạo lịch thi đấu\n");
        printf("0. Trở về menu chính\n");

        printf("#Chọn: ");
        fflush(stdin);
        scanf("%c", &select);

        switch (select)
        {
        case '1':
            HienThiLichThiDau();
            break;
        case '2':
            ThemLichThiDau();
            break;
        case '0':
            MainMenu();
            break;
        }
    }
}
void HienThiLichThiDau()
{
    system("cls");
    if (CountLTD == 0)
    {
        printf("Danh sách trống!\n");
        printf("Nhấn Enter để quay lại! ");
        fflush(stdin);
        getchar();
    }
    else
    {
        printf("=====================================================================================================================\n");
        printf("Lịch thi đấu\n");
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-34s | %-23s | %-24s | %-24s |\n", "Mã trận đấu", "Trận", "Ngày thi đấu", "Giờ thi đấu", "Sân thi đấu");
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < CountLTD; i++)
        {
            printf("| %-11s | %-14s vs %14s | %-2d/%-2d/%-13d | %-2dh%-16d | %-20s |\n", (ThemLich + i)->MaTran, (ThemLich + i)->TenDoi1, (ThemLich + i)->TenDoi2, (ThemLich + i)->dd, (ThemLich + i)->mm, (ThemLich + i)->yyyy, (ThemLich + i)->gg, (ThemLich + i)->pp, (ThemLich + i)->SanThiDau);
        }
        printf("---------------------------------------------------------------------------------------------------------------------\n");

        printf("Bấm Enter để quay lại Menu! ");
        fflush(stdin);
        getchar();
    }
}

void ThemLichThiDau()
{
    system("cls");
    char select;
    int i = 0;
    int Count1 = 0;
    int Count2 = 0;
    char MaTran[20];
    int Count = 0;
    int dd, mm, yyyy;
    int gg, pp;
    if (CountDB < 2)
    {
        printf("Danh sách đội bóng không đủ 2 đội để có thể tạo lịch thi đấu!\n");
        printf("Nhấn Enter để quay lại!");
        fflush(stdin);
        getchar();
    }
    else
    {
        printf("=== TẠO LỊCH THI ĐẤU === \n");

        ThemLich = realloc(ThemLich, (CountLTD + 1) * sizeof(struct LichThiDau));

        printf("- Mã trận: ");
        fflush(stdin);
        scanf("%[^\n]s", &MaTran);
        for (int i = 0; i <= CountLTD; i++)
        {
            if (strcmp(MaTran, (ThemLich + i)->MaTran) != 0)
            {
                Count = 1;
            }
            break;
        }
        if (Count == 0)
        {
            printf("Mã trận đã tồn tại!\n");
            while (true)
            {
                printf("Bạn có muốn nhập lại mã trận không? (Y/N): ");
                fflush(stdin);
                scanf("%c", &select);
                if (select == 'y' || select == 'Y')
                {
                    printf("- Mã trận: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &MaTran);
                    for (int k = 0; k <= CountLTD; k++)
                    {
                        if (strcmp(MaTran, (ThemLich + k)->MaTran) != 0)
                        {
                            Count = 1;
                        }
                        break;
                    }
                }
                else if (select == 'n' || select == 'N')
                {
                    QuanLyLichThiDau();
                    getchar;
                    break;
                }
                if (Count == 1)
                {
                    break;
                }
            }
        }
        strcpy((ThemLich + i)->MaTran, MaTran);
        printf("- Ngày thi đấu (MM/DD/YYYYY): ");
        while (true)
        {
            fflush(stdin);
            scanf("%d/%d/%d", &dd, &mm, &yyyy);
            if (yyyy >= 2010 && yyyy <= 2050)
            {
                if (mm >= 1 && mm <= 12)
                {
                    if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                    {
                        Count1 = 1;
                    }
                    else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                    {
                        Count1 = 1;
                    }
                    else if ((dd >= 1 && dd <= 28) && (mm == 2))
                    {
                        Count1 = 1;
                    }
                    else if (dd == 29 && mm == 2 && (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0)))
                    {
                        Count1 = 1;
                    }
                    if (Count1 == 1)
                    {
                        (ThemLich + i)->dd = dd;
                        (ThemLich + i)->mm = mm;
                        (ThemLich + i)->yyyy = yyyy;
                        break;
                    }
                }
                else
                {
                    printf("- Nhập lại ngày thi đấu : ");
                }
            }
            else
            {
                printf("- Nhập lại ngày thi đấu : ");
            }
        }
        printf("- Giờ thi đấu : ");
        while (true)
        {
            fflush(stdin);
            scanf("%dh%d", &gg, &pp);
            if (gg >= 0 && gg <= 23)
            {
                if (pp >= 0 && pp <= 59)
                {
                    (ThemLich + i)->gg = gg;
                    (ThemLich + i)->pp = pp;
                    break;
                }
                else
                {
                    printf("- Nhập lại giờ thi đấu : ");
                }
            }
            else
            {
                printf("- Nhập lại giờ thi đấu : ");
            }
        }
        printf("- Sân thi đấu: ");
        fflush(stdin);
        scanf("%[^\n]s", &(ThemLich + i)->SanThiDau);
        printf("- Nhập mã đội 1: ");
        fflush(stdin);
        scanf("%[^\n]s", &(ThemLich + i)->MaDoi1);
        for (int k = 0; k < CountDB; k++)
        {
            if (strcmp((ThemLich + i)->MaDoi1, (ThemDoi + k)->MaDoi) == 0)
            {
                strcpy((ThemLich + i)->TenDoi1, (ThemDoi + k)->TenDoi);
                Count1 = 1;
                break;
            }
        }
        if (Count1 == 0)
        {
            printf("Mã đội không tồn tại! \n");
            while (true)
            {
                printf("Bạn có muốn nhập lại mã đội 1 không? (Y/N): ");
                fflush(stdin);
                scanf("%c", &select);
                if (select == 'n' || select == 'N')
                {
                    QuanLyLichThiDau();
                    getchar;
                    break;
                }
                if (select == 'y' || select == 'Y')
                {
                    printf("- Nhập lại mã đội 1: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &(ThemLich + i)->MaDoi1);
                    for (int k = 0; k < CountDB; k++)
                    {
                        if (strcmp((ThemLich + i)->MaDoi1, (ThemDoi + k)->MaDoi) == 0)
                        {
                            strcpy((ThemLich + i)->TenDoi1, (ThemDoi + k)->TenDoi);
                            Count1 = 1;
                            break;
                        }
                    }
                    if (Count1 == 1)
                    {
                        break;
                    }
                }
            }
        }
        printf("- Nhập mã đội 2: ");
        fflush(stdin);
        scanf("%[^\n]s", &(ThemLich + i)->MaDoi2);
        for (int k = 0; k <= CountDB; k++)
        {
            if (strcmp((ThemLich + i)->MaDoi2, (ThemDoi + k)->MaDoi) == 0)
            {
                strcpy((ThemLich + i)->TenDoi2, (ThemDoi + k)->TenDoi);
                Count2 = 1;
            }
            if (strcmp((ThemLich + i)->MaDoi2, (ThemLich + i)->MaDoi1) == 0)
            {
                Count2 = 2;
            }
        }
        if (Count2 == 2)
        {
            printf("Mã đội 2 trùng mã đội 1! \n");
            while (true)
            {
                printf("Bạn có muốn nhập lại mã đội 2 không? (Y/N): ");
                fflush(stdin);
                scanf("%c", &select);
                if (select == 'n' || select == 'N')
                {
                    QuanLyLichThiDau();
                    getchar;
                    break;
                }
                if (select == 'y' || select == 'Y')
                {
                    printf("- Nhập lại mã đội 2: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &(ThemLich + i)->MaDoi2);
                    for (int k = 0; k <= CountDB; k++)
                    {
                        if ((strcmp((ThemLich + i)->MaDoi2, (ThemDoi + k)->MaDoi) == 0) && (strcmp((ThemLich + i)->MaDoi2, (ThemLich + i)->MaDoi1) != 0))
                        {
                            strcpy((ThemLich + i)->TenDoi2, (ThemDoi + k)->TenDoi);
                            Count2 = 1;
                            break;
                        }
                    }
                    if (Count2 == 1)
                    {
                        break;
                    }
                }
            }
        }
        if (Count2 == 0)
        {
            printf("Mã đội không tồn tại! \n");
            while (true)
            {
                printf("Bạn có muốn nhập lại mã đội 2 không? (Y/N): ");
                fflush(stdin);
                scanf("%c", &select);
                if (select == 'n' || select == 'N')
                {
                    QuanLyLichThiDau();
                    getchar;
                    break;
                }
                if (select == 'y' || select == 'Y')
                {
                    printf("- Nhập lại mã đội 2: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &(ThemLich + i)->MaDoi2);
                    for (int k = 0; k <= CountDB; k++)
                    {
                        if ((strcmp((ThemLich + i)->MaDoi2, (ThemDoi + k)->MaDoi) == 0) && (strcmp((ThemLich + i)->MaDoi2, (ThemLich + i)->MaDoi1) != 0))
                        {
                            strcpy((ThemLich + i)->TenDoi2, (ThemDoi + k)->TenDoi);
                            Count2 = 1;
                            break;
                        }
                    }
                    if (Count2 == 1)
                    {
                        break;
                    }
                }
            }
        }
        i++;
        CountLTD = i;
        while (true)
        {
            printf("Bạn muốn tiếp tục ?(Y/N): ");
            fflush(stdin);
            scanf("%c", &select);
            switch (select)
            {
            case 'y':
                ThemLichThiDau();
                getchar;
                break;
            case 'Y':
                ThemLichThiDau();
                getchar;
                break;
            case 'n':
                QuanLyLichThiDau();
                getchar;
                break;
            case 'N':
                QuanLyLichThiDau();
                getchar;
                break;
            }
        }
    }
}

void KetQuathiDau()
{
    char select;
    int i = 0;
    int Count = 0;
    system("cls");
    if (CountLTD == 0)
    {
        printf("Chưa có trận đấu nào được hoàn thành!\n");
        printf("Nhấn Enter để quay lại!");
        fflush(stdin);
        getchar();
    }
    else
    {
        printf("====== KẾT QUẢ THI ĐẤU ======\n");
        KQ = realloc(KQ, (CountKQ + 1) * sizeof(struct KetQua));
        printf("- Nhập mã trận : ");
        fflush(stdin);
        scanf("%[^\n]s", &(KQ + i)->Tran);
        for (int k = 0; k < CountLTD; k++)
        {
            if (strcmp((KQ + i)->Tran, (ThemLich + k)->MaTran) == 0)
            {
                Count = 1;
                break;
            }
        }
        if (Count == 0)
        {
            printf("Mã trận không tồn tại! \n");
            char question;
            while (true)
            {
                printf("Bạn có muốn nhập lại mã trận không? (Y/N): ");
                fflush(stdin);
                scanf("%c", &question);
                if (question == 'Y' || question == 'y')
                {
                    printf("- Nhập lại mã trận : ");
                    fflush(stdin);
                    scanf("%[^\n]s", &(KQ + i)->Tran);
                    for (int k = 0; k < CountLTD; k++)
                    {
                        if (strcmp((KQ + i)->Tran, (ThemLich + k)->MaTran) == 0)
                        {
                            Count = 1;
                            break;
                        }
                    }
                    if (Count == 1)
                    {
                        break;
                    }
                }
                else if (question == 'n' || question == 'N')
                {
                    MainMenu();
                    getchar;
                    break;
                }
            }
        }
        if (CountKQ == 0)
        {
            for (int k = 0; k < CountLTD; k++)
            {
                if (strcmp((KQ + i)->Tran, (ThemLich + k)->MaTran) == 0)
                {
                    printf("Ket qua %s: ", (ThemLich + k)->TenDoi1);
                    fflush(stdin);
                    scanf("%d", &(KQ + i)->KetQua1);
                    printf("Ket qua %s: ", (ThemLich + k)->TenDoi2);
                    fflush(stdin);
                    scanf("%d", &(KQ + i)->KetQua2);

                    if ((KQ + i)->KetQua1 == (KQ + i)->KetQua2)
                    {
                        for (int i = 0; i < CountDB; i++)
                        {
                            if (strcmp((ThemLich + k)->TenDoi1, (ThemDoi + i)->TenDoi) == 0)
                            {
                                (ThemDoi + i)->Hoa++;
                            }
                            if (strcmp((ThemLich + k)->TenDoi2, (ThemDoi + i)->TenDoi) == 0)
                            {
                                (ThemDoi + i)->Hoa++;
                            }
                        }
                    }
                    else if ((KQ + i)->KetQua1 > (KQ + i)->KetQua2)
                    {
                        for (int i = 0; i < CountDB; i++)
                        {
                            if (strcmp((ThemLich + k)->TenDoi1, (ThemDoi + i)->TenDoi) == 0)
                            {
                                (ThemDoi + i)->Thang++;
                            }
                            if (strcmp((ThemLich + k)->TenDoi2, (ThemDoi + i)->TenDoi) == 0)
                            {
                                (ThemDoi + i)->Thua++;
                            }
                        }
                    }
                    else if ((KQ + i)->KetQua1 < (KQ + i)->KetQua2)
                    {
                        for (int i = 0; i < CountDB; i++)
                        {
                            if (strcmp((ThemLich + k)->TenDoi1, (ThemDoi + i)->TenDoi) == 0)
                            {
                                (ThemDoi + i)->Thua++;
                            }
                            if (strcmp((ThemLich + k)->TenDoi2, (ThemDoi + i)->TenDoi) == 0)
                            {
                                (ThemDoi + i)->Thang++;
                            }
                        }
                    }
                    i++;
                    CountKQ = i;
                }
            }
        }
        else
        {
            for (int i = 0; i < CountKQ; i++)
            {
                for (int k = 0; k < CountLTD; k++)
                {
                    if (strcmp((KQ + i)->Tran, (KQ + k)->Tran) != 0)
                    {
                        printf("Ket qua %s: ", (ThemLich + k)->TenDoi1);
                        fflush(stdin);
                        scanf("%d", &(KQ + i)->KetQua1);
                        printf("Ket qua %s: ", (ThemLich + k)->TenDoi2);
                        fflush(stdin);
                        scanf("%d", &(KQ + i)->KetQua2);
                        if ((KQ + i)->KetQua1 == (KQ + i)->KetQua2)
                        {
                            for (int i = 0; i < CountDB; i++)
                            {
                                if (strcmp((ThemLich + k)->TenDoi1, (ThemDoi + i)->TenDoi) == 0)
                                {
                                    (ThemDoi + i)->Hoa++;
                                }
                                if (strcmp((ThemLich + k)->TenDoi2, (ThemDoi + i)->TenDoi) == 0)
                                {
                                    (ThemDoi + i)->Hoa++;
                                }
                            }
                        }
                        else if ((KQ + i)->KetQua1 > (KQ + i)->KetQua2)
                        {
                            for (int i = 0; i < CountDB; i++)
                            {
                                if (strcmp((ThemLich + k)->TenDoi1, (ThemDoi + i)->TenDoi) == 0)
                                {
                                    (ThemDoi + i)->Thang++;
                                }
                                if (strcmp((ThemLich + k)->TenDoi2, (ThemDoi + i)->TenDoi) == 0)
                                {
                                    (ThemDoi + i)->Thua++;
                                }
                            }
                        }
                        else if ((KQ + i)->KetQua1 < (KQ + i)->KetQua2)
                        {
                            for (int i = 0; i < CountDB; i++)
                            {
                                if (strcmp((ThemLich + k)->TenDoi1, (ThemDoi + i)->TenDoi) == 0)
                                {
                                    (ThemDoi + i)->Thua++;
                                }
                                if (strcmp((ThemLich + k)->TenDoi2, (ThemDoi + i)->TenDoi) == 0)
                                {
                                    (ThemDoi + i)->Thang++;
                                }
                            }
                        }
                        i++;
                        CountKQ = i;
                    }
                    else
                    {
                        printf("Trận đấu đã có kết quả!\n");
                        while (true)
                        {
                            printf("Bạn có muốn nhập kết quả cho trận đấu khác không ?(Y/N): ");
                            fflush(stdin);
                            scanf("%c", &select);
                            switch (select)
                            {
                            case 'y':
                                KetQuathiDau();
                                getchar;
                                break;
                            case 'Y':
                                KetQuathiDau();
                                getchar;
                                break;
                            case 'n':
                                MainMenu();
                                getchar;
                                break;
                            case 'N':
                                MainMenu();
                                getchar;
                                break;
                            }
                        }
                    }
                }
            }
        }
        while (true)
        {
            printf("Bạn muốn tiếp tục ?(Y/N): ");
            fflush(stdin);
            scanf("%c", &select);
            switch (select)
            {
            case 'y':
                KetQuathiDau();
                getchar;
                break;
            case 'Y':
                KetQuathiDau();
                getchar;
                break;
            case 'n':
                MainMenu();
                getchar;
                break;
            case 'N':
                MainMenu();
                getchar;
                break;
            }
        }
    }
}
void ThongKe()
{
    system("cls");
    if (CountDB == 0)
    {
        printf("Danh sách trống!\n");
        printf("Nhấn Enter để quay lại! ");
        fflush(stdin);
        getchar();
    }
    else
    {
        printf("======================================================================================================\n");
        printf("------------------------------------------------------------------------------------------------------\n");
        printf("Bảng Xếp hạng\n");
        printf("------------------------------------------------------------------------------------------------------\n");
        printf("| %-14s | %-24s | %-14s | %-11s | %-11s | %-11s | %-13s |\n", "Mã đội", "Tên đội", "Số trận", "Thắng", "Hoà", "Thua", "Điểm");
        printf("======================================================================================================\n");
        for (i = 0; i < CountDB; i++)
        {
            printf("------------------------------------------------------------------------------------------------------\n");
            printf("| %-10s | %-20s | %-10d | %-10d | %-10d | %-10d | %-10d |\n", (ThemDoi + i)->MaDoi, (ThemDoi + i)->TenDoi, ((ThemDoi + i)->Thang + (ThemDoi + i)->Hoa + (ThemDoi + i)->Thua), (ThemDoi + i)->Thang, (ThemDoi + i)->Hoa, (ThemDoi + i)->Thua, ((ThemDoi + i)->Thang * 3 + (ThemDoi + i)->Hoa));
        }
        printf("======================================================================================================\n");
        printf(".  .  .\n\n");
        printf("Chúc các đội thi đấu giải V - League 2019 thành công!");
        getchar();
    }
}