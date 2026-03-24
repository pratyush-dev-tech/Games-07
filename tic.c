#include <stdio.h>
int main() 
 {
    char a='1', b='2', c='3',
         d='4', e='5', f='6',
         g='7', h='8', i='9';
    
    
         int choice;
         char player = 'X';       
     for(int turn = 0; turn < 9; turn++)
     {

        printf("\n");
        printf("%c | %c | %c\n", a,b,c);
        printf("---------\n");
        printf("%c | %c | %c\n", d,e,f);
        printf("---------\n");
        printf("%c | %c | %c\n", g,h,i);

        printf("\nPlayer %c, enter position: ", player);
        scanf("%d", &choice);

        if(choice==1 && a=='1') a=player;
        else if(choice==2 && b=='2') b=player;
        else if(choice==3 && c=='3') c=player;
        else if(choice==4 && d=='4') d=player;
        else if(choice==5 && e=='5') e=player;
        else if(choice==6 && f=='6') f=player;
        else if(choice==7 && g=='7') g=player;
        else if(choice==8 && h=='8') h=player;
        else if(choice==9 && i=='9') i=player;
        else 
        {

            printf("Invalid move! Try again.\n");
            turn--;
            continue;
        }

        if((a==player && b==player && c==player) ||
           (d==player && e==player && f==player) ||
           (g==player && h==player && i==player) ||
           (a==player && d==player && g==player) ||
           (b==player && e==player && h==player) ||
           (c==player && f==player && i==player) ||
           (a==player && e==player && i==player) ||
           (c==player && e==player && g==player)) 
           {

            printf("\nPlayer %c wins! \n", player);
            return 0;
           }

        if(player=='X') player='O';
        else player='X';
    }

    printf("\nGame Draw!\n");
    return 0;
}