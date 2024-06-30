#include <stdio.h>
#include <windows.h>
#include<string.h>

//Global variables and arrays to show all the orders and prices
int token = 0,tokens[100];
int totalcnt = 0;
char total_order[100][50];
char total_size[100][50];
char total_color[100][50];
int total_qty[100];
int total_cost[100];
int mens_stock[10]={100,100,100,100,100,100,100,100,100,100};//Stock of products
int womens_stock[10]={100,100,100,100,100,100,100,100,100,100};
int shoes_stock[10]={100,100,100,100,100,100,100,100,100,100};

//Function prototypes
int main_page();
void show_menu(int costs[],char items[][16],char colors[][16],char size[][16],int stock[]);
void order(int costs[],char items[][16],char colors[][16],char size[][16],int stock[] );
void cart();
void Bill_Payment();

void main()
 {
    int k;
    //Arrays for men's menu 
    int mens_costs[10]={800,1400,700,450,1250,800,1000,700,500,750};
    char mens_items[10][16]={"Shirts (casual)","Shirts (formal)","Polo-shirts","T-shirts","Hoodie","Jeans","Formal Pants","Joggers","Shorts","Cargo"};
    char mens_colors[10][16]={"Maroon","Blue","Navy","Olive","Beige","Grey","Sky","Black","White","Brown"};
    char mens_size[4][16]={"M","L","XL","XXL"};
    //Arrays for women's menu
    int womens_costs[10]={2000,1200,1500,2500,2000,1500,1000,500,1200,1400};
    char womens_items[10][16]={"Salwar Kameez","Kurta(long)","Floral Shirt","Cotton Poncho","Cardigan","Jeans","Skirts(long)","Palazzo","Cullote","Legging"};
    char womens_colors[10][16]={"Ruby","Blue","Maroon","Olive","Purple","Pink","White","Black","Yellow","tangerine"};
    char womens_size[4][16]={"36","38","40","42"};
    //Arrays for shoe menu
    char shoe_items[10][16]={"Oxford","Loafer","Sneaker","Trainer","Sandals","Flat Sandal","Ballerina","Pumps","Lace-Up Sneaker","Kitten Heel"};
    char shoe_colors[10][16]={"Maroon","Blue","Navy","Olive","Beige","Grey","Sky","Black","White","Brown"};
    char shoe_size[4][16]={"8","9","10","11"};
    int shoe_costs[10]={3000,1800,3500,3700,400,1200,2300,3000,2000,2200};

    k = main_page();//Takes the value n from the main page
    if(k==1)
    {
        show_menu(mens_costs,mens_items,mens_colors,mens_size,mens_stock);
    }
    else if(k==2)
    {
        show_menu(womens_costs,womens_items,womens_colors,womens_size,womens_stock);
    }
    else if(k==3){
        show_menu(shoe_costs,shoe_items,shoe_colors,shoe_size,shoes_stock);
    }
    else if(k==4){
        cart();
    }
    else if(k==5){
        Bill_Payment();
    }
    else{
        printf("\n\n\n\t\t\tThank you for using STYLESCRIPT! Have a great day\t\t\t\n\n\n");
        exit(0);//Ends the program
    }
 }

int main_page()
{
    int i;
    system("cls");
    printf("\n\n\n\n\n\t\t       @@_@_\n\t\t         `'*'  Welcome to STYLESCRIPT \n\t\t\t\t\t\t      '*'`-@@_@\n\n");
    printf("\n\n\n\n\t\t\t what item are you looking for? (^_^)\n\n                       ");
    for (i=0;i<42;i++)
     {
        printf("~");
     }
    printf("\n");
    printf("        trendy         $                                       $\n");
    printf("                       $         Select any -                  $\n");
    printf("        and            $                                       $\n");
    printf("                       $         1. Men's Clothes              $\n");
    printf("        fashionable    $                                       $\n");
    printf("                       $         2. Women's Clothes            $\n");
    printf("        items right    $                                       $\n");
    printf("                       $         3. Shoes.                     $\n");
    printf("        at your doors  $                                       $\n");
    printf("                       $         4. Show your cart.            $\n");
    printf("                       $                                       $\n");
    printf("                       $         5. Go to payment.             $\n");
    printf("                       $                                       $\n");
    printf("        ORDER NOW !!   ");

    for (i=0;i<42;i++)
     {
        printf("~");
     }
    printf("\n\n\n\n                         (Press any other key to exit) ");
    printf("\n\n\n\n                         Enter Your Choice: ");
    int n;
    scanf("%d",&n);
    return n;//returns a value to main
}

