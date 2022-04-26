base = int(input("x? "))  # 3
exponent = int(input("y? "))  # 2

power = 1
# FOR i := 0, i by 1 to exponent; i++
for i in range(exponent):
    # product
    base_A = base
    exponent_B = exponent
    if base_A < 0:
        base_A = -base_A
        exponent_B = -exponent_B
    product = 0
    for j in range(base_A):
        product = product + exponent_B
    power = product

print(f"Result: {power}.")
