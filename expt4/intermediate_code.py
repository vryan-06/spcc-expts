print("Intermediate Code Generation:\n\n")

while True:
    print("1. Assignment 2. Arithmetic 3. Relational 4. Exit")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        expr = input("Enter the assignment expression: ")
        parts = expr.split("=")
        a1 = parts[0]
        a2 = parts[1]
        print(f"temp = {a2}")
        print(f"{a1} = temp")

    elif choice == 2:
        expr = input("Enter the arithmetic expression: ")
        parts = expr.split("=")
        var = parts[0]
        rhs = parts[1]
        op = None

        for a_op in ["+", "-", "*", "/", "^", "%"]:
            if a_op in rhs:
                op = a_op
                break

        if op is None:
            print("Invalid arithmetic expression")
            continue

        op_pos = rhs.index(op)
        operand1 = rhs[:op_pos]
        operand2 = rhs[op_pos + 1:]

        print(f"temp = {operand1} {op} {operand2}")
        print(f"{var} = temp")

    elif choice == 3:
        expr = input("Enter the relational expression: ")
        parts = expr.split()
        if len(parts) != 3:
            print("Invalid relational expression")
            continue

        var1 = parts[0]
        var2 = parts[2]
        rel_op = parts[1]
        addr = 100

        print(f"{addr}: if {var1} {rel_op} {var2} goto {addr+3}")
        addr += 1
        print(f"{addr}: t = 0")
        addr += 1
        print(f"{addr}: goto {addr+2}")
        addr += 1
        print(f"{addr}: t = 1")
    elif choice == 4:
        break
    else:
        print("Invalid choice")