void show_menu(int costs[],char items[][16],char colors[][16],char size[][16],int stock[])
{
    int decision;//Decision variable
    system("cls");
    printf("\n\t\t\t\t\t\tPRODUCT LIST\n\t\t\t\t\t\t------------\n");
    printf("\t         Product\t________________________________\t  Prices\t\tAvailability\n");
    for(int i=0;i<10;i++)
    {
        printf("\t%d. %-16s\t________________________________\t %d\t____%d\n",i+1,items[i],costs[i],stock[i]);//Shows the product list from each 3 categories
    }
    printf("\n\n\tOrder your item: (Enter 0 to finish order)\n");

    order(costs,items,colors,size,stock);
    //Calls the order function from all 3 categories
    do{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\tThanks for your order. \n\n\t\t\t  <Enter 1 to order again>\n\n\t\t\t  <Enter 2 to checkout>\n\n\t\t\tEnter your choice: ");

    scanf("%d",&decision);//Decision variable to go to next pages
    printf("\n\n\n\n\n\n\n\n");
    if(decision==1)
    {
        main();//Goes back to the main page if entered 1
        break;
    }
    else if(decision==2){
        
        cart();//Goes to the cart function and shows the cart if orders are given
        break;
    
    }
    else{
        printf("\t\t\tInvalid option. Please enter 2 to check your bill\t\n");//Error handling: Repeatedly shows error until a correct decision input is given
    }
    }while(1);

}

void order(int costs[],char items[][16],char colors[][16],char size[][16],int stock[] ){
    int arID[10],arqty[10],arColor[10],arSize[10],counter=0,previousCounter=0;//array and vars to store the orders
    for(;;)//Infinite loop to run until broken by typing 0
    {
        counter++;//Increments counter by 1 to take orders according to index
        printf("\t Enter Product ID: ");
        scanf("%d",&arID[counter-1]);//Stores the values of the product IDs ordered. Minuses one to show the equivalent index 
        if(arID[counter-1]<=10){
            if(arID[counter-1]==0)
            {
                break;//Stops ordering once pressed 0
            }
            do{printf("\t Enter Quantity:");
            scanf("%d",&arqty[counter-1]);//Enters the quantity in an array

            if(arqty[counter-1]>stock[arID[counter-1]-1]){
                printf("\t Product out of stock\n");//Shows if quantity is more than items in stock
            }
            }while(arqty[counter-1]>stock[arID[counter-1]-1]);//Error handling. Runs the loop until the quantity is correct

            stock[arID[counter-1]-1]-=arqty[counter-1];//Removes orders from stock

            for(int i=0;i<arqty[counter-1];i++){//Runs the loop as many quantities ordered
                printf("\n\t Available Colors: \n\n");
                for(int i=0;i<10;i++){
                    printf("\t%d.%s \n",i+1,colors[i]);
                }
                printf("\n\t Available Sizes:\n\n");
                for(int i=0;i<4;i++){
                    printf("\t%d.%s \n",i+1,size[i]);
                }
                do{
                printf("\t Enter color: \t");
                scanf("%d",&arColor[counter-1]);//Stores color ID
                    if(arColor[counter-1]<1||arColor[counter-1]>10){
                        printf("\t Invalid color \n");
                    }
                }while(arColor[counter-1]<1||arColor[counter-1]>10);//Error handling. Will repeatedly show errors until correct color code given
                do{
                printf("\t Enter Size: ");
                scanf("%d",&arSize[counter-1]);//Stores size
                if(arSize[counter-1]<1||arSize[counter-1]>4){
                    printf("\t Invalid Size \n");
                }
                }while(arSize[counter-1]<1||arSize[counter-1]>4);//Error handling. Same as color

                strcpy(total_order[totalcnt], items[arID[counter-1]-1]);//Copies the order,color and size strings from local arrays to the global total order arrays.
                strcpy(total_color[totalcnt],colors[arColor[counter-1]-1]);
                strcpy(total_size[totalcnt],size[arSize[counter-1]-1]);
                total_cost[totalcnt] = costs[arID[counter-1]-1];//Adds the costs of the products from local array to global array
                total_qty[totalcnt] = 1;//Keeps the total quantities one across all loop runs.
                totalcnt++;//Increases total count with each order given. Storing more orders in the global arrays.
            }
        }
        else{
            counter=previousCounter;//Error handling. Reverts counter to the old count in case of an error.
            printf("\t Invalid Product ID\n");
        }
        previousCounter=counter;//Previous counter set to the value of counter from the beginning of each loop
        
    }
    counter--;
}

