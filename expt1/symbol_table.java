package experiment_codes.expt1;

import java.util.*;

class symbol_table {
    static List<List<String>> tokenTable = new ArrayList<List<String>>();
    public static void createTable(String s){
        String type ="";
        //Loop to add all the symbols present in String s
        for(int i=0; i<s.length(); i++)
        {
            List<String> exp = new ArrayList<String>();
            //storing the i'th symbol in val
            char val = s.charAt(i);
            //System.out.println("Adding -> "+ val);
            //Using the ascii value to identify the type
            if((int) val >=42 && (int) val <=47){
                type="operator";
            }
            else{
                type="identifier";
            }

            int alreadyFlag = 0;
            //Checking if the table already has the symbol that is stored in val
            if(!tokenTable.isEmpty()) {
                for (List<String> strings : tokenTable) {
                    if (strings.get(0).equals(String.valueOf(val)) && type!="operator") {
                        System.out.println("Symbol '" + val + "' is present in the table");
                        alreadyFlag = 1;
                    }
                }
            }
            //If the symbol is already present, we'll go to the next symbol present in s
            if(alreadyFlag==1)
                continue;

            exp.add(String.valueOf(val));
            exp.add(String.valueOf((int) val *8));
            exp.add(type);
            
            tokenTable.add(exp);
        }
//         System.out.print(tokenTable);
    }
    
    public static void searchTable(String c){
        for(int i=0; i<tokenTable.size(); i++)
        {
            if(tokenTable.get(i).get(0).equals(c)) {
                System.out.println(tokenTable.get(i));
                return;
            }
        }
        System.out.println("Symbol '"+c+"' is not present in the table");
    }

    public static void addSymbol(String c){
        for(int i=0; i<tokenTable.size(); i++)
        {
            if(tokenTable.get(i).get(0).equals(c)) {
                System.out.println("The symbol'"+c+"' is already present in the table");
                return;
            }
        }

        createTable(String.valueOf(c));
//        System.out.println("Symbol '"+c+"' has been added in the table");
    }

    public static void removeSymbol(String c){
        for(int i=0; i<tokenTable.size(); i++)
        {
            if(tokenTable.get(i).get(0).equals(c)) {
                tokenTable.remove(i);
                System.out.println("The symbol'"+c+"' has been removed");
                return;
            }
        }
        System.out.println("Symbol '"+c+"' is not present in the table");
    }
    
    public static void viewTable(){
        System.out.println("|\tSymbol\t|\tAddress\t|\tType\t|");
        System.out.println();
        for(int i=0;i<tokenTable.size();i++)
        {
            for(int j=0; j<3; j++)
            {
                System.out.print("\t");
                System.out.print(tokenTable.get(i).get(j));
                System.out.print("\t");
            }
            System.out.println();
        }
    }
     
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int exitFlag = 0;
        while(exitFlag!=1){
            System.out.println("\n1. Create table 2. Search table 3. Enter symbol 4. Remove symbol 5. View table 6. Exit\n");
            System.out.println("Enter your option: ");
            int inp;
            inp = sc.nextInt();
            switch(inp){
                case 1:
                    System.out.println("Enter expression: ");
                    String s = sc.next();
                    createTable(s);
                    break;

                case 2:
                    System.out.println("Enter the symbol you want to search: ");
                    String c = sc.next();
                    searchTable(c);
                    break;

                case 3:
                    System.out.println("Enter the symbol you want to add: ");
                    String a = sc.next();
                    addSymbol(a);
                    break;

                case 4:
                    System.out.println("Enter the symbol you want to remove: ");
                    String r = sc.next();
                    removeSymbol(r);
                    break;

                case 5:
                    viewTable();
                    break;

                case 6:
                    exitFlag=1;
                    break;
                default:
                    System.out.println("Incorrect option");
            }
        }
    }
}