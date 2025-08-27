from cs50 import get_string


text = get_string("Text: ")

W = 0
L = 0
S = 0
a = len(text)
for i in range(a):
    if text[i] == " ":
        W += 1
W = W + 1

for i in range(a):
    if text[i].isalpha() == True:
        L += 1

for i in range(a):
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        S += 1

index = round(0.0588 * (L / W * 100.0) - 0.296 * (S / W * 100.0) - 15.8)
if index < 1:
    print("Before Grade 1\n")
elif index > 16:
    print("Grade 16+\n")
else:
    print(f"Grade {index}")
