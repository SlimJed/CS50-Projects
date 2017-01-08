import sys
def main():
    #Sets change to float
    change = 0.0;
    print("O hai! ");
    
    while (change < 0):
        print ("How much change is owed?\n");
        #Ask user to input change amount
        change = input("Input change amount: ")
        
    cents = round(change * 100);
    coins = 0;
        
    while(cents > 0):
        if (cents >= 25):
            cents -= 25
            coins = coins + 1
        elif(cents >= 10):
            cents -= 10
            coins = coins + 1
        elif(cents >= 5):
            cents -= 5;
            coins = coins + 1
        else:
            cents = cents - 1
            coins = coins - 1
    
    print(coins)
    print("\n")

    
        