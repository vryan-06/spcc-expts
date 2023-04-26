import re
operatorTable = {
    "+": "ADD",
    "-": "SUB",
    "*": "MUL",
    "/": "DIV",
}

registerTable = {}


def getRegisterByIndex(index):
    for [key, value] in enumerate(registerTable):
        if value == 'R' + index:
            return key

    return -1


def getRegisterByOperand(operand):
    if operand not in registerTable.keys():
        registerTable[operand] = "R" + str(len(registerTable))

    return registerTable[operand]


def parseLine(line):
    line = line.strip().replace(" ", "")
    print(line)

    # Check for equals
    if '=' not in line:
        return

    expression = line.split("=")

    operands = re.split(r'[-+*/()]', expression[1])
    operators = re.findall(r'[-+*/()]', expression[1])

    # print(operands)
    # print(operators)

    setVarCode = ""
    operationCode = ""

    for op in operators:
        if op not in operatorTable:
            raise "Invalid Operator " + op

        operationCode += operatorTable[op] + " "

        # Get Operand 1 and its register
        operand1 = operands.pop(0)

        # Allocate Register to operand
        if operand1 not in registerTable.keys():
            setVarCode += f"MOV {operand1},"

        register1 = getRegisterByOperand(operand1)

        if len(setVarCode) > 1:
            setVarCode += register1

        # Get Operand 2 and its register
        operand2 = operands.pop(0)

        if operand2 in registerTable.keys():
            operand2 = getRegisterByOperand(operand2)

        operationCode += f"{operand2},{register1}"

    if len(setVarCode) > 0:
        print(setVarCode)
    if len(operationCode) > 0:
        print(operationCode)
    print(f"{expression[0]} : {getRegisterByOperand(expression[0])}")
    print()


code = open("code.txt").readlines()

for line in code[:]:
    parseLine(line)
