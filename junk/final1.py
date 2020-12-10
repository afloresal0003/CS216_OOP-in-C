def readFile(fileName):
    file1=open(fileName,'r')#open file in reading mode
    Lines=file1.readlines() #read all lines
    userNameList=[]#create 3 list user,pass,balance
    passwordList=[]
    balanceList=[]
    for line in Lines:#read each line
        List=line.strip().split() #split by space
        userNameList.append(List[0])#add username to list
        passwordList.append(List[1])#add password to list
        balanceList.append(List[2])#add balance to list
    #retur all three list
    return userNameList,passwordList,balanceList
      
#ask user for password and name
def changeUser(userNameList,passwordList,balanceList):
    while True:#loop till user not entered value
        userName=input("enter user name:")#prompt
        passWord=input("enter password:")
        if userName in userNameList:#if user name in list
            index=userNameList.index(userName)#get index
            if passWord==passwordList[index]:#check password on same index
                return index #return index
            else:
                print("Invalid user name and password \n Enter again.")
              
        else:
            print("Invalid user name and password \n Enter again.")
  
def deposit(balanceList,index):
    #prompt to enter money to deposit
    amount=int(input("Enter amount to deposit:"))
    balance=int(balanceList[index])#get current balance
    newBalance =amount+balance#add to deposit money
    #int() convert str to int
    #str convert int to list
    balanceList[index]=str(newBalance)#update list
    print("deposited successfully")

def withDraw(balanceList,index):
    #get amount to deposit
    amount=int(input("Enter amount to withdraw:"))
    #get current balance
    balance=int (balanceList[index])
    #if withdrawal amount greater than current balance prompt
    if amount>balance:
        print("you do not have enough balance to withdraw.")
    else:#else update balance
        newBalance=balance-amount
        balanceList[index]=str(newBalance)
        print("withdraw successfully.")

def showBalance(userNameList,balanceList,index):
    #show current balance
    print(userNameList[index],"'s current balance is :",int(balanceList[index]))
  
def updateFile(fileName,userNameList,passwordList,balanceList):
    file1 = open(fileName,"w") #open file in writing mode
    #store username password and balance in single list and wtite to file
    str1=userNameList[0]+" "+passwordList[0]+" "+balanceList[0]+"\n"
    file1.writelines(str1)
    str1=userNameList[1]+" "+passwordList[1]+" "+balanceList[1]+"\n"
    file1.writelines(str1)
    str1=userNameList[2]+" "+passwordList[2]+" "+balanceList[2]+"\n"
    file1.writelines(str1)
    file1.close()
  
  

if __name__=="__main__":
    #read file data
    userNameList,passwordList,balanceList=readFile("UserInformtion.txt")
    #get index of user name and password entered by user
    index=changeUser(userNameList, passwordList, balanceList)
    while True:#infinite loop
        #print menu
        print("D- Deposit money.")
        print("W- WithDraw money .")
        print("B- show current balance .")
        print("C- Change user .")
        print("E- Exit.")
        #get choice
        userInput=input("Enter choice :")
        if(userInput[0]=='D'):
            deposit(balanceList,index)
            #update file
            updateFile("UserInformtion.txt", userNameList, passwordList, balanceList)
        elif(userInput[0]=='W'):
            #with draw
            withDraw(balanceList,index)
            updateFile("UserInformtion.txt", userNameList, passwordList, balanceList)
        elif(userInput[0]=='B'):
            showBalance(userNameList,balanceList,index)
            #show balance
        elif(userInput[0]=='C'):
            #change user
            index=changeUser(userNameList, passwordList, balanceList)
        elif(userInput[0]=='E'):
            print("Good bye ! ")
            break
        else:
            print("Invalid Choice !")