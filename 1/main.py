num=int(input("1. Create table 2. Search table 3. Enter symbol 4. Remove symbol 5.View table 6. Exit: "))
identifier=["+", "=", "-", "*", "/"]
table=[]

if num==1:
    exp=input("Enter expression: ")
    for element in exp:
        table.append(element)
    num=int(input("1. Create table 2. Search table 3. Enter symbol 4. Remove symbol 5.View table 6. Exit: "))
if num==2:
    search=input("search table: ")
    if search in table:
        if search in identifier:
            print("Symbol: "+search+ " | address: "+ str(id(search))+ " | type: identifier")
        else:
            print("Symbol: "+search+ " | address: "+str(id(search))+ " | type: operator")
    num=int(input("1. Create table 2. Search table 3. Enter symbol 4. Remove symbol 5.View table 6. Exit: "))
if num==3:
    inexp=input("Enter symbol: ")
    table.append(inexp)
    num=int(input("1. Create table 2. Search table 3. Enter symbol 4. Remove symbol 5.View table 6. Exit: "))
if num==4:
    outexp=input("Enter symbol: ")
    table.remove(outexp)
    num=int(input("1. Create table 2. Search table 3. Enter symbol 4. Remove symbol 5.View table 6. Exit: "))
if num==5:
    for i in table:
        if i in identifier:
            print("Symbol: "+i+ " | address: "+ str(id(i))+ " | type: identifier")
        else:
            print("Symbol: "+i+ " | address: "+str(id(i))+ " | type: operator") 
    num=int(input("1. Create table 2. Search table 3. Enter symbol 4. Remove symbol 5.View table 6. Exit: "))
if num==6:
    print("EXIT")