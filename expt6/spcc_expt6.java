package experiment_codes.expt6;

import java.io.*;
import java.util.regex.Pattern;

public class spcc_expt6 {

  static String reg[] = new String[100];

  public static int genReg() {
    int i = 0;
    while (reg[i] != null) {
      i++;
    }
    return i;
  }

  public static String getInstr(String c) {
    if (c.equals("+")) {
      return "ADD";
    } else if (c.equals("-")) {
      return "SUB";
    } else {
      return "MUL";
    }
  }

  public static int findReg(String a) {
    int i = 0;
    while (reg[i] != null) {
      if (reg[i].equals(a)) {
        return i;
      } else {
        i++;
      }
    }
    return -1;
  }

  public static void main(String[] args) {
    String filePath = "C:/Users/ryan1/Desktop/FRCRCE/TY/SPCC/expt6input.txt";
    try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
      String line;
      int t = 0;
      int j = 0;
      String code[] = new String[100];
      String op[] = new String[20];
      String arg1[] = new String[20];
      String arg2[] = new String[20];
      String result[] = new String[20];
      while ((line = br.readLine()) != null) {
        Pattern p = Pattern.compile("[\\s]");
        String input[] = p.split(line);
        result[t] = input[0];
        arg1[t] = input[2];

        if (input.length == 5) {
          op[t] = input[3];
          arg2[t] = input[4];
        } else {
          op[t] = input[1];
        }

        t++;
      }

      for (int i = 0; i < 5; i++) {
        int tempreg = 0;
        if (!op[i].equals("=")) {
          int temp1;
          int temp2;
          temp1 = findReg(arg1[i]);
          temp2 = findReg(arg2[i]);

          if (temp1 == -1 && temp2 == -1) {
            tempreg = genReg();
            code[j] = "MOV " + arg1[i] + " R" + tempreg;
            j++;
            reg[tempreg] = result[i];
            code[j] = getInstr(op[i]) + " " + arg2[i] + " R" + tempreg;
            j++;
          } else if (temp1 != -1 && temp2 != -1) {
            code[j] = getInstr(op[i]) + " " + "R" + temp1 + "," + "R" + temp2;
            reg[temp2] = result[i];
            j++;
          } else if (temp1 != -1 && temp2 == -1) {
            tempreg = genReg();
            code[j] = "MOV " + arg2[i] + " R" + tempreg;
            j++;
            code[j] = getInstr(op[i]) + " " + "R" + temp1 + "," + "R" + tempreg;
            reg[tempreg] = result[i];
          } else if (temp2 != -1 && temp1 == -1) {
            tempreg = genReg();
            code[j] = "MOV " + arg1[i] + " R" + tempreg;
            j++;
            code[j] = getInstr(op[i]) + " " + "R" + tempreg + "," + "R" + temp2;
            j++;
            reg[temp2] = result[i];
          }
        } else {
          int temp1 = findReg(arg1[i]);
          if (temp1 != -1) {
            code[j] = "MOV R" + temp1 + "," + result[i];
            j++;
          } else if (temp1 == -1) {
            tempreg = genReg();
            code[j] = "MOV " + arg1[i] + ",R" + tempreg;
            j++;
            code[j] = "MOV R" + tempreg + "," + result[i];
          }
        }
      }
      System.out.println("Three address code to assembly code:");
      for (int i = 0; i < j; i++) {
        System.out.println(code[i]);
      }
    } catch (IOException e) {
      System.err.format("IOException: %s%n", e);
    }
  }
}