void cart(){

    int decision,confirmation;//Variables to input decision
    system("cls");

    int i,sum=0;//Sum is set to 0 initially
    if(totalcnt<=0){
        system("cls");
        printf("\n\n\n\t\t\tYour cart is empty.\n\n\t\t\tEnter (1) to order \n\n");//Message shown if cart is empty or no items are ordered
        do{
        printf("\t\t\tEnter your choice:");
        scanf("%d",&decision);
        if(decision==1){
            main();
            break;
        }
        else{
            printf("\n\t\t\tInvalid Option\n");
        }
        }while(1);
    }
    else{
        system("cls");
        printf("\n\nYour Cart:\n\n\n\t\tItem(s)\t\t     Color\t\t     Size\t\t     Quantity\t\t    Cost\n\n\n\n");

    for(i=0;i<totalcnt;i++)//Shows all the given orders from the global order arrays and variables
    {
        printf("\t%2d. %-16s\t________%-16s________%-16s________%-5d________\t %7d\n",i+1,total_order[i],total_color[i],total_size[i],total_qty[i],total_qty[i]*total_cost[i]);
        sum += total_qty[i]*total_cost[i];
    }

    printf("\n\n\n\n\t\t\t\t\t\t\t  Total = %d\n\n\n\n",sum);
    
    do{
        printf("\n\n\t\t\tEnter (1) to confirm your order.\n\n\t\t\tEnter (2) to clear your cart\n\n\t\t\tEnter (3) to order again\n\n\t\t\tEnter your choice:");//Asks for confirmation for the order. Select any option that applies
        scanf("%d",&confirmation);
        if(confirmation==1){
            token ++;//A token number is generated;
            tokens[token]=sum;//The price of the order is stored in an array associated with the token number
            do{
            system("cls");
            printf("\n\n\tYour token number is %d. Use this token while paying the bill.\n\n\n\n\n\t\t\t<enter (1) to pay the bill>\n\n\t\t\t<Enter (2) to order again\n\n\t\t\t>Enter your choice: ",token);
            scanf("%d",&decision);//Takes the decision input
            printf("\n\n\n");
            if(decision==1)
            {
                Bill_Payment();
                break;
            }
            if(decision==2){
                token--;//Decrements the token to keep the token number same if ordering again
                main();
                break;
            }
            else{
                printf("\n\n\t\t\tInvalid option\n");
            }
            }while(1);//Error handling: Repeatedly shows an error until the correct decision is made
        }
        else if(confirmation==2){
            totalcnt=0;
            do{
            printf("\n\n\t\t\tYour cart has been cleared\n\n\t\t\tEnter (1) to order again\n\n\t\t\tEnter (2) to pay a bill\n\n\t\t\tEnter your choice:");
            scanf("%d",&decision);
            if(decision==1){
                main();
                break;
            }
            else if(decision==2){
                Bill_Payment();
                break;
            }
            else{
                printf("\n\n\t\t\tInvalid Option\n");
            }
            }while(1);
        }
        else if(confirmation==3){
            main();
            break;
        }
        else{
            printf("\n\n\t\t\tInvalid option\n");//Error handling:Shows the same error message until correct option is given
        }
    }while(1);
    }
}

