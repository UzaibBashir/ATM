#include<stdio.h>
struct customer{
    char name[25];
    int AccNo, pin, cardNo;
};

int frontPage(){
    char enter;
    printf("WELCOME\n   TO\nBANK OF TRUST\n");
    printf("Enter to continue\n");
    scanf("%c", &enter);

    int card;
    printf("Enter your Card no: ");
    scanf("%d", &card);
    return card;
}
int search(int card, struct customer *applicant){
    // int size = sizeof(applicant)/sizeof(applicant[0]);        //array size
    for(int i=0; i<5; i++){
        //if found (print profile)
        if(card==applicant[i].cardNo){
            printf("Account number: %d\nPress [1] to confirm your Identity\notherwise press [0]\n", applicant[i].AccNo);
            int confirm=1;
            scanf("%d", &confirm);
            if(!confirm){
                return 0;
            }
            return i;
        }
    }
    printf("Account Not Found\n");
    return 0;
}
int authenticate(int j, struct customer* applicant){
    for(int i=0; i<3; i++){
        int pin;
        printf("Enter your Password: ");
        scanf("%d", &pin);
        if(pin==applicant[j].pin){
            printf("Access Granted");
            return 1;
        }else{
            printf("INCORRECT PIN\n%d attempts left\nTry Again\n", (2-i));
        }
    }
    printf("Access Denied");
    return 0;
}
void details(){
    printf("MENU");
}

int main(){

    struct customer applicant[5] = {
        {"Sample", 000000, 1234, 111111},
        {"Uzaib", 230363, 1402, 152001},
        {"Raeel", 230332, 1205, 152002},
        {"Adeeb", 230301, 1405, 152003},
        {"Fawad", 230324, 4520, 15204}
    };

    
    int authentic, arrNo;
    do{
        //FrontPage
        int card = frontPage();

        //Search      (use DSA)
        arrNo = search(card, applicant);
    }while(!arrNo);
    authentic = authenticate(arrNo, applicant);

    return 0;
}
