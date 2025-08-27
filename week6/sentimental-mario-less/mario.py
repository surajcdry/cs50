from cs50 import get_int

height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")

for i in range(height):
    count = 0
    blank = height - 1
    while blank > i:
        blank -= 1
        print(" ", end="")
    while count <= i:
        count += 1
        print("#", end="")
    print("")