void Bill_Payment()
{
    int k,i,cash,changer,n,sum=0;
    redo://label for a goto statement
    system("cls");
    do{
        printf("\n\n\n\t\t\tPay your bill or press 0 to return to the main menu");
        printf("\n\n\n\t\t\tEnter your token number: ");
        scanf("%d",&k);//Takes input of the token number. If pressed 0, returns to the main menu
    if(k==0){
        main();
    }
    else if(tokens[k]==0){
        printf("\t\t\tNo bills under this token\n");//If no bill is found in the array index corresponding to the token number, an error is shown
    }
    else{
        printf("\t\t\tYour Total Bill is = %d",tokens[k]);//Shows the bill if a bill is found
    work://Label for a goto statement
            printf("\n\t\t\tPay your bill: ");
            scanf("%d",&cash);//Takes input of the bill
            changer = cash-tokens[k];
            break;
    }
    }while(1);//Error handling:Repeatedly shows an error if no bill is found under a token. Breaks if it does

    if(changer == 0)
    {
        printf("\n\t\tThanks for your payment. Have a great day!\n");
        tokens[k]=0;
    }
    else if (changer<0)
    {
        //system("clear");
        printf("\n\t\t\tAmount is not sufficient. :(\n\t\tPlease pay the fair price of your bill\n");
        goto work;//If condition is not met, repeats the statements under the work label
    }
    else
    {
        printf("\n\n\n\t\tHere is your change : (%d - %d) = %d Tk.\n\t\t  ",cash,tokens[k],changer);//Generates change

            for(i=0;i<19;i++)
            {
                printf("_");
            }
            if(changer>=1000 )
                {printf("\n\t\t1000 Tk. note(s) = %d\n",changer/1000);
                changer=changer%1000;}
            if(changer>=500 && changer<1000)
            {printf("\n\t\t 500 Tk. note(s) = %d\n",changer/500);
            changer=changer%500;}
            if(changer>=100 && changer<500)
            {printf("\n\t\t 100 Tk. note(s) = %d\n",changer/100);
            changer= changer%100;}
            if(changer>=50 && changer<100)
            {printf("\n\t\t  50 Tk. note(s) = %d\n",changer/50);
            changer=changer%50;}
             if(changer>=10 && changer<50)
            {printf("\n\t\t  10 Tk. note(s) = %d\n",changer/10);
            changer=changer%10;}
            if(changer>=5 && changer<10)
            {printf("\n\t\t   5 Tk. note(s) = %d\n",changer/5);
            changer=changer%5;}
            if(changer>=2 && changer<5)
            {printf("\n\t\t   2 Tk. note(s) = %d\n",changer/2);
            changer=changer%2;}
            if(changer>=1 && changer<2)
            {printf("\n\t\t   1 Tk. note(s) = %d\n",changer/1);
            changer=changer%1;}

            printf("\t\t  ");
            for(i=0;i<19;i++)
            {
                printf("_");
            }
            tokens[k]=0;
    }
    do{
    printf("\n\n\t\t\t\t\t====================YOUR RECEIPT====================\t\t\t\t\t\n\n");//Shows a receipt of all the orders and bill paid
    printf("\n\nYour Bill:\n\n\n\t\tItem(s)\t\t     Color\t\t     Size\t\t     Quantity\t\t    Cost\n\n\n\n");

    for(i=0;i<totalcnt;i++)
    {
        printf("\t%2d. %-16s\t________%-16s________%-16s________%-5d________\t %7d\n",i+1,total_order[i],total_color[i],total_size[i],total_qty[i],total_qty[i]*total_cost[i]);
        sum += total_qty[i]*total_cost[i];
    }

    printf("\n\n\n\n\t\t\t\t\t\t\t  Total = %d\n\n\n\n",sum);
    printf("\n\n\n\n\n\t\t\tThanks for your payment.\n\t\t\t    Have a great day!\n");
    totalcnt=0;

        printf("\n\n\t\t\t<Enter (1) to order again.>\n\t\t\t<Enter (2) to pay another bill>\n\n\n\t\t\tEnter your choice: \t");
        scanf("%d",&n);
        if(n==1)
        {
            main();
            break;
        }
        else if(n==2)
        {
           goto redo;//If condition is met, reruns the statement inside the redo label
           break;
        }
        else{
            printf("\t\t\tInvalid option\n");//Error handling:Will keep showing the receipt until a correct decision is made
        }
    }while(1);
}