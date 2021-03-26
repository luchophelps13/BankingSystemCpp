#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class User{

    private:
        float balance = 0.00;
        float inp = 0.00;

    public:
        void depositMoney(float inp){
            this->balance += inp;
        }
        void withdrawMoney(float inp){
            this->balance -= inp;
        }

        float retrieveBalance(){
            return this->balance;
        }

        float calcInterest(){
            float newAmount = this->balance + .1 * this->balance;
            this->balance = newAmount;
            return newAmount;
        }
};

int main(){

    char method;
    char username[20], password[20], testuser[20], testpass[20];

    printf("Hello there! This is a demo banking account made with C++! I'll walk you through step by step. Let's create an account!\n");

    printf("Let's create a username: ");
    scanf("%s", username);

    printf("Now let's create a password: ");
    scanf("%s", password);

    printf("\nNow login: \nUsername: ");
    scanf("%s", testuser);

    printf("Password: ");
    scanf("%s", testpass);

    if (strcmp(username, testuser) == 0 && strcmp(password, testpass) == 0){ 
        User usr;
        float input1, input2;

        printf("Now, make a deposit! Enter in the amount in $ you would like: ");
        scanf("%f", &input1);

        usr.depositMoney(input1);

        printf("Here's your balance $%.2f\n", usr.retrieveBalance());

        printf("\nIf you would like to deposit more money or withdraw money, we'll do that later. For now, let's show you our interest plan.\n");
        printf("We offer 10%% annual compound interest. With your balance, let's calculate how much you'd have next year!\n");
        printf("With your current balance of $%.2f, by next year (assuming no deposits or withrawls are made), you would have $%.2f.\n", usr.retrieveBalance(), usr.calcInterest());

        printf("Now that is has been a year, to withdraw money, enter the amount you would like to withdraw! ");
        scanf("%f", &input2);

        usr.withdrawMoney(input2);
        printf("Your new balance is $%.2f", usr.retrieveBalance());

        printf("\nThank you for using my program!\n");

        return 0;
    }

    else{
        printf("Incorrect username and/or password");
        return 0;
    }

    return 0;